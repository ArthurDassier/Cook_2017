/*
** EPITECH PROJECT, 2017
** draw_client.c
** File description:
** <..>
*/

#include "my_cook.h"

static void draw_customer(struct game *gm, int i)
{
	struct __entity__ *el = NULL;
	struct queue	*tmp = NULL;

	tmp = gm->bots[i];
	while (tmp) {
		if (gm->clients[i])
			gm->clients[i]->draw(gm->clients[i], gm->wd);
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}

}

void draw_client(struct game *gm)
{
	for (int i = 0; i < CLIENT_NO; i++) {
		draw_customer(gm, i);
	}

}
