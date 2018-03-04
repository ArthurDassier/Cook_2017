/*
** EPITECH PROJECT, 2017
** score.c
** File description:
** <..>
*/

#include "my_cook.h"

int check_score(int score)
{
	if (score > 200)
		return (3);
	if (score < 0)
		return (-3);
	return (0);
}
