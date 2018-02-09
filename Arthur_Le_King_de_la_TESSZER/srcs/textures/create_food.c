/*
** EPITECH PROJECT, 2017
** create_food.c
** File description:
** blabla
*/

#include "my_cook.h"

static int draw_fp(food_t *self, sfRenderWindow *win)
{
	sfSprite_setPosition(self->sprite[0], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[0], NULL);
	return (0);
}

static int move_fp(food_t *self, int x, int y)
{
	self->pos.x = x;
	self->pos.y = y;
	return (0);
}

static int collide_fp(food_t *self, int x, int y)
{
	sfFloatRect	taille = sfSprite_getGlobalBounds(self->sprite[0]);

	if (self->pos.x <= x && self->pos.x + taille.width >= x &&
		self->pos.y <= y && self->pos.y + taille.height >= y)
		return (1);
	return (0);
}

food_t *create_food(int x, int y, enum food type)
{
	food_t		*food = malloc(sizeof(food_t));
	sfTexture	*tx;

	if (food == NULL)
		return (NULL);
	food->pos.x = x;
	food->pos.y = y;
	food->sprite = malloc(sizeof(sfSprite *) * 2);
	if (food->sprite == NULL)
		return (NULL);
	tx = sfTexture_createFromFile(btn_tab(type), NULL);
	food->sprite[0] = sfSprite_create();
	sfSprite_setTexture(food->sprite[0], tx, sfTrue);
	food->draw = &draw_fp;
	food->move = &move_fp;
	food->collide = &collide_fp;
	return (food);
}
