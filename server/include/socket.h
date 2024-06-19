/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** socket
*/

#ifndef SOCKET_H_
    #define SOCKET_H_
    #include <netinet/in.h>
    #include <sys/types.h>
    #include <sys/socket.h>

sockaddr_in_t generate_addr(const int port);

#endif /* !SOCKET_H_ */
