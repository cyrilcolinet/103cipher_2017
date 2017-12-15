/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** one_sized_cipher functions
*/

# include "my.h"
# include "cipher.h"

void one_sized_encryption(param_t *param)
{
	int msg_len = my_strlen(param->msg);
	double tmp = 0;
	double key = param->key[0];

	printf("Key :\n%.0f\n\n", key);
	printf("Encrypted message :\n");

	for (int i = 0; i < msg_len; i++) {
		tmp = param->msg[i] * key;
		printf("%.0f", tmp);

		if (i < msg_len - 1)
			printf(" ");
	}

	printf("\n");
}