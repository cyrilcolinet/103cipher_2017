##
## EPITECH PROJECT, 2017
## 103cipher
## File description:
## Makefile with build project rule and units tests
##

.PHONY			: all, fclean, clean, re, tests_run, library

NAME 			= 103cipher

SRC 			= src/cipher.c  			\
				  src/main.c 				\
				  src/utils.c 				\
				  src/one_sized_cipher.c 	\
				  src/encryption.c 			\
				  src/decryption.c

CFLAGS 			= -Wall -Wextra -I./include -g3 --coverage

EXTRA_FLAGS 	= -L./lib/ -lmy -g3

CC 				= gcc

RM 				= rm -f

OBJ 			= $(SRC:.c=.o)

all: 			library $(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ) ./lib/my/*.o -o $(NAME)

library:
				make -C ./lib

clean:
				$(RM) $(OBJ)
				$(RM) vgcore.*

fclean: 		clean
				$(RM) $(NAME)
				make fclean -C ./lib

re: 			fclean all

tests_run:		re
				@echo "Running units tests..."

