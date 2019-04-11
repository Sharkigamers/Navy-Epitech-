##
## EPITECH PROJECT, 2018
## navy
## File description:
## Makefile
##

SRC	=	src/navy.c		\
		src/fill_map.c		\
		src/print_map.c		\
		src/init_positions.c	\
		src/main.c	\
		src/gest_error.c	\
		src/connection.c	\
		src/wrap.c	\
		src/modif_map.c	\
		src/send_touch.c	\
		src/receive_attack.c	\
		src/chose_attack.c	\
		src/cond_end.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CPPFLAGS	=	-I./include/ -Wall -Wextra -g3 -lm

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ) $(LIB) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make clean

fclean: clean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make fclean

re:	fclean all

.PHONY: all clean fclean re
