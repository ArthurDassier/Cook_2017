/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "my_cook.h"

static void set_text(struct game *gm)
{
	sfFont		*fnt = sfFont_createFromFile("./fonts/arial.ttf");
	sfVector2f	pos;

	pos.x = 500;
	pos.y = 20;
	gm->score_text = sfText_create();
	sfText_setFont(gm->score_text, fnt);
	sfText_setPosition(gm->score_text, pos);
	sfText_setString(gm->score_text, "0");
	for (int i = 0; i < CLIENT_NO; i++)
		gm->bots[i] = NULL;
	gm->next_pos_x = 1200;
	gm->next_pos_y = 100;
	gm->menu = NULL;
	gm->user = NULL;
	gm->info = NULL;
	gm->game = NULL;
}

struct game *init(void)
{
	struct game	*gm = malloc(sizeof(struct game));

	if (gm == NULL)
		return (NULL);
	gm->video_md.width = WIDTH;
	gm->video_md.height = HEIGHT;
	gm->video_md.bitsPerPixel = 32;
	gm->tm.microseconds = 20000;
	gm->zikmu = sfMusic_createFromFile("./Musics/japan.ogg");
	sfMusic_setLoop(gm->zikmu, sfTrue);
	sfMusic_play(gm->zikmu);
	gm->wd = sfRenderWindow_create(gm->video_md, WIN, sfDefaultStyle, NULL);
	gm->status = 1;
	gm->clients = malloc(sizeof(struct customer_t*) * CLIENT_NO);;
	gm->bots = malloc(sizeof(struct queue *) * CLIENT_NO);
	if (gm->bots == NULL || gm->clients == NULL)
		return (NULL);
	gm->score = 100;
	set_text(gm);
	return (gm);
}
