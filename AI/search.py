#!/usr/bin/env python3
import socket
import sys
from AI import connect

class Player:
    def __init__(self):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.level = 1

def spiral_search(player):
    # Starting position (assuming 0, 0 is the starting point)
    x, y = 0, 0
    # Initial direction (0=up, 1=right, 2=down, 3=left)
    direction = 0

    # Initial movement parameters
    steps = 1
    step_limit = 1
    turn_count = 0

    # Set to store visited tiles
    visited_tiles = set()
    visited_tiles.add((x, y))

    while True:
        # Check the current level to update vision range
        vision_range = player.level
        
        visible_tiles = connect.look(player.client)
        new_tiles = mark_visible_tiles_as_visited(x, y, direction, vision_range, visited_tiles)
        
        # Find the direction that leads to the most new tiles
        best_direction, best_count = find_best_direction(x, y, direction, vision_range, visited_tiles)
        
        # If a better direction is found, turn towards it
        while direction != best_direction:
            connect.right(player.client)
            direction = (direction + 1) % 4
        
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

# Function to mark the visible tiles as visited based on the current vision range
def mark_visible_tiles_as_visited(x, y, direction, vision_range, visited_tiles):
    new_tiles = 0
    for level in range(1, vision_range + 1):
        for offset in range(-level, level + 1):
            if direction == 0:  # Up
                tile_x, tile_y = x + offset, y + level
            elif direction == 1:  # Right
                tile_x, tile_y = x + level, y + offset
            elif direction == 2:  # Down
                tile_x, tile_y = x + offset, y - level
            elif direction == 3:  # Left
                tile_x, tile_y = x - level, y + offset

            if (tile_x, tile_y) not in visited_tiles:
                visited_tiles.add((tile_x, tile_y))
                new_tiles += 1
    return new_tiles

# Function to find the best direction to move towards the most new tiles
def find_best_direction(x, y, direction, vision_range, visited_tiles):
    best_direction = direction
    best_count = 0
    for i in range(4):
        count = count_new_tiles(x, y, (direction + i) % 4, vision_range, visited_tiles)
        if count > best_count:
            best_count = count
            best_direction = (direction + i) % 4
    return best_direction, best_count

# Function to count the number of new tiles in a given direction
def count_new_tiles(x, y, direction, vision_range, visited_tiles):
    count = 0
    for level in range(1, vision_range + 1):
        for offset in range(-level, level + 1):
            if direction == 0:  # Up
                tile_x, tile_y = x + offset, y + level
            elif direction == 1:  # Right
                tile_x, tile_y = x + level, y + offset
            elif direction == 2:  # Down
                tile_x, tile_y = x + offset, y - level
            elif direction == 3:  # Left
                tile_x, tile_y = x - level, y + offset

            if (tile_x, tile_y) not in visited_tiles:
                count += 1
    return count