/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main_file
*/

#include "my_cook.h"

int main(int ac, char **av)
{
	struct game	*gm = init();

	if (gm == NULL)
		return (84);
	menu(gm);
//	while (sfRenderWindow_isOpen(gm->wd)) {
//		btn->draw(btn, gm->wd);
//		if (btn->collide(btn, sfMouse_getPositionRenderWindow(gm->wd).x,
//			sfMouse_getPositionRenderWindow(gm->wd).y) == 1) {
//		}
//		sfRenderWindow_display(gm->wd);
//		close_wd(gm);
//		sfSleep(gm->tm);
//	}
	return (0);
}