/*
** EPITECH PROJECT, 2017
** my_cook.h
** File description:
** <..>
*/

#ifndef MY_COOK_H_
#define MY_COOK_H_

#include "my.h"
#include "my_getopt.h"
#include "clist.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct __entity__
{
	sfVector2f	pos;
	sfSprite	**sprite;
	int	(*draw)(struct __entity__ *, sfRenderWindow *);
	int	(*move)(struct __entity__ *, int, int);
};

#endif
