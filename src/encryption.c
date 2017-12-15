/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** encryption functions
*/

# include "my.h"
# include "cipher.h"
 
void encrypt_two_by_two_matrix(param_t *param)
{
	int msg_len = my_strlen(param->msg);
	int i = 0, j = 0, fir = 0, sec = 0;

	for (i = 0, j = 0; i < msg_len; i += 2, j += 2) {
		fir = param->msg[i] * param->key_matrix[0];
		fir += param->msg[j] * param->key_matrix[2];
		sec = param->msg[i] * param->key_matrix[1];
		sec += param->msg[j] * param->key_matrix[3];

		printf("%d %d", fir, sec);

		if (j < msg_len)
			printf(" ");
	}

	if (i < msg_len) {
		fir = param->msg[i] * param->key_matrix[0];
		sec = param->msg[j] * param->key_matrix[1];

		printf(" %d %d", fir, sec);
	}

	printf("\n");
}

void encrypt_three_by_three_matrix(param_t *param)
{
	int msg_len = my_strlen(param->msg);
	int i = 0, j = 0, k = 0, fir = 0, sec = 0, thr = 0;

	for (i = 0, j = 0, k = 0; i < msg_len; i += 3, j += 3, k += 3) {
		fir = param->msg[i] * param->key_matrix[0];
		fir += param->msg[j] * param->key_matrix[3];
		fir += param->msg[k] * param->key_matrix[6];
		sec = param->msg[i] * param->key_matrix[1];
		sec += param->msg[j] * param->key_matrix[4];
		sec += param->msg[k] * param->key_matrix[7];
		thr = param->msg[i] * param->key_matrix[2];
		thr += param->msg[j] * param->key_matrix[5];
		thr += param->msg[k] * param->key_matrix[8];

		printf("%d %d %d", fir, sec, thr);

		if (k < msg_len)
			printf(" ");
	}

	if (i < msg_len || (j > i && j < msg_len)) {
		fir = param->msg[i] * param->key_matrix[0];
		sec = param->msg[i] * param->key_matrix[1];
		thr = param->msg[i] * param->key_matrix[2];

		printf(" %d %d %d", fir, sec, thr);
	}

	printf("\n");
}

void encrypt_four_by_four_matrix(param_t *param)
{
	printf("key = %s\n", param->key);
}

void encryption(param_t *param)
{
	if (param->key_len > 16) {
		my_puterr("Key too long. Aborded.\n");
		exit(84);
	}

	double *key = param->key_matrix;
	printf("Key matrix :\n");

	if (param->key_len <= 4) {
		for (int i = 0; i < 4; i += 2)
			printf("%.2f\t%.2f\n", key[i], key[i + 1]);

		printf("\nEncrypted message :\n");
		encrypt_two_by_two_matrix(param);
	} else if (param->key_len > 4 && param->key_len <= 9) {
		for (int i = 0; i < 9; i += 3)
			printf("%.2f\t%.2f\t%.2f\n", key[i], key[i + 1], key[i + 2]);

		printf("\nEncrypted message :\n");
		encrypt_three_by_three_matrix(param);
	} else if (param->key_len > 9 && param->key_len <= 16) {
		for (int i = 0; i < 16; i += 4)
			printf("%.2f\t%.2f\t%.2f\t%.2f\n", key[i], key[i + 1], key[i + 2], key[i + 3]);
		
		printf("\nEncrypted message :\n");
		encrypt_four_by_four_matrix(param);
	}
}