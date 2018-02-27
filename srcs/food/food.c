/*
** EPITECH PROJECT, 2017
** food.c
** File description:
** food generator file
*/

#include "my_cook.h"

static struct queue *grilled_bug(void)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(0, 0, GRILLED_BUG));
	return (tmp);
}

static struct queue *spider_and_worm(void)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(0, 0, COOKED_SPIDER));
	add_queue(tmp, create_food(0, 0, COOKED_WORM));
	return (tmp);
}

static struct queue *bug_and_worm(void)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(0, 0, GRILLED_BUG));
	add_queue(tmp, create_food(0, 0, COOKED_WORM));
	return (tmp);
}

static struct queue *worm(void)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(0, 0, COOKED_WORM));
	return (tmp);
}

struct queue *generate_food(void)
{
	struct queue	*tmp = NULL;
	struct queue	*(*tab[5])(void) = {&grilled_bug, &spider_and_worm,
		 			&bug_and_worm, &worm, NULL};

	srand(time(NULL));
	no = rand() % 3;
	tmp = tab[no]();
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
