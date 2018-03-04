/*
** EPITECH PROJECT, 2017
** end.c
** File description:
** Arthur
*/

#include "my_cook.h"

static void init_end(struct game *gm, int status)
{
	gm->end = add_queue(gm->end, create_end(0, 0, BACK));
	if (status == 3)
		gm->end = add_queue(gm->end, create_end(680, 300, WINNER));
	else
		gm->end = add_queue(gm->end, create_end(680, 300, LOOSE));
}

static int event_handler(struct game *gm)
{
	sfEvent	event;
	int	no = -1;

	while (sfRenderWindow_pollEvent(gm->wd, &event)) {
		if (event.type == sfEvtMouseButtonPressed)
			no = detection(gm);
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
	}
	return (no);
}

static void draw_sprite(struct game *gm)
{
	struct queue		*tmp = gm->end;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}
}

int end_it(struct game *gm, int status)
{
	int	no = 0;

	if (gm->end == NULL)
		init_end(gm, status);
	while (sfRenderWindow_isOpen(gm->wd)) {
		if ((no = event_handler(gm)) != -1)
			break;
		draw_sprite(gm);
		sfRenderWindow_display(gm->wd);
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
	}
	return (status);
}
