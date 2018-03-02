/*
** EPITECH PROJECT, 2017
** create_customer.c
** File description:
** Arthur
*/

#include "my_cook.h"

static int draw_fp(customer_t *self, sfRenderWindow *win)
{
	sfSprite_setPosition(self->sprite[0], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[0], NULL);
	return (0);
}

static int move_fp(customer_t *self, int x, int y)
{
	self->pos.x = x;
	self->pos.y = y;
	return (0);
}

static int collide_fp(customer_t *self, int x, int y)
{
	sfFloatRect	taille = sfSprite_getGlobalBounds(self->sprite[0]);

	if (self->pos.x <= x && self->pos.x + taille.width >= x &&
		self->pos.y <= y && self->pos.y + taille.height >= y)
		return (1);
	return (0);
}

static customer_t *set_texture(customer_t *customer, enum customer type)
{
	sfTexture	*tx;

	tx = sfTexture_createFromFile(customer_tab(type), NULL);
	customer->sprite[0] = sfSprite_create();
	sfSprite_setTexture(customer->sprite[0], tx, sfTrue);
	return (customer);
}

customer_t *create_customer(int x, int y, enum customer type)
{
	customer_t	*customer = malloc(sizeof(customer_t));

	if (customer == NULL)
		return (NULL);
	customer->pos.x = x;
	customer->pos.y = y;
	customer->sprite = malloc(sizeof(sfSprite *) * 2);
	if (customer->sprite == NULL)
		return (NULL);
	customer->draw = &draw_fp;
	customer->move = &move_fp;
	customer->collide = &collide_fp;
	customer = set_texture(customer, type);
	customer->type = type;
	customer->ch = 'U';
	return (customer);
}
