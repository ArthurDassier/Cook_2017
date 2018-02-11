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
typedef struct __entity__ background_t;
typedef struct __entity__ food_t;

enum food {
	PLATS = 0
};

enum button {
	PLAY_BUTTON = 0,
	EXIT_BUTTON = 1,
	INFO_BUTTON = 2
};

enum background {
	MENU = 0,
	GAME = 1,
	PAUSE = 2
};

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
int menu(struct game *);
int detection(struct game *gm);
void close_wd(struct game *gm);

char *food_tab(int type);
char *bckg_tab(int type);
char *btn_tab(int type);

button_t *create_button(int, int, enum button type);
background_t *create_background(int, int, enum background type);
food_t *create_food(int, int, enum food type);

#endif
