/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** encryption functions
*/

# include "cipher.h"

void encryption(param_t *param)
{
	printf("Key matrix :\n");

	if (param->key_len <= 4) {
		double *key = param->key_matrix;
		printf("%.2f\t%.2f\n%.2f\t%.2f\n\n", key[0], key[1], key[2], key[3]);
		printf("Encrypted message :\n");
		//manage_two_by_two_matrix(param);
	} else if (param->key_len > 4 && param->key_len <= 9) {

	} else if (param->key_len > 9 && param->key_len <= 16) {

	}
}