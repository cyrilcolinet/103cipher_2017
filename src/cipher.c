/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** cipher functions
*/

# include "my.h"
# include "utils.h"
# include "cipher.h"

void cipher(param_t *param)
{
	if (param->type == encrypt) {
		if (param->key_len > 1) {
			param->key_matrix = get_matrix_key(param->key);
		} else {
			one_sized_encryption(param);
		}
	} else if (param->type == decrypt) {
		if (param->key_len > 1) {
			param->key_matrix = get_matrix_key(param->key);
		} else {
			one_sized_decryption(param);
		}
	} else {
		my_puterr("Unknown type. Only 'encrypt' and 'decrypt' allowed.\n");
		exit(84);
	}
}

int cipher_main(int ac, char **av)
{
	param_t *param;

	check_arguments(ac, av);
	param = init_struct(av);

	cipher(param);
	free(param);

	return (0);
}