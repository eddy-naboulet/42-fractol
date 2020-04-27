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

HDRDIR = header
SRCDIR = src
CUDASRC = cudasrc
CUDAHDR = cudaheader

CSRC =  $(CUDASRC)/cuda.cu \
                $(CUDASRC)/juliacu.cu \
                $(CUDASRC)/mandelbrotcu.cu \
                $(CUDASRC)/newtoncu.cu

COBJ =  cuda.o \
                juliacu.o\
                mandelbrotcu.o \
                newtoncu.o

SOURCE =        $(SRCDIR)/fractol.c \
                        $(SRCDIR)/print.c \
                        $(SRCDIR)/attr.c \
                        $(SRCDIR)/attr_helper.c \
                        $(SRCDIR)/ft_atoid.c \
                        $(SRCDIR)/env.c \
                        $(SRCDIR)/draw.c \
                        $(SRCDIR)/mandelbrot.c \
                        $(SRCDIR)/julia.c \
                        $(SRCDIR)/newton.c \
                        $(SRCDIR)/bind_key_1.c \
                        $(SRCDIR)/bind_key_2.c \
                        $(SRCDIR)/bind_mouse.c \
                        $(SRCDIR)/check_value.c \
                        $(SRCDIR)/display_info.c \
                        $(SRCDIR)/newton_cu.c \


OBJ =   fractol.o \
                print.o \
                attr.o \
                attr_helper.o \
                ft_atoid.o \
                env.o \
                draw.o \
                mandelbrot.o \
                julia.o \
                newton.o \
                bind_key_1.o \
                bind_key_2.o \
                bind_mouse.o \
                check_value.o \
                display_info.o \
                newton_cu.o

FLAGS = -Wall -Werror -Wextra -iquote header -framework OpenGL -framework AppKit -I/usr/X11/include

LIBFTDIR = libft/
LIBFT =  $(LIBFTDIR)libft.a

MLXDIR = minilibx_macos/
MLXLIB = $(MLXDIR)libmlx.a
LIB = -L/usr/X11/lib -lmlx -lXext -lX11

CUDA=/Developer/NVIDIA/CUDA-5.5
NVCC=/Developer/NVIDIA/CUDA-5.5/bin/nvcc
NVCC_C = -ccbin /usr/bin/clang -m64
NVCC_FRAMEWORK = -Xlinker -framework,OpenGL -Xlinker -framework,AppKit
NVCC_LIB = -Xlinker -rpath -Xlinker /Developer/NVIDIA/CUDA-5.5/lib
NVCC_ARCH = -Xcompiler -arch -Xcompiler x86_64
NVCC_STD = -Xcompiler -stdlib=libstdc++
NVCC_VCODE = -gencode arch=compute_10,code=sm_10 -gencode arch=compute_20,code=sm_20 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=\"sm_35,compute_35\"
NVCC_FLAGS = -Xcompiler -Werror -Xcompiler -Wall -Xcompiler -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(MLXLIB) $(OBJ) $(COBJ)
        $(NVCC) $(NVCC_C) $(NVCC_ARCH) $(NVCC_STD) $(NVCC_FRAMEWORK) $(NVCC_LIB) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(LIB) $(COBJ)

$(LIBFT):
        make -C $(LIBFTDIR)

$(COBJ):
        $(NVCC) $(NVCC_C) $(NVCC_ARCH) $(NVCC_STD) $(NVCC_VCODE) $(NVCC_FLAGS) -I $(CUDA)/include -I header -I $(CUDAHDR) -c $(CSRC)

$(MLXLIB):
        make -C $(MLXDIR)

$(OBJ):
        gcc $(FLAGS) -iquote $(LIBFTDIR) -I $(MLXDIR) -iquote $(CUDAHDR) -c $(SOURCE)

clean:
        rm -f $(OBJ) $(COBJ)

fclean: clean
        rm -f $(NAME)

re: fclean all
