/*
** EPITECH PROJECT, 2017
** detection.c
** File description:
** Arthur
*/

#include "my_cook.h"

int detection(struct game *gm)
{
	struct queue		*tmp = gm->menu->next;
	struct __entity__	*el = NULL;

	while (tmp) {
		el = tmp->token;
		if (el->ch == 'B' && el->type == EXIT_BUTTON &&
		(el->collide(el, sfMouse_getPositionRenderWindow(gm->wd).x,
			sfMouse_getPositionRenderWindow(gm->wd).y) == 1))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
