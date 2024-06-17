#!/usr/bin/env python3
from AI import connect
import sys
import socket

def main():
    if len(sys.argv) != 5 and len != 7:
        print("Incorrect number of argument")
        sys.exit(84)

    server_port = None
    team_name = None
    machine_name = "127.0.0.1"

    for i in range(len(sys.argv)):
        if sys.argv[i] == "-p" and i + 1 < len(sys.argv):
            server_port = int(sys.argv[i + 1])
        elif sys.argv[i] == "-n" and i + 1 < len(sys.argv):
            team_name = sys.argv[i + 1]
        elif sys.argv[i] == "-h" and i + 1 < len(sys.argv):
            machine_name = sys.argv[i + 1]
    
    if server_port is None or team_name is None:
        print("Missing arguments")
        sys.exit(84)

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    map_size = connect.innit_connection(client, machine_name, server_port, (team_name + '\n'))
    i = 0
    while i >= 0:
        i += 1
    client.close()
    

if __name__ == "__main__":
    main()