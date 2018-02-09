/*
** EPITECH PROJECT, 2017
** path_food.c
** File description:
** blabla
*/

#include "my_cook.h"

char *food_tab(int type)
{
	char	*food_tab[2] = {"textures/Food_Special.png", NULL};

	return (food_tab[type]);
}
