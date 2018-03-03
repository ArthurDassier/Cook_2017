##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -I./include

LFLAGS=	-L./lib -lmy -lmy_getopt -lclist
ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LFLAGS+=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system
else
LFLAGS+=	-lc_graph_prog
endif

NAME=	my_cook

SRC_DIR=	./srcs
SRC=		$(SRC_DIR)/main.c				\
			$(SRC_DIR)/init.c			\
			$(SRC_DIR)/close_wd.c			\
			$(SRC_DIR)/destroy.c			\
			$(SRC_DIR)/menu/create_button.c		\
			$(SRC_DIR)/menu/menu.c			\
			$(SRC_DIR)/menu/detection.c		\
			$(SRC_DIR)/menu/infos.c			\
			$(SRC_DIR)/menu/pause.c			\
			$(SRC_DIR)/food/create_food.c		\
			$(SRC_DIR)/food/rect_food.c		\
			$(SRC_DIR)/food/food.c			\
			$(SRC_DIR)/food/recipes.c		\
			$(SRC_DIR)/food/check_food.c		\
			$(SRC_DIR)/textures/create_background.c	\
			$(SRC_DIR)/textures/create_customer.c	\
			$(SRC_DIR)/textures/tab.c		\
			$(SRC_DIR)/play/hud.c			\
			$(SRC_DIR)/play/draw_client.c		\
			$(SRC_DIR)/play/book.c			\
			$(SRC_DIR)/play/carpet.c		\
			$(SRC_DIR)/play/phone.c			\

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my re
	make -C lib/clist re
	make -C lib/my_getopt re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	make -C lib/clist clean
	make -C lib/my_getopt clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/clist fclean
	make -C lib/my_getopt fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
