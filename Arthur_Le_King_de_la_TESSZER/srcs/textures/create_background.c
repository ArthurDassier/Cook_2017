/*
** EPITECH PROJECT, 2017
** create_background.c
** File description:
** <..>
*/

#include "my_cook.h"

static int draw_fp(background_t *self, sfRenderWindow *win)
{
	sfSprite_setPosition(self->sprite[0], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[0], NULL);
	return (0);
}

static int move_fp(background_t *self, int x, int y)
{
	self->pos.x = x;
	self->pos.y = y;
	return (0);
}

static int collide_fp(background_t *self, int x, int y)
{
	sfFloatRect	taille = sfSprite_getGlobalBounds(self->sprite[0]);

	if (self->pos.x <= x && self->pos.x + taille.width >= x &&
		self->pos.y <= y && self->pos.y + taille.height >= y)
		return (1);
	return (0);
}

background_t *create_background(int x, int y, enum background type)
{
	background_t	*bg = malloc(sizeof(background_t));
	sfTexture	*tx;

	if (bg == NULL)
		return (NULL);
	bg->pos.x = x;
	bg->pos.y = y;
	bg->sprite = malloc(sizeof(sfSprite *) * 2);
	if (bg->sprite == NULL)
		return (NULL);
	tx = sfTexture_createFromFile(bckg_tab(type), NULL);
	bg->sprite[0] = sfSprite_create();
	sfSprite_setTexture(bg->sprite[0], tx, sfTrue);
	bg->draw = &draw_fp;
	bg->move = &move_fp;
	bg->collide = &collide_fp;
	return (bg);
}
