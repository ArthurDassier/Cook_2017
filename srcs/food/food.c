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

	add_queue(tmp, create_food(x, y, GRILLED_BUG));
	return (tmp);
}

static struct queue *spider_and_worm(int x, int y)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(x, y, COOKED_SPIDER));
	add_queue(tmp, create_food(x, y, COOKED_WORM));
	return (tmp);
}

static struct queue *bug_and_worm(int x, int y)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(x, y, GRILLED_BUG));
	add_queue(tmp, create_food(x, y, COOKED_WORM));
	return (tmp);
}

static struct queue *worm(int x, int y)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(x, y, COOKED_WORM));
	return (tmp);
}

struct queue *generate_food(int x, int y)
{
	struct queue	*tmp = NULL;
	struct queue	*(*tab[7])(int x, int y) = {&grilled_bug,
		&spider_and_worm, &bug_and_worm, &worm, &spider_cooked,
		&spider_bug, NULL};
	int		no = 0;

	srand(time(NULL));
	no = rand() % 5;
	tmp = tab[no](x, y);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
