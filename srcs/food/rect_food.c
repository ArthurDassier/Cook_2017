/*
** EPITECH PROJECT, 2017
** rest_food.c
** File description:
** Arthur
*/

#include "my_cook.h"

sfIntRect position_pixels(int a, int b, int c, int d)
{
	sfIntRect	taille;

	taille.height = a;
	taille.left = b;
	taille.top = c;
	taille.width = d;
	return (taille);
}

sfIntRect rect_bug(enum food type)
{
	sfIntRect rect;

	if (type == GREEN_BUG)
		rect = position_pixels(100, 134, 0, 100);
	if (type == BLUE_BUG)
		rect = position_pixels(100, 28, 0, 100);
	if (type == GRILLED_BUG)
		rect = position_pixels(100, 243, 0, 100);
	return (rect);
}
