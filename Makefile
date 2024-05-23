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

fclean:
	make fclean -C GUI
	make fclean -C server
	rm -f zappy_GUI
	rm -f zappy_server
	rm -f zappy_AI

re:
	make re -C server
	make re -C GUI

server:
	make -C server
 
gui:
	make -C GUI