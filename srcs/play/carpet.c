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
	if (*y > 830)
		*y = 630;
}

void clean_carpet(int *pos_x, int *pos_y)
{
	*pos_x = 725;
	*pos_y = 630;
}

void set_carpet(int *pos_x, int *pos_y, int no, struct game *gm)
{
	gm->user = add_queue(gm->user, create_food(*pos_x, *pos_y, no));
	carpet_food(pos_x, pos_y);
}
