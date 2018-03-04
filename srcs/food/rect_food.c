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
	if (type == GRILLED_BUG_B)
		rect = position_pixels(100, 343, 0, 100);
	if (type == GRILLED_BUG_G)
		rect = position_pixels(100, 243, 0, 100);
	if (type == RAW_SPIDER)
		rect = position_pixels(50, 0, 50, 100);
	if (type == COOKED_SPIDER)
		rect = position_pixels(50, 0, 0, 100);
	if (type == RAW_WORM)
		rect = position_pixels(100, 0, 0, 100);
	if (type == COOKED_WORM)
		rect = position_pixels(100, 0, 100, 100);
	return (rect);
}
