/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** cipher functions
*/

# include "utils.h"
# include "cipher.h"

int cipher_main(int ac, char **av)
{
	param_t *param;

	check_arguments(ac, av);
	param = init_struct(av);

	free(param);

	return (0);
}