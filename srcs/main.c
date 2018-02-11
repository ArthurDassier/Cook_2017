/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main_file
*/

#include "my_cook.h"

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	struct game	*gm = NULL;

	if (env[0] == NULL)
		return (84);
	gm = init();
	if (gm == NULL)
		return (84);
	menu(gm);
	return (0);
}
