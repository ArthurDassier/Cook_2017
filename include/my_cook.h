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

#define WIN "Sesame & Sel"
#define WIDTH 1920
#define HEIGHT 1080
#define CLIENT_NO 5

typedef struct __entity__ button_t;
typedef struct __entity__ background_t;
typedef struct __entity__ customer_t;
typedef struct __entity__ food_t;
typedef struct __entity__ end_t;

enum food {
	GREEN_BUG = 0,
	GRILLED_BUG_G = 1,
	BLUE_BUG = 2,
	GRILLED_BUG_B = 3,
	RAW_SPIDER = 4,
	COOKED_SPIDER = 5,
	RAW_WORM = 6,
	COOKED_WORM = 7
};

enum customer {
	HOMME1 = 0,
	FEMME = 1
};

enum button {
	PLAY_BUTTON = 0,
	EXIT_BUTTON = 1,
	INFO_BUTTON = 2,
	RTN_BUTTON = 3,
	RED_BOOK = 4
};

enum background {
	MENU = 0,
	GAME = 1,
	INFOS = 2,
	PAUSE = 3,
	BOOK = 4
};

enum end {
	BACK = 0,
	WINNER = 1,
	LOOSE = 2
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

struct ph
{
	sfTexture	*text_ph;
	sfSprite	*spt_ph;
	sfIntRect	anim_ph[3];
	sfVector2f	pos_ph;
};

struct game
{
	struct queue	*menu;
	struct queue	*game;
	struct queue	*user;
	struct queue	*info;
	struct queue	*pause;
	struct queue	*end;
	struct queue	**bots;
	struct ph	*phone;
	customer_t	**clients;
	sfRenderWindow	*wd;
	sfVideoMode	video_md;
	sfTime		tm;
	sfClock		*horloge;
	sfMusic		*zikmu;
	int		score;
	sfText		*score_text;
	sfText		*good_text;
	sfText		*bad_text;
	int		good;
	int		bad;
	int		status;
	int		next_pos_x;
	int		next_pos_y;
};

struct game *init(void);
int menu(struct game *gm);
int detection(struct game *gm);
int detection_pause(struct game *gm);
int detection_book(struct game *gm);
void close_wd(struct game *gm);
void check_food(struct game *gm, int *pos_x, int *pos_y);
int launch(struct game *gm);
int infos(struct game *gm);
int end_it(struct game *gm, int status);
int pause_game(struct game *gm);
int book(struct game *gm);
void init_phone(struct game *gm);
void destroyer(struct game *gm);

char *food_tab(int type);
char *bckg_tab(int type);
char *customer_tab(int type);
char *btn_tab(int type);
char *win_loose_tab(int type);

int check_score(int score);
void carpet_food(int *x, int *y);
void destroy_food(struct game *gm);
void clean_carpet(int *pos_x, int *pos_y);
void set_carpet(int *, int *, int, struct game *);
void draw_client(struct game *gm);
void draw_phone(struct game *gm);
void food_gen(struct game *gm);

sfIntRect position_pixels(int a, int b, int c, int d);
sfIntRect rect_bug(enum food type);

struct queue *spider_cooked(int x, int y);
struct queue *spider_bug(int x, int y);
struct queue *generate_food(sfClock *horloge, struct game *gm, int i);
void check_food(struct game *gm, int *pos_x, int *pos_y);

button_t *create_button(int, int, enum button type);
background_t *create_background(int, int, enum background type);
end_t *create_end(int, int, enum end type);
food_t *create_food(int, int, enum food type);
customer_t *create_customer(int, int, enum customer type);

#endif
