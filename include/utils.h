/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** utils functions (header file)
*/

# include "cipher.h"

# ifndef UTILS_H
# define UTILS_H

void 		check_arguments(int ac, char **av);
param_t 	*init_struct(char **av);
int 		*get_matrix_key(char *key);

# endif