/*
** EPITECH PROJECT, 2017
** book.c
** File description:
** <..>
*/

#include "my_cook.h"



static int event_handler(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->wd, &event)) {
		if (event.type == sfEvtMouseButtonPressed)
			return (1);
	}
	return (-1);
}

static void draw_sprite(struct game *gm)
{
	struct queue		*tmp = gm->game;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}
	el = create_background(500, 200, BOOK);
	el->draw(el, gm->wd);
	sfRenderWindow_drawText(gm->wd, gm->score_text, NULL);
}

int book(struct game *gm)
{
	int	no = 0;

	while (sfRenderWindow_isOpen(gm->wd)) {
		if ((no = event_handler(gm)) != -1)
			break;
		draw_sprite(gm);
		sfRenderWindow_display(gm->wd);
		sfText_setString(gm->score_text, my_itoa(gm->score));
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
	}
	return (no);
}

