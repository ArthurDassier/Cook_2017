/*
** EPITECH PROJECT, 2017
** check_food.c
** File description:
** Arthur
*/

#include "my_cook.h"

static void move_bots(struct game *gm, int *pos_x, int *pos_y)
{
	free(gm->user);
	gm->user = NULL;
	clean_carpet(pos_x, pos_y);
	if (gm->bots) {
		for (int i = 1; i < CLIENT_NO; i++) {
			gm->bots[i - 1] = NULL;
			gm->bots[i - 1] = gm->bots[i];
			gm->bots[i] = NULL;
		}
	}
}

static void cook_food(struct __entity__ *el)
{
	el->type += 1;
}

static int loop_carpet(struct game *gm, struct __entity__ *el)
{
	struct __entity__	*el2 = NULL;
	struct queue	*tmp = gm->user;

	while (tmp) {
		el2 = tmp->token;
		if (el && el2 && el->type == el2->type + 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void check_food(struct game *gm, int *pos_x, int *pos_y)
{
	static int	i = 0;
	struct queue	*tmp2 = gm->bots[0];
	struct __entity__	*el = NULL;
	int		flag = 0;

	while (tmp2) {
		el = tmp2->token;
		if (loop_carpet(gm, el))
			flag += 10;
		tmp2 = tmp2->next;
	}
	gm->score += (flag) ? flag : -10;
	move_bots(gm, pos_x, pos_y);
	if (++i == CLIENT_NO) {
		i = 0;
		*pos_x = 0;
		*pos_y = 0;
	}
}
