/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** <..>
*/

#include "my_cook.h"

static void init_menu(struct game *gm)
{
	gm->menu = add_queue(gm->menu, create_button(100, 100));
	gm->menu = add_queue(gm->menu, create_button(100, 500));
	gm->menu = add_queue(gm->menu, create_button(500, 500));
}

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
	struct queue	*tmp = gm->menu;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}
}

int menu(struct game *gm)
{
	init_menu(gm);
	while (sfRenderWindow_isOpen(gm->wd)) {
		if (event_handler(gm) != 0)
			break;
		draw_sprite(gm);
		sfRenderWindow_display(gm->wd);
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
	}
	return (0);
}
