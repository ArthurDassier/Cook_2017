/*
** EPITECH PROJECT, 2017
** hud.c
** File description:
** Arthur
*/

#include "my_cook.h"

void launch(struct game *gm)
{
	struct queue *tam = NULL;
	tam = add_queue(tam, create_background(0, 0, GAME));
	struct queue		*tmp = tam;
	struct __entity__	*el = NULL;
	el = tmp->token;
	el->draw(el, gm->wd);
	sfRenderWindow_display(gm->wd);
	sfSleep(gm->tm);
	sfRenderWindow_clear(gm->wd, sfBlack);
}
