#!/usr/bin/env python3
import socket
import sys

def innit_connection(client, machine_name, server_port, team_name):
    try:
        client.connect((machine_name, server_port))
        print(f"Connected to {machine_name}:{server_port}")

        initial_data = client.recv(10)
        print(f"Received from server: {initial_data.decode()}")

        client.sendall(team_name.encode())

        data = client.recv(60).decode()
        print(f"Received from server: {data}")

    except socket.error as e:
        print(f"Connection error: {e}")
    
    split_data = data.split('\n')
    client_number = int(split_data[0])

    if client_number < 0 :
        client.close()
        print(f"Not enough space in team: {team_name}")
        sys.exit(84)

    map_size = tuple(map(int, split_data[1].split()))

    return map_size