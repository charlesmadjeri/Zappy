##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## -> Makefile
##

all:
	make -C GUI
	make -C server

clean:
	make clean -C GUI
	make clean -C server
	make clean -C AI

fclean:
	make fclean -C GUI
	make fclean -C server
	make fclean -C AI
	rm -f zappy_GUI
	rm -f zappy_server
	rm -f zappy_AI

re:
	make re -C server
	make re -C GUI
	make re -C AI

Server:
	make -C server

gui:
	make -C GUI

ai:
	make -C AI