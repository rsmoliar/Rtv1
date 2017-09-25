# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 16:24:54 by rsmoliar          #+#    #+#              #
#    Updated: 2017/06/21 18:25:15 by rsmoliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = main.c\
	  utils.c\
	  vector_op.c\
	  color.c\
	  drawer.c\
	  light.c\
	  trace.c\
	  obj_works.c\
	  pixel_works.c\
	  vector_math.c\
	  hooks.c\
	  new_object.c\
	  scenes_base.c\
	  scenes_extended.c\
	  scenes_tool.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

MLX = ./lib/miniLibX/
MLX_LIB = $(addprefix $(MLX),mlx.a)
MLX_INC = -I ./lib/miniLibX
MLX_LINK = -L ./lib/miniLibX -l mlx -framework OpenGL -framework AppKit

LIBFT = ./lib/libft/
LIBFT_LIB = $(addprefix $(FT),libft.a)
LIBFT_INC = -I ./lib/libft
LIBFT_LINK = -L ./lib/libft -l ft

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

all: obj $(LIBFT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -I $(INCDIR) -o $@ -c $<

$(LIBFT_LIB):
	make -C $(LIBFT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LINK) $(LIBFT_LINK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
