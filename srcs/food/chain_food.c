/*
** EPITECH PROJECT, 2017
** chain_food.c
** File description:
** Arthur
*/

#include "my_cook.h"

struct queue *chain_food(void)
{
	struct queue	*food = NULL;
	int		i = 0;
	int		x = 100;

	while (i != 2) {
		add_queue(food, create_food(x, 200, i));
		x += 100;
		++i;
	}
	return (food);
}
