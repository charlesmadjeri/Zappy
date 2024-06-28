##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

SRC = 			src/main.c 						\
				src/main_server.c				\
				src/server.c					\
				src/socket.c					\
				src/error_manager.c				\
				src/init.c						\
				src/free.c						\
				src/resources.c					\
				src/map.c						\
				src/client/client.c     		\
				src/client/linked_client.c		\
				src/commands/handle_command.c	\
				src/commands/linked_commands.c	\
				src/player/create_player.c 		\
				src/client/get_command.c		\
				src/args/args_manager.c			\
				src/args/get_teams.c			\

OBJ		=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	= -I./include -g3

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	mv $(NAME) ../$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
