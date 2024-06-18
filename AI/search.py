#!/usr/bin/env python3
import socket
import sys
from AI import connect


#(client, map_size) :
def spiral_search(client):
    # Starting position (assuming 0, 0 is the starting point)
    x, y = 0, 0
    # Initial direction (0=up, 1=right, 2=down, 3=left)
    direction = 0

    # Initial movement parameters
    steps = 1
    step_limit = 1
    turn_count = 0

    while True:
        visible_tiles = connect.look(client)
        
        connect.forward(client)
        x, y = move_forward(x, y, direction)

        # Increment steps
        steps += 1

        if steps > step_limit:
            connect.right(client)
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