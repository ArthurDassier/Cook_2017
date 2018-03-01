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

void check_food(struct game *gm)
{
	struct queue	*tmp2 = pop_stack(&(gm->bots));
	struct __entity__	*el = NULL;
	struct __entity__	*el2 = NULL;
	int		flag = 1;

	while (gm->user && tmp2) {
		if (flag == 1)
			--flag;
		el = pop_queue(&gm->user);
		el2 = pop_queue(&tmp2);
		if (el->type != el2->type)
			flag += 10;
	}
	if (flag)
		gm->score -= flag;
	while (gm->user) {
		pop_queue(&gm->user);
	}
	gm->score += 50;
}
