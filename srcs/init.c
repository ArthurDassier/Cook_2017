/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "my_cook.h"

struct game *init(void)
{
	struct game	*gm = malloc(sizeof(struct game));

	if (gm == NULL)
		return (NULL);
	gm->video_md.width = WIDTH;
	gm->video_md.height = HEIGHT;
	gm->video_md.bitsPerPixel = 32;
	gm->tm.microseconds = 20000;
	gm->wd = sfRenderWindow_create(gm->video_md, WIN, sfDefaultStyle, NULL);
	gm->status = 1;
	gm->menu = NULL;
	gm->user = NULL;
	gm->game = NULL;
	return (gm);
}
