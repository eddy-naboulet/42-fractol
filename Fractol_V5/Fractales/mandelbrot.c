/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:37:19 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/05 17:36:19 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_fctl		*init_mandelbrot(t_fctl *fctl)
{

	fctl->x1 = -2.1;
	fctl->x2 = 0.6;
	fctl->y1 = -1.2;
	fctl->y2 = 1.2;
	fctl->image_x = 1024;
	fctl->image_y = 1024;
	fctl->zoom_x = fctl->image_x / (fctl->x2 - fctl->x1);
	fctl->zoom_y = fctl->image_y / (fctl->y2 - fctl->y1);
	fctl->imax = 30;
	fctl->tmp_r = 0;
	fctl->tmp_i = 0;
	fctl->x = 0;
	fctl->y = 0;
	fctl->c_r = 0;
	fctl->c_i = 0;
	fctl->z_r = 0;
	fctl->z_i = 0;
	fctl->color_value_1 = 127;
	fctl->color_value_2 = 128;
	fctl->x_save = 0;
	fctl->y_save = 0;
	return (fctl);
}

void 		ft_mandelbrot(t_fctl *fctl)
{
	double x;
	double y;
	double tmp;

	x = -1;
	while (++x < fctl->image_x)
	{
		y = -1;
		while (++y < fctl->image_y)
		{
			fctl->c_r = fctl->x_save + (x - fctl->x) / fctl->zoom_x;//x / fctl->zoom_x + fctl->x1;
			fctl->c_i = fctl->y_save + (y - fctl->y) / fctl->zoom_y;//y / fctl->zoom_y + fctl->y1;
			fctl->z_r = fctl->tmp_r;
			fctl->z_i = fctl->tmp_i;
			fctl->i = 0;
			while (fctl->z_r * fctl->z_r + fctl->z_i * fctl->z_i < 4 && fctl->i < fctl->imax)
			{
				tmp = fctl->z_r;
				fctl->z_r = fctl->z_r * fctl->z_r - fctl->z_i * fctl->z_i + fctl->c_r;
				fctl->z_i = 2 * fctl->z_i * tmp + fctl->c_i;
				fctl->i++;
				ft_put_pixel(fctl, x, y);
			}
		}
	}
}
