/*
** EPITECH PROJECT, 2017
** create_button.c
** File description:
** blabla
*/

#include "my_cook.h"

static int draw_fp(button_t *self, sfRenderWindow *win)
{
	sfSprite_setPosition(self->sprite[0], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[0], NULL);
	return (0);
}

static int move_fp(button_t *self, int x, int y)
{
	self->pos.x = x;
	self->pos.y = y;
	return (0);
}

static int collide_fp(button_t *self, int x, int y)
{
	sfFloatRect	taille = sfSprite_getGlobalBounds(self->sprite[0]);
	if (self->pos.x <= x && self->pos.x + taille.width >= x &&
		self->pos.y <= y && self->pos.y + taille.height >= y)
		return (1);
	return (0);
}

button_t *create_button(int x, int y, enum button btn_type)
{
	button_t	*btn = malloc(sizeof(button_t));
	sfTexture	*tx;

	if (btn == NULL)
		return (NULL);
	btn->pos.x = x;
	btn->pos.y = y;
	btn->sprite = malloc(sizeof(sfSprite *) * 2);
	if (btn->sprite == NULL)
		return (NULL);
	tx = sfTexture_createFromFile("textures/GREEN.png", NULL);
	btn->sprite[0] = sfSprite_create();
	sfSprite_setTexture(btn->sprite[0], tx, sfTrue);
	btn->draw = &draw_fp;
	btn->move = &move_fp;
	btn->collide = &collide_fp;
	return (btn);
}
