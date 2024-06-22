##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

SRC = 			src/main.c 			\
				src/main_server.c	\
				src/server.c		\
				src/socket.c		\
				src/error_manager.c	\
				src/args_manager.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	= -I./include

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
