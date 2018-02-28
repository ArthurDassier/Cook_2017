/*
** EPITECH PROJECT, 2017
** pauses.c
** File description:
** Arthur
*/

#include "my_cook.h"

static void init_game(struct game *gm)
{
	gm->pause = add_queue(gm->pause, create_background(0, 0, MENU));
	gm->pause = add_queue(gm->pause, create_background(674, 200, PAUSE));
	gm->pause = add_queue(gm->pause, create_button(680, 300, PLAY_BUTTON));
	gm->pause = add_queue(gm->pause, create_button(300, 600, EXIT_BUTTON));
	gm->pause = add_queue(gm->pause, create_button(1000, 600, INFO_BUTTON));
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
	struct queue		*tmp = gm->pause;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}
}

int pause_game(struct game *gm)
{
	int	no = 0;

	if (gm->pause == NULL)
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
