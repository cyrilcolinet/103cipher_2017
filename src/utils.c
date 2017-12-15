/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** utils functions
*/

# include "my.h"
# include "cipher.h"
# include "utils.h"

void check_arguments(int ac, char **av)
{
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("USAGE:\n\t./103cipher <msg> <key> <flag>\n\n");
		my_putstr("DESCRIPTION:\n");
		my_putstr("\t[-h]\tDisplay the help page (this page)\n");
		my_putstr("\tmsg\tMessage to encrypt/decrypt\n");
		my_putstr("\tkey\tKey used to encrypt/decrypt message (usefull)\n");
		my_putstr("\tflag\tFlag: 1 to decrypt and 0 to encrypt\n");
		exit(0);
	} else if (ac != 4) {
		my_puterr("Usage: ./103cipher <msg> <key> <flag>\n");
		exit(84);
	} else {
		int num = my_atoi(av[3]);

		if (!av[1][0] || !av[2][0]) {
			my_puterr("Message or Key must be not empty.\n");
			exit(84);
		} else if(my_strlen(av[3]) != 1 || (num != 0 && num != 1)) {
			my_puterr("Flag must be equals to 0 or 1.\n");
			exit(84);
		}
	}
}

param_t *init_struct(char **av)
{
	param_t *param = my_malloc(sizeof(*param));

	param->key_len = my_strlen(av[2]);
	param->type = ((my_atoi(av[3]) == 0 ? encrypt : decrypt));
	param->key_matrix = NULL;
	param->msg = av[1];
	param->key = av[2];

	return (param);
}

void set_matrix_key(param_t *param)
{
	int matrix_offset = 0;

	if (param->key_len > 1 && param->key_len <= 4) 
		matrix_offset = 4;
	else if (param->key_len > 4 && param->key_len <= 9) 
		matrix_offset = 9;
	else if (param->key_len > 9 && param->key_len <= 16) 
		matrix_offset = 16;

	param->key_matrix = my_malloc(sizeof(int) * matrix_offset);

	if (matrix_offset == 16)
		matrix_offset = 12;

	for (int i = 0; i < param->key_len; i++)
			param->key_matrix[i] = param->key[i];

	for (; param->key_len < matrix_offset; param->key_len++)
		param->key_matrix[param->key_len] = 0;
}