/*
** EPITECH PROJECT, 2017
** food.c
** File description:
** food generator file
*/

#include "my_cook.h"
#include <time.h>

static struct queue *grilled_bug(int x, int y)
{
	struct queue	*tmp = NULL;

	tmp = add_queue(tmp, create_food(x, y, GRILLED_BUG_B));
	return (tmp);
}

static struct queue *spider_and_worm(int x, int y)
{
	struct queue	*tmp = NULL;

	tmp = add_queue(tmp, create_food(x, y, COOKED_SPIDER));
	tmp = add_queue(tmp, create_food(x, y, COOKED_WORM));
	return (tmp);
}

static struct queue *bug_and_worm(int x, int y)
{
	struct queue	*tmp = NULL;

	tmp = add_queue(tmp, create_food(x, y, GRILLED_BUG_B));
	tmp = add_queue(tmp, create_food(x, y, COOKED_WORM));
	return (tmp);
}

static struct queue *worm(int x, int y)
{
	struct queue	*tmp = NULL;

	tmp = add_queue(tmp, create_food(x, y, COOKED_WORM));
	return (tmp);
}

struct queue *generate_food(sfClock *horloge, struct game *gm, int i)
{
	sfTime	temps = sfClock_getElapsedTime(horloge);
	struct queue	*tmp = NULL;
	struct queue	*(*tab[7])(int x, int y) = {&grilled_bug,
		&spider_and_worm, &bug_and_worm, &worm, &spider_cooked,
		&spider_bug, NULL};
	int		no = 0;

	no = rand() % 6;
	tmp = tab[no](gm->next_pos_x + 200, gm->next_pos_y + 100);
	if (tmp == NULL)
		return (NULL);
	if (temps.microseconds > 8000000) {
		sfClock_restart(horloge);
		gm->clients[i] = create_customer(gm->next_pos_x,
				gm->next_pos_y, (i % 2) ? HOMME1 : FEMME);
		gm->next_pos_x -= 200;
		return (tmp);
	}
	return (NULL);
}
