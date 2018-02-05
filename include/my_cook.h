/*
** EPITECH PROJECT, 2017
** my_cook.h
** File description:
** config
*/

#ifndef MY_COOK_H_
#define MY_COOK_H_

#include "my.h"
#include "my_getopt.h"
#include "clist.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define WIN "Zonan_Kebab"
#define WIDTH 1920
#define HEIGHT 1080

typedef struct __entity__ button_t;

struct __entity__
{
	sfVector2f	pos;
	sfSprite	**sprite;
	int		(*draw)(struct __entity__ *, sfRenderWindow *);
	int		(*move)(struct __entity__ *, int, int);
	int		(*collide)(struct __entity__ *, int, int);
};

struct game
{
	struct queue	*menu;
	sfRenderWindow	*wd;
	sfVideoMode	video_md;
	sfTime		tm;
};

struct game *init(void);
button_t *create_button (int, int);

#endif
