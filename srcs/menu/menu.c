/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** <..>
*/

#include "my_cook.h"

static void init_menu(struct game *gm)
{
	gm->menu = add_queue(gm->menu, create_background(0, 0, MENU));
	gm->menu = add_queue(gm->menu, create_button(700, 300, PLAY_BUTTON));
	gm->menu = add_queue(gm->menu, create_button(700, 600, EXIT_BUTTON));
//	gm->menu = add_queue(gm->menu, create_food(0, 0, GRILLED_BUG));
//	printf("%p\n", create_food(0, 0, 0));
//	gm->menu = add_queue(gm->menu, create_button(500, 500, INFO_BUTTON));
}

static void event_handler(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->wd, &event)) {
		if (event.type == sfEvtMouseButtonPressed)
			detection(gm);
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
	}
}

static void draw_sprite(struct game *gm)
{
	struct queue		*tmp = gm->menu;
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
		event_handler(gm);
		if (gm->status == 0) {
			draw_sprite(gm);
			sfRenderWindow_display(gm->wd);
			sfSleep(gm->tm);
			sfRenderWindow_clear(gm->wd, sfBlack);
		}
		if (gm->status == 1)
			launch(gm);
	}
	return (0);
}
