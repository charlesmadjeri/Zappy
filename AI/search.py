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

    # List to track movements (for backtracking)
    movements = []

    while True:
        if step_limit >= 6:
            return_to_start(player)
            step_limit = 0
        visible_tiles = connect.look(player.client)
        
        # Move forward
        connect.forward(player.client)
        x, y = move_forward(x, y, direction)
        movements.append(direction)  # Track the direction moved

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