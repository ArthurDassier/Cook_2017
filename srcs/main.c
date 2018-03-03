/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main_file
*/

#include "my_cook.h"

static int menu_loop(struct game *gm, int no)
{
	while (sfRenderWindow_isOpen(gm->wd) && gm->status) {
		if (no == PLAY_BUTTON)
			launch(gm);
		if (no == EXIT_BUTTON)
			break;
		if (no == INFO_BUTTON)
			infos(gm);
		if (no == RTN_BUTTON)
			break;
		no = pause_game(gm);
	}
	return (no);
}

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
		no = menu_loop(gm, no);
		if (no == EXIT_BUTTON)
			break;
	}
	destroyer(gm);
	return (0);
}
