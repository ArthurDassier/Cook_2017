/*
** EPITECH PROJECT, 2017
** close_wd.c
** File description:
** blabla
*/

#include "my_cook.h"

void close_wd(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->wd, &event))
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
}
