/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** Arthur
*/

#include "my_cook.h"

void destroyer(struct game *gm)
{
	sfClock_destroy(gm->horloge);
	sfText_destroy(gm->score_text);
	sfMusic_destroy(gm->zikmu);
	sfRenderWindow_destroy(gm->wd);
	free(gm);
}
