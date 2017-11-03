# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/01 17:26:35 by dsoloshe          #+#    #+#              #
#    Updated: 2017/09/01 17:26:37 by dsoloshe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = 	Resources/launcher.c \
		Resources/add_funcs.c \
		Resources/raytracing.c \
		Resources/objects_intersections.c \
		Resources/shadow_intersections.c \
		Resources/key_hooks.c \
		Resources/vector_operations_part1.c \
		Resources/vector_operations_part2.c \
		Resources/scenes_part1.c \
		Resources/scenes_part2.c \
		Resources/scenes_part3.c \
		Resources/scenes_part4.c \

OBJ = 	Resources/launcher.o \
		Resources/add_funcs.o \
		Resources/raytracing.o \
		Resources/objects_intersections.o \
		Resources/shadow_intersections.o \
		Resources/key_hooks.o \
		Resources/vector_operations_part1.o \
		Resources/vector_operations_part2.o \
		Resources/scenes_part1.o \
		Resources/scenes_part2.o \
		Resources/scenes_part3.o \
		Resources/scenes_part4.o \

FLAGS = -Wall -Wextra -Werror
HEADERS = Libs

LIBCOMP = cd Libs/libft && make && cd ..
LIBCLEAN = cd Libs/libft && make clean && cd ..
LIBFCLEAN = cd Libs/libft && make fclean && cd ..

MLGCC = gcc -o RTv1 -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(LIBCOMP)
	$(MLGCC) $(FLAGS) $(SRC) Libs/libft/libft.a Libs/minilibx/libmlx.a
	@echo "\n$(NAME) WAS SUCCESSFULLY COMPILED."
	@echo "\nUSAGE:\n1 - 1 sphere \n2 - 1 cylinder \n3 - 2 planes, 2 spheres and 1 cone"
	@echo "4 - 2 planes and 3 spheres \n5 - 3 planes, 2 spheres, 2 cylinders, 1 cone"

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
