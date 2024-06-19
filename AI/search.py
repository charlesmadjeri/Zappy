#!/usr/bin/env python3
import socket
import sys
from AI import connect
class Player:
    def __init__(self):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.level = 1
        self.x, self.y = 0, 0
        self.direction = 0

def spiral_search(player):
    # Starting position (assuming 0, 0 is the starting point)
    x, y = 0, 0
    # Initial direction (0=up, 1=right, 2=down, 3=left)
    direction = 0

    # Initial movement parameters
    steps = 1
    step_limit = 1
    turn_count = 0
    items_of_interest = ["food", "linemate"]
    while True:
        visible_tiles = connect.look(player.client)
        loot_tiles(player, items_of_interest)

        # Move forward
        connect.forward(player.client)
        x, y = move_forward(x, y, direction)

        # Increment steps
        steps += 1

        if steps > step_limit:
            connect.right(player.client)
            direction = (direction + 1) % 4  # Update direction

            # Reset step count and update turn count
            steps = 1
            turn_count += 1

            # Every two turns, increase the step limit
            if turn_count == 2:
                step_limit += 1
                turn_count = 0

        player.x, player.y, player.direction = x, y, direction

# Define movement based on direction
def move_forward(x, y, direction):
    if direction == 0:
        return x, y + 1
    elif direction == 1:
        return x + 1, y
    elif direction == 2:
        return x, y - 1
    elif direction == 3:
        return x - 1, y

# Function to return to the starting position (0, 0) using Manhattan distance optimization
def return_to_start(player):
    while player.x > 0 or player.y > 0:
        # Determine the optimal direction to move
        if abs(player.x) >= abs(player.y):
            if player.x > 0:
                target_direction = 3  # Move left
            else:
                target_direction = 1  # Move right
        else:
            if player.y > 0:
                target_direction = 2  # Move down
            else:
                target_direction = 0  # Move up

        # Turn to face the target direction
        while player.direction != target_direction:
            connect.right(player.client)
            player.direction = (player.direction + 1) % 4
        
        # Move forward
        connect.forward(player.client)
        player.x, player.y = move_forward(player.x, player.y, player.direction)

def align_with_target(player, current, target, positive_direction, negative_direction):
        if current < target:
            target_direction = positive_direction
        elif current > target:
            target_direction = negative_direction
        else:
            return

        while player.direction != target_direction:
            connect.right(player.client)
            player.direction = (player.direction + 1) % 4

def move_to_coordinates(player, target_x, target_y):

    # Move along the y-axis first
    align_with_target(player, player.y, target_y, 0, 2)

    while player.y != target_y:
        connect.forward(player.client)
        player.x, player.y = move_forward(player.x, player.y, player.direction)

    # Move along the x-axis
    align_with_target(player, player.x, target_x, 1, 3)

    while player.x != target_x:
        connect.forward(player.client)
        player.x, player.y = move_forward(player.x, player.y, player.direction)

def navigate_to_tile(index, player):
        row = index // (2 * player.level)
        col = (index % (2 * player.level)) - (player.level - 1)

        if col < 0:  # Tile is to the left
            target_direction = 3
        elif col > 0:  # Tile is to the right
            target_direction = 1
        elif row > 0:  # Tile is directly in front
            target_direction = 0
        else:  # Tile is behind
            target_direction = 2

        while player.direction != target_direction:
            connect.right(player.client)
            player.direction = (player.direction + 1) % 4

        for _ in range(abs(col) + abs(row)):
            connect.forward(player.client)
            player.x, player.y = move_forward(player.x, player.y, player.direction)

def loot_tiles(player, items_of_interest):
    start_x, start_y = player.x, player.y
    start_direction = player.direction
    
    visible_tiles = connect.look(player.client)

    interesting_tiles = []

 # Iterate through each tile's contents
    for i, tile_contents in enumerate(visible_tiles):
        # Split the tile_contents string by spaces to get individual elements
        elements = tile_contents.split()

        # Check if any item of interest is in the elements of the current tile
        for item_of_interest in items_of_interest:
            if item_of_interest in elements:
                interesting_tiles.append((i, elements))  # Store index and elements
                break

    for index, elements in interesting_tiles:
        navigate_to_tile(index, player)
        for item_of_interest in items_of_interest:
            if item_of_interest in elements:
                connect.take(player.client, item_of_interest)
                elements.remove(item_of_interest)  # Remove the taken item from elements

    move_to_coordinates(player, start_x, start_y)
    while player.direction != start_direction:
        connect.right(player.client)
        player.direction = (player.direction + 1) % 4