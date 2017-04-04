##
## Makefile for scroller in /home/victor/Rushs/scroller
## 
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
## 
## Started on  Fri Mar 31 21:39:35 2017 Victor LE DANTEC
## Last update Mon Apr  3 14:52:12 2017 Victor LE DANTEC
##

NAME	=	scroller

SRC	=	src/main.c			\
		src/happy_scene.c		\
		src/init_happy_scene.c		\
		src/tracker.c			\
		src/text_happy_scene.c		\
		src/music_happy_scene.c		\
		src/taz_anim.c			\
		src/bug_screen.c		\
		src/bunny.c			\
		src/evil_scene.c		\
		src/bg_evil.c			\
		src/evil_text.c			\
		src/scroller_evil.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CFLAGS	+=	-Wall -Wextra -pedantic $(INCLUDE) $(LIBS)

INCLUDE	=	-I./include

LIBS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
