/*
** EPITECH PROJECT, 2017
** check_food.c
** File description:
** Arthur
*/

#include "my_cook.h"

static void move_bots(struct game *gm, int *pos_x, int *pos_y)
{
	gm->user = NULL;
	clean_carpet(pos_x, pos_y);
	gm->bots[0] = NULL;
	for (int i = 1; i < CLIENT_NO; i++)
		gm->bots[i - 1] = gm->bots[i];
}

static void cook_food(struct __entity__ *el)
{
	el->type += 1;
}

void check_food(struct game *gm, int *pos_x, int *pos_y)
{
	static int	i = 0;
	struct queue	*tmp2 = gm->bots[i];
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
	gm->score += (flag > 1) ? flag : -50;
	move_bots(gm, pos_x, pos_y);
	if (++i == CLIENT_NO)
		i = 0;
}
