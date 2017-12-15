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

	return (param);
}