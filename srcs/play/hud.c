/*
** EPITECH PROJECT, 2017
** hud.c
** File description:
** Arthur
*/

#include "my_cook.h"

static void init_game(struct game *gm)
{
	gm->game = add_queue(gm->game, create_background(0, 0, GAME));
	gm->game = add_queue(gm->game, create_food(300, 650, GREEN_BUG));
	gm->game = add_queue(gm->game, create_food(400, 650, BLUE_BUG));
	gm->game = add_queue(gm->game, create_food(500, 675, RAW_SPIDER));
	gm->game = add_queue(gm->game, create_food(300, 750, RAW_WORM));
}

static int test(sfEvent event)
{
	switch (event.key.code) {
		case sfKeyG:
			return (GREEN_BUG);
		case sfKeyB:
			return (BLUE_BUG);
		case sfKeyS:
			return (RAW_SPIDER);
		case sfKeyW:
			return (RAW_WORM);
		default:
			return (-2);
	}
}

static int event_handler(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->wd, &event)) {
		if (event.type == sfEvtKeyPressed &&
				event.key.code == sfKeyEscape)
			return (-1);
		if (event.type == sfEvtKeyPressed &&
				event.key.code == sfKeySpace)
			return (10);
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
		if (event.type == sfEvtKeyPressed)
			return (test(event));
	}
	return (-2);
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
	tmp = gm->user;
	while (tmp) {
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}
	sfRenderWindow_drawText(gm->wd, gm->score_text, NULL);
}

int launch(struct game *gm)
{
	int	no = 0;

	if (gm->game == NULL)
		init_game(gm);
	while (sfRenderWindow_isOpen(gm->wd)) {
		if ((no = event_handler(gm)) == -1)
			break;
		if (no == 10)
			gm->score += 1111111;
		else  if (no != -2)
			gm->user = add_queue(gm->user, create_food(800, 650,
						no));
		draw_sprite(gm);
		sfRenderWindow_display(gm->wd);
		sfText_setString(gm->score_text, my_itoa(gm->score));
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
	}
	return (no);
}
