# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enaboule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/27 09:50:04 by enaboule          #+#    #+#              #
#    Updated: 2016/04/27 09:50:06 by enaboule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c Fractales/julia.c ft_draw_image.c ft_event.c fractol.c Fractales/pointed.c\
Fractales/mandelbrot.c Fractales/choux.c Fractales/robot.c Fractales/hum.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FW = -lmlx -framework OpenGL -framework AppKit

LIB =  -L/usr/local/lib/ libft/libft.a


all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) $(LIB) -I/usr/local/include $(FW) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
