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

char *bckg_tab(int type)
{
	char	*bckg_tab[2] = {"textures/1376139933194.png", NULL};

	return (bckg_tab[type]);
}
char *btn_tab(int type)
{
	char	*btn_tab[3] = {"textures/playbutton.png", NULL, "textures/exitbutton.png", NULL};

	return (btn_tab[type]);
}
