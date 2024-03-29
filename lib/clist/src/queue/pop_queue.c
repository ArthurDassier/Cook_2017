/*
** EPITECH PROJECT, 2017
** pop_queue.c
** File description:
** <..>
*/

#include "clist.h"
#include <stdio.h>

void *pop_queue(struct queue **root)
{
	struct queue	*tmp;
	struct queue	*before;
	void		*token;

	if (*root == NULL)
		return (NULL);
	tmp = *root;
	before = tmp;
	printf("--?>%p:%p\n", tmp, tmp->next);
	while (tmp->next) {
		before = tmp;
		tmp = tmp->next;
	}
	token = tmp->token;
	free(tmp);
	if (before == *root)
		*root = NULL;
	else if (before)
		before->next = NULL;
	return (token);
}
