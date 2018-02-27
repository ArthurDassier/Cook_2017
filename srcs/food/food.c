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

	return (tmp);
}

struct queue *generate_food(void)
{
	struct queue	*tmp = NULL;
	struct queue	*(*tab[])(void) = {&grilled_bug, NULL};
	int		no = 0;

	tmp = tab[no]();
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
