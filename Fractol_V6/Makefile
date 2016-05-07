# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/27 09:50:04 by enaboule          #+#    #+#              #
#    Updated: 2016/05/07 10:58:43 by enaboule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = 			Src/main.c\
				Helper/ft_help.c\
				Helper/ft_window_size.c\
				Helper/ft_window_help.c\
				Src/ft_open_cl.c\
				Src/ft_draw_image.c\
				Src/ft_select_fract.c\
				Src/ft_select_draw.c\
				Fractales/burningship.c\
				Fractales/choux.c\
				Fractales/hum.c\
				Fractales/julia.c\
				Fractales/mandelbrot.c\
				Fractales/pointed.c\
				Fractales/robot.c\
				Eventhook/ft_init_event.c\
				Eventhook/ft_init_key_choux.c\
				Eventhook/ft_init_key_hum.c\
				Eventhook/ft_init_key_julia.c\
				Eventhook/ft_init_key_robot.c\
				Eventhook/ft_key_color.c\
				Eventhook/ft_key_move.c\
				Eventhook/ft_mouse_event.c\

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
