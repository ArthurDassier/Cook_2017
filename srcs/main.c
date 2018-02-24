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
	int		no = 0;
	struct game	*gm = NULL;

	if (env[0] == NULL)
		return (84);
	gm = init();
	if (gm == NULL)
		return (84);
	while (sfRenderWindow_isOpen(gm->wd) && gm->status) {
		no = menu(gm);
		if (no == PLAY_BUTTON)
			launch(gm);
		if (no == EXIT_BUTTON)
			break;
		if (no == INFO_BUTTON)
			continue;
	}
	return (0);
}
