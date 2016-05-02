# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/27 09:50:04 by enaboule          #+#    #+#              #
#    Updated: 2016/05/02 17:56:20 by enaboule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c Fractales/julia.c ft_draw_image.c ft_event.c fractol.c Fractales/pointed.c\
Fractales/mandelbrot.c Fractales/choux.c Fractales/robot.c Fractales/hum.c\
ft_mandelbrot_cl.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FW = -lmlx -framework OpenGL -framework AppKit -framework OpenCL

LIB =  -L/usr/local/lib/ libft/libft.a


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(LIB) -I/usr/local/include $(FW) $(OBJ) -o $(NAME)

%.o:%.c
	gcc -c $< -o $@ $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
