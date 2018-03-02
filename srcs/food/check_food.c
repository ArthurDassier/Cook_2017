/*
** EPITECH PROJECT, 2017
** check_food.c
** File description:
** Arthur
*/

#include "my_cook.h"

static void lf_food(struct game *gm, int *pos_x, int *pos_y)
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

void check_food(struct game *gm, int *pos_x, int *pos_y, int i)
{
	while (i < CLIENT_NO) {
		lf_food(gm, pos_x, pos_y);
		++i;
	}
}
