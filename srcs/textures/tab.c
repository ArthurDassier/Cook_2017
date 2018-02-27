/*
** EPITECH PROJECT, 2017
** path_food.c
** File description:
** blabla
*/

#include "my_cook.h"

char *customer_tab(int type)
{
	char	*customer_tab[3] = {"textures/FEMME.png",
		"textures/HOMME1.png", NULL};

	return (customer_tab[type]);
}

char *food_tab(int type)
{
	char	*food_tab[8] = {"textures/BUGS.png", "textures/BUGS.png",
		"textures/BUGS.png", "textures/SPIDERS.png",
		"textures/SPIDERS.png", "textures/WORM.png",
		"textures/WORM.png", NULL};

	if (type < 0 || type >= 7)
		return (NULL);
	return (food_tab[type]);
}

char *bckg_tab(int type)
{
	char	*bckg_tab[4] = {"textures/1376139933194.png",
		"textures/HUD.png", "textures/help_menu.png", NULL};

	return (bckg_tab[type]);
}
char *btn_tab(int type)
{
	char	*btn_tab[4] = {"textures/playbutton.png",
		"textures/exitbutton.png","textures/help.png", NULL};

	return (btn_tab[type]);
}
