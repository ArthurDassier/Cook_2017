/*
** EPITECH PROJECT, 2017
** detection.c
** File description:
** Arthur
*/

#include "my_cook.h"

int detection(struct game *gm)
{
	struct queue		*tmp = gm->menu;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		if (el->ch == 'B' &&
		(el->collide(el, sfMouse_getPositionRenderWindow(gm->wd).x,
			sfMouse_getPositionRenderWindow(gm->wd).y) == 1)) {
			return (el->type);
		}
		tmp = tmp->next;
	}
	return (-1);
}

int detection_book(struct game *gm)
{
	struct queue		*tmp = gm->game;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		if (el->ch == 'B' &&
		(el->collide(el, sfMouse_getPositionRenderWindow(gm->wd).x,
			sfMouse_getPositionRenderWindow(gm->wd).y) == 1)) {
			return (el->type);
		}
		tmp = tmp->next;
	}
	return (-1);
}

int detection_pause(struct game *gm)
{
	struct queue		*tmp = gm->pause;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		if (el->ch == 'B' &&
		(el->collide(el, sfMouse_getPositionRenderWindow(gm->wd).x,
			sfMouse_getPositionRenderWindow(gm->wd).y) == 1)) {
			return (el->type);
		}
		tmp = tmp->next;
	}
	return (-1);
}

static void cook_food(struct __entity__ *el)
{
	el->type += 1;
}

void check_food(struct game *gm, int *pos_x, int *pos_y)
{
	struct queue	*tmp2 = gm->bots[0];
	struct __entity__	*el = NULL;
	struct __entity__	*el2 = NULL;
	int		flag = 1;

	while (gm->user && tmp2) {
		if (flag == 1)
			--flag;
		el = gm->user->token;
		el2 = tmp2->token;
		gm->user = gm->user->next;
		tmp2 = tmp2->next;
		cook_food(el);
		if (el && el2 && el->type == el2->type)
			flag += 10;
	}
	gm->score += (flag) ? flag : -50;
	gm->user = NULL;
	clean_carpet(pos_x, pos_y);
}
