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
