/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** <..>
*/

#include "my_runner.h"

static int even_handler(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->win, &event)) {
		if (event.type == sfEvtKeyPressed &&
				event.key.code == sfKeySpace) {
			return (1);
		}
		if (event.type == sfEvtClosed)
			return (-1);
	}
	return (0);
}

static void draw_sprite(struct game *gm)
{
	int	i = 0;

	for (i = 0; i < (BACKGROUND_NO / 2); i++) {
		gm->bg[i]->animate(gm->bg[i], gm->win);
		gm->bg[i]->move(gm->bg[i], -1 * (i + 1), 0);
		gm->bg[i + (BACKGROUND_NO / 2)]->animate(gm->bg[i +
				(BACKGROUND_NO / 2)], gm->win);
		gm->bg[i + (BACKGROUND_NO / 2)]->move(gm->bg[i +
				(BACKGROUND_NO / 2)], -1 * (i + 1), 0);
	}
	gm->p1->animate(gm->p1, gm->win);
	for (i = 0; i < gm->set->no_tile; i++)
		gm->ground[i]->animate(gm->ground[i], gm->win);
	for (i = 0; i < gm->set->no_mob; i++)
		gm->mob[i]->animate(gm->mob[i], gm->win);
	gm->death_title->animate(gm->death_title, gm->win);
	sfRenderWindow_drawText(gm->win, gm->score_text, NULL);
}

int death(struct game *gm)
{
	int	no = 0;
	sfVector2f	pos;

	pos.x = 510;
	pos.y = 300;
	sfText_setPosition(gm->score_text, pos);
	while (sfRenderWindow_isOpen(gm->win)) {
		if((no = even_handler(gm)) != 0)
			break;
		draw_sprite(gm);
		sfRenderWindow_display(gm->win);
		sfSleep(gm->fps);
		sfRenderWindow_clear(gm->win, sfBlack);
	}
	return (no);
}
