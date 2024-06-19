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
        sys.exit(84)
    
    split_data = data.split('\n')
    client_number = int(split_data[0])

    if client_number < 0 :
        client.close()
        print(f"Not enough space in team: {team_name}\n")
        sys.exit(84)

    map_size = tuple(map(int, split_data[1].split()))

    return map_size

def forward(client):
    client.sendall("Forward\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def left(client):
    client.sendall("Left\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def right(client):
    client.sendall("Right\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def look(client):
    client.sendall("Look\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    array = data.split(", ")
    return array

def inventory(client):
    client.sendall("Inventory\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    array = data.split(", ")
    return array

def send(client, text):
    message = "Broadcast " + text + "\n"
    client.sendall(message.encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def unused_slot(client):
    client.sendall("Connect_nbr\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return int(data)

def add_slot(client):
    client.sendall("Fork\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def eject(client):
    client.sendall("Eject\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def dead(client):
    print("Drone is dead, disconnecting\n")
    client.close()
    sys.exit()

def take(client, object):
    client.sendall(f"Take {object}\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def drop(client, object):
    client.sendall(f"Set {object}\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data

def elevate(client):
    client.sendall("Incantation\n".encode())
    data = client.recv(1024).decode()
    while data == "":
        data = client.recv(1024).decode()
    if data == "dead\n":
        dead(client)
    return data