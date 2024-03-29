/*
** EPITECH PROJECT, 2017
** infos.c
** File description:
** Arthur
*/

#include "my_cook.h"

static void init_game(struct game *gm)
{
	gm->info = add_queue(gm->info, create_background(0, 0, MENU));
	gm->info = add_queue(gm->info, create_background(674, 411, INFOS));
	gm->info = add_queue(gm->info, create_button(730, 150, INFO_BUTTON));
}

static int event_handler(struct game *gm)
{
	sfEvent	event;
	int	no = -1;

	while (sfRenderWindow_pollEvent(gm->wd, &event)) {
		if (event.type == sfEvtKeyPressed &&
				event.key.code == sfKeyEscape) {
			return (1);
		}
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
	}
	return (no);
}

static void draw_sprite(struct game *gm)
{
	struct queue		*tmp = gm->info;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}
}

int infos(struct game *gm)
{
	int	no = 0;

	if (gm->info == NULL)
		init_game(gm);
	while (sfRenderWindow_isOpen(gm->wd)) {
		if ((no = event_handler(gm)) != -1)
			break;
		draw_sprite(gm);
		sfRenderWindow_display(gm->wd);
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
	}
	return (no);
}
