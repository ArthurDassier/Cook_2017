/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main_file
*/

#include "my_cook.h"

int main(int ac, char **av)
{
	sfRenderWindow	*wd;
	sfVideoMode	video_md;
	sfTime		tm;
	int i = 0;

	tm.microseconds = 2000;
	video_md.width = 1920;
	video_md.height = 1080;
	video_md.bitsPerPixel = 32;
	wd = sfRenderWindow_create(video_md, "Zonan_Kebab", sfDefaultStyle, NULL);
	button_t *btn = create_button(100, 100);
	while (sfRenderWindow_isOpen(wd)) {
		btn->draw(btn, wd);
		if (btn->collide(btn, sfMouse_getPositionRenderWindow(wd).x, sfMouse_getPositionRenderWindow(wd).y) == 1) {
			printf("Oooh clique %d\n", i);
			++i;
		}
		sfRenderWindow_display(wd);
		sfSleep(tm);
	}
	return (0);
}
