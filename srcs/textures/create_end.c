/*
** EPITECH PROJECT, 2017
** create_end.c
** File description:
** Arthur
*/

#include "my_cook.h"

static int draw_fp(end_t *self, sfRenderWindow *win)
{
	sfSprite_setPosition(self->sprite[0], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[0], NULL);
	return (0);
}

static int move_fp(end_t *self, int x, int y)
{
	self->pos.x = x;
	self->pos.y = y;
	return (0);
}

static int collide_fp(end_t *self, int x, int y)
{
	sfFloatRect	taille = sfSprite_getGlobalBounds(self->sprite[0]);

	if (self->pos.x <= x && self->pos.x + taille.width >= x &&
		self->pos.y <= y && self->pos.y + taille.height >= y)
		return (1);
	return (0);
}

end_t *create_end(int x, int y, enum end type)
{
	end_t	*bg = malloc(sizeof(end_t));
	sfTexture	*tx;

	if (bg == NULL)
		return (NULL);
	bg->pos.x = x;
	bg->pos.y = y;
	bg->sprite = malloc(sizeof(sfSprite *) * 2);
	if (bg->sprite == NULL)
		return (NULL);
	tx = sfTexture_createFromFile(win_loose_tab(type), NULL);
	bg->sprite[0] = sfSprite_create();
	sfSprite_setTexture(bg->sprite[0], tx, sfTrue);
	bg->draw = &draw_fp;
	bg->move = &move_fp;
	bg->collide = &collide_fp;
	bg->ch = 'E';
	bg->type = type;
	return (bg);
}
