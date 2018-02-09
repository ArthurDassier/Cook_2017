/*
** EPITECH PROJECT, 2017
** path_food.c
** File description:
** blabla
*/

#include "my_cook.h"

char *food_tab(int type)
{
	char	*food_tab[4] = {"textures/Food_Special.png", "textures/playbutton.png",
	"textures/1376139933194.jpg", NULL};

	return (food_tab[type]);
}
