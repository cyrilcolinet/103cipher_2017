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

typedef enum type {
	encrypt, decrypt
} type_e;

typedef struct params {
	double 	*key_matrix;
	int 	key_len;
	type_e 	type;
	char 	*msg;
	char 	*key;
} param_t;

void 		cipher(param_t *param);
int 		cipher_main(int ac, char **av);

void 		encryption(param_t *param);
void 		decryption(param_t *param);

void 		one_sized_encryption(param_t *param);
void 		one_sized_decryption(param_t *param);

# endif