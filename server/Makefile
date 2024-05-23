##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## -> Makefile
##

SRC_NO_MAIN	=	$(shell find src/ -type f -name "*.c" -not -name "main.c")
SRC 	=	$(SRC_NO_MAIN) src/main.c
OBJ_NO_MAIN	=	$(patsubst src/%,obj/%,$(SRC_NO_MAIN:.c=.o))
OBJ =   $(OBJ_NO_MAIN) obj/main.o

C  =   gcc
DEBUG   =   -ggdb3 -DDEBUG_MODE

RELEASE = -O2
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined
ANALYZER	=

CFLAGS  +=  -Wall -Wextra -pedantic -fsigned-char -I include\
			-fconcepts-diagnostics-depth=4
LDFLAGS	+= -lsfml-graphics -lsfml-window -lsfml-system -ldl
LD_PRELOAD	=

NAME    =   zappy_server

.PHONY: all re
all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

.PHONY: debug redebug
debug: CFLAGS += $(DEBUG)
debug: $(NAME)
redebug: fclean debug

.PHONY: sanitize resanitize
sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: LD_PRELOAD += -lasan -lubsan
sanitize: $(NAME)
resanitize: fclean sanitize

.PHONY: analyzer reanalyzer
analyzer: ANALYZER += on
analyzer: CFLAGS += $(DEBUG) -fanalyzer
analyzer: $(NAME)
reanalyzer: fclean analyzer

.PHONY: display_info
display_info:
	@$(C) --version | head -n 1
	@echo CFLAGS : $(CFLAGS)
	@echo LDFLAGS : $(LD_PRELOAD) $(LDFLAGS)
	@echo -------------

.PHONY: remove_old_analyzer
remove_old_analyzer:
	@if [[ "$(ANALYZER)" != "" ]]; then		\
		rm -f ./analyzer.log;				\
		echo "Removing old analyzer log.";	\
	fi

$(NAME): display_info remove_old_analyzer $(OBJ)
	@$(C) $(OBJ) $(LD_PRELOAD) $(LDFLAGS) -o $(NAME)

obj/%.o: src/%.c
	@echo "$< -> $@"
	@if [[ "$(ANALYZER)" != "" ]]; then						\
		$(C) -c $(CFLAGS) $< -o $@ 2>> ./analyzer.log;	\
	else													\
		$(C) -c $(CFLAGS) $< -o $@;						\
	fi

.PHONY: clean_vgcore
clean_vgcore:
	@echo Removing Core Dumped files.
	@rm -f vgcore.*
	@rm -f valgrind*.log.core.*

.PHONY: clean
clean: clean_vgcore
	@echo Removing temporary and object files.
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@echo Removing binary.
	@rm -f $(NAME)
