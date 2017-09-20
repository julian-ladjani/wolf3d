##
## Makefile for makefile in /home/julian-ladjani/delivery/PSU/my_printf
##
## Made by julian ladjani
## Login   <julian.ladjani@epitech.net>
##
## Started on  Mon Nov  7 16:31:28 2016 julian ladjani
## Last update Mon May 22 16:13:48 2017 Ladjani Julian
##

CC 		=	gcc -O2

SRC		=	src/my_draw_line.c				\
			src/my_put_pixel.c				\
			src/window/windows.c				\
			src/window/windows2.c				\
			src/my_parallel_projection.c			\
			src/parseur/parseur.c				\
			src/parseur/parseur2.c				\
			src/wolf.c					\
			src/wolf_foncs.c				\
			src/calc/calc.c					\
			src/calc/calc2.c				\
 			src/calc/check_bonus.c				\
			src/my_isometric_projection.c			\
			src/my_projection.c				\
			src/raycast.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS		=	-I./include/ -Wall -Wextra -W

LIBDIR		=	./lib/

NAME 		=	wolf3d

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -L$(LIBDIR) -lmy

clean:
			$(RM) $(OBJ)
			$(RM) *~

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
