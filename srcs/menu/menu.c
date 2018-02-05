/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** <..>
*/

#include "my_cook.h"

static int event_handler(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->wd, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			return (1);
		}
		if (event.type == sfEvtClosed)
			return (-1);
	}
	return (0);
}

static void draw_sprite(struct game *gm)
{

}

int menu(struct game *gm)
{
	while (sfRenderWindow_isOpen(gm->wd)) {
		if (event_handler(gm) != 0)
			break;
		draw_sprite(gm);
		sfRenderWindow_display(gm->wd);
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->win, sfBlack);
	}
	return (0);
}
