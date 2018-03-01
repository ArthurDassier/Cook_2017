/*
** EPITECH PROJECT, 2017
** carpet.c
** File description:
** Arthur
*/

#include "my_cook.h"

void carpet_food(int *x, int *y)
{
	*x += 50;
	if (*x > 1150) {
		*x = 725;
		*y += 50;
	}
}

void clean_carpet(struct game *gm, int *pos_x, int *pos_y)
{
	gm->user = NULL;
	*pos_x = 725;
	*pos_y = 630;
}
