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
typedef struct __entity__ customer_t;
typedef struct __entity__ food_t;

enum food {
	GREEN_BUG = 0,
	BLUE_BUG = 1,
	GRILLED_BUG = 2,
	RAW_SPIDER = 3,
	COOKED_SPIDER = 4
	RAW_WORM = 5,
	COOKED_WORM = 6
};

enum customer {
	HOMME1 = 0,
	FEMME = 1
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
	char		ch;
	int		type;
	int		(*draw)(struct __entity__ *, sfRenderWindow *);
	int		(*move)(struct __entity__ *, int, int);
	int		(*collide)(struct __entity__ *, int, int);
};

struct game
{
	struct queue	*menu;
	struct queue	*game;
	sfRenderWindow	*wd;
	sfVideoMode	video_md;
	sfTime		tm;
	int		status;
};

struct game *init(void);
int menu(struct game *);
int detection(struct game *gm);
void close_wd(struct game *gm);

int launch(struct game *gm);

char *food_tab(int type);
char *bckg_tab(int type);
char *customer_tab(int type);
char *btn_tab(int type);

sfIntRect rect_bug(enum food type);

button_t *create_button(int, int, enum button type);
background_t *create_background(int, int, enum background type);
food_t *create_food(int, int, enum food type);
customer_t *create_customer(int, int, enum customer type);

#endif
