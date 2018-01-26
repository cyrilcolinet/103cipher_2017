/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** decryption functions
*/

# include "my.h"
# include "cipher.h"

void decrypt_two_by_two(param_t *param, double rev[4])
{
	(void)param, (void)rev;
}

void reverse_two_by_two(param_t *param)
{
	double *mat = param->key_matrix;
	double rev = (mat[0] * mat[3]) - (mat[2] * mat[1]);
	double reverted[4];

	if (rev == 0) {
		my_puterr("Unable to reverse matrix. Abord.\n", false);
		exit(84);
	}

	reverted[0] = mat[3] / rev;
	reverted[1] = (-mat[1]) / rev;
	reverted[2] = (-mat[2]) / rev;
	reverted[3] = mat[0] / rev;

	printf("Key matrix :\n");
	printf("%.3f\t%.3f\n%.3f\t%.3f\n\n", reverted[0], reverted[1], reverted[2], reverted[3]);
	decrypt_two_by_two(param, reverted);
}

void decryption(param_t *param)
{
	if (param->key_len <= 4) 
		reverse_two_by_two(param);
	//else if (param->key_len > 4 && param->key_len <= 9)
	//	reverse_three_by_three(param);
}
