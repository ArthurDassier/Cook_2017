/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main_file
*/

#include "my_cook.h"

static int code_h(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("Launch the game and play, ");
		my_putstr("the help menu is inside the game\n");
		return (0);
	}
	return (84);
}

static int menu_loop(struct game *gm, int no)
{
	int	leave = 0;

	while (sfRenderWindow_isOpen(gm->wd) && gm->status) {
		if (no == PLAY_BUTTON)
			leave = launch(gm);
		if (no == EXIT_BUTTON)
			break;
		if (no == INFO_BUTTON)
			infos(gm);
		if (no == RTN_BUTTON)
			break;
		if (leave == 3 || leave == -3)
			return (leave);
		no = pause_game(gm);
	}
	return (no);
}

int main(int ac, char **av, char **env)
{
	int		no = 0;
	struct game	*gm = NULL;

	if (ac > 1)
		return (code_h(av));
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
		if (no == -3)
			break;
		if (no == 3)
			break;
	}
	destroyer(gm);
	return (0);
}
