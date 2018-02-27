/*
** EPITECH PROJECT, 2017
** recipes.c
** File description:
** Arthur
*/

#include "my_cook.h"

struct queue *spider_cooked(int x, int y)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(x, y, COOKED_SPIDER));
	return (tmp);
}

struct queue *spider_bug(int x, int y)
{
	struct queue	*tmp = NULL;

	add_queue(tmp, create_food(x, y, COOKED_SPIDER));
	add_queue(tmp, create_food(x, y, GRILLED_BUG));
	return (tmp);
}
