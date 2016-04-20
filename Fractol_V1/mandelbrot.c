/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:37:19 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/20 16:37:22 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fctl		*init_mandelbrot(t_fctl *fctl)
{

	fctl->x1 = -2.1;
	fctl->x2 = 0.6;
	fctl->y1 = -1.2;
	fctl->y2 = 1.2;
	fctl->image_x = 800;
	fctl->image_y = 800;
	fctl->zoom_x = fctl->image_x / (fctl->x2 - fctl->x1);
	fctl->zoom_y = fctl->image_y / (fctl->y2 - fctl->y1);
	fctl->imax = 50;
	fctl->tmp_r = 0;
	fctl->tmp_i = 0;
	fctl->x = -1;
	return (fctl);
}

void 		ft_mandelbrot(t_fctl *fctl, t_use *use)
{
	while (++fctl->x < fctl->image_x)
	{
		fctl->y = -1;
		while (++fctl->y < fctl->image_y)
		{
			fctl->c_r = fctl->x / fctl->zoom_x + fctl->x1;
			fctl->c_i = fctl->y / fctl->zoom_y + fctl->y1;
			fctl->z_r = 0;
			fctl->z_i = 0;
			fctl->i = 0;
			while (fctl->z_r * fctl->z_r + fctl->z_i * fctl->z_i < 4 && fctl->i < fctl->imax)
			{
				fctl->tmp = fctl->z_r;
				fctl->z_r = fctl->z_r * fctl->z_r - fctl->z_i * fctl->z_i + fctl->c_r;
				fctl->z_i = 2 * fctl->z_i * fctl->tmp + fctl->c_i;
				fctl->i++;
				ft_put_pixel(fctl, use);
			}
		}
	}
}
