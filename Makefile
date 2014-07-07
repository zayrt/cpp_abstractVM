##
## Makefile for my_script in /home/szwank_g/systemeUnix/my_script
## 
## Made by szwankowski guillaume
## Login   <szwank_g@epitech.net>
## 
## Started on  Tue Jan 28 17:02:58 2014 szwankowski guillaume
## Last update Sat Feb 22 17:33:16 2014 Guillaume Szwankowski
##

NAME =			abstractVM

CC =				g++

CPPFLAGS =	-W -Wall -Werror -Wextra

SRC =				abstractVM.cpp \
						Exception.cpp \
						Operand.cpp \
						Parser.cpp \
						VMStack.cpp

OBJ =				$(SRC:.cpp=.o)

$(NAME):		$(OBJ)
						$(CC) -o $(NAME) $(OBJ)

all:				$(NAME)

clean:
						rm -f $(OBJ)

fclean:			clean
						rm -f $(NAME)

re:					fclean all

.PHONY:			all clean fclean re
