/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** cipher functions (header file)
*/

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef CIPHER_H
# define CIPHER_H

typedef struct params {
	int 	key_len;	
} param_t;

int 		cipher_main(int ac, char **av);

# endif