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
	int i;
	double tmp = 0;
	double key = param->key[0];

	printf("Key matrix :\n%.0f\n\n", key);
	printf("Encrypted message :\n");

	for (i = 0; i < msg_len; i++) {
		tmp = param->msg[i] * key;
		printf("%.0f", tmp);

		if (i < msg_len - 1)
			printf(" ");
	}

	printf("\n");
}

void one_sized_decryption(param_t *param)
{
	int msg_len = my_strlen(param->msg);
	int a = 0, m = 0, i = 0;
	double key = param->key[0];

	printf("Key matrix :\n%.0f\n\n", key);
	printf("Decrypted message :\n");

	while (i < msg_len) {
		while (param->msg[i] != ' ' && param->msg[i] != 0) {
			a = a * 10 + (param->msg[i] - 48);
			i++;
		}

		m = a / key;
		printf("%c", m);
		i++;
		a = 0;
	}

	printf("\n");
}
