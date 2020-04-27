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
#include <stdio.h>

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
	double			tmp;
	int 			x;
	int				y;
	int 			imax;
	int 			i;
	//double			tmp_c_r;
	//double			tmp_c_i;
}					t_fctl;

typedef struct		s_use
{
	void 			*mlx;
	void 			*win;
	void 			*img;
	int            	bpp;
	int            	sizeline;
	int             endian;
	char 			*data;
	//t_fctl			*fctl;
}					t_use;

int					ft_mouse_funct(int x, int y, void *param, t_fctl *fctl, t_use *use);
t_fctl				*init_mandelbrot(t_fctl *fctl);
void 				ft_mandelbrot(t_fctl *fctl, t_use *use);
t_fctl				*init_julia(t_fctl *fctl);
void 				ft_julia(t_fctl *fctl, t_use *use);
t_fctl				*ft_draw_image(t_fctl *fctl, t_use *use);
t_fctl				*ft_draw_image_2(t_fctl *fctl, t_use *use);
void   				ft_put_pixel(t_fctl *fctl, t_use *use);


#endif
