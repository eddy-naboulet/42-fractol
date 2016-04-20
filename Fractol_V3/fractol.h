/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:35:42 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/20 14:35:46 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define DEBUG printf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <openGL/gl.h>
#include <openGL/glu.h>
#include <glut/glut.h>

typedef struct		s_use
{
	void 			*mlx;
	void 			*win;
	void 			*img;
	int            	bpp;
	int            	sizeline;
	int             endian;
	char 			*data;
}					t_use;

typedef struct		s_fctl
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			image_x;
	double			image_y;
	double			zoom_x;
	double			zoom_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp_r;
	double			tmp_i;
	int 			x;
	int				y;
	int 			imax;
	int 			i;
	int 			pause;
	int				fractal;
	int 			init_fractal;
	t_use			*use;
}					t_fctl;

int 				ft_key_move(int keycode, t_fctl *fctl);
int					ft_test_zoom(int button, int x, int y, void *param);
int 				ft_mouse_zoom(t_fctl *fctl, int button);
int					ft_mouse_funct(int x, int y, void *param);
t_fctl				*init_mandelbrot(t_fctl *fctl);
void 				ft_mandelbrot(t_fctl *fctl);
t_fctl				*init_julia(t_fctl *fctl);
void 				ft_julia(t_fctl *fctl);
t_fctl				*init_pointed(t_fctl *fctl);
void 				ft_pointed(t_fctl *fctl);
t_fctl				*init_choux(t_fctl *fctl);
void 				ft_choux(t_fctl *fctl);
t_fctl				*init_robot(t_fctl *fctl);
void 				ft_robot(t_fctl *fctl);
t_fctl				*init_hum(t_fctl *fctl);
void 				ft_hum(t_fctl *fctl);
t_fctl				*ft_restart_image(t_fctl *fctl);
t_fctl				*ft_draw_image(t_fctl *fctl);
void   				ft_put_pixel(t_fctl *fctl, double x, double y);
int 				ft_select_fractal(char *argv, t_fctl *fctl);
void				ft_select_2(t_fctl *fctl);

#endif
