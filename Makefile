# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnaour <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/23 00:35:29 by cnaour            #+#    #+#              #
#    Updated: 2019/11/28 17:20:35 by cnaour           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = fractol.h
mlx1 =  -lmlx -framework OpenGL -framework AppKit
OBJ = feigenbaum.o color.o ft_strcmp.o limits.o menu.o thread.o	key_hook2.o\
	  fractal_chosing.o julia.o main.o mouse_hook.o tricorn.o burning_julia.o\
	  burningship.o key_hook.o mandelbrot.o tear_drop.o gradian.o
CFLAGS = -Wall -Werror -Wextra 
CC = gcc
NAME = fractol

all : $(NAME)
%.o : %.c $(INC)
	$(CC) $(FLAGS) -c -o $@ $<
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(mlx1) -o $(NAME) -I $(INC)
	@printf "\033[32mcompilation done\n\033[0m"

clean :
	@rm -f $(OBJ)
	@printf "\033[33mobjects removed\n\033[0m"

fclean : clean
	@rm -f $(NAME)
	@printf "\033[31mbinary file removed\n\033[0m"

re : fclean all
