/*
** EPITECH PROJECT, 2017
** phone.c
** File description:
** Arthur
*/

#include "my_cook.h"

void draw_phone(struct game *gm)
{
	sfTime		time_s;
	static int 	i = 0;

	time_s.microseconds = 20000;
	sfSleep(time_s);
	sfSprite_setPosition(gm->phone->spt_ph, gm->phone->pos_ph);
	sfRenderWindow_drawSprite(gm->wd, gm->phone->spt_ph, NULL);
	sfSprite_setTextureRect(gm->phone->spt_ph, gm->phone->anim_ph[i]);
	++i;
	if (i == 3)
		i = 0;
}

void init_anim_ph(struct game *gm)
{
	int	stand = 0;
	int	i = 0;

	while (i != 3) {
		gm->phone->anim_ph[i] = position_pixels(300, stand, 0, 230);
		stand += 265;
		++i;
	}
}

void init_phone(struct game *gm)
{
	gm->phone = malloc(sizeof(struct ph));
	gm->phone->text_ph = sfTexture_createFromFile("textures/phonering.png", NULL);
	gm->phone->spt_ph = sfSprite_create();
	sfSprite_setTexture(gm->phone->spt_ph, gm->phone->text_ph, sfTrue);
	init_anim_ph(gm);
	gm->phone->pos_ph.x = 1430;
	gm->phone->pos_ph.y = 742;
}
