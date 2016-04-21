/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:21:09 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/21 11:21:11 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fctl		*init_pointed(t_fctl *fctl)
{
	fctl->x1 = -1.5;
	fctl->x2 = 1.5;
	fctl->y1 = -1.2;
	fctl->y2 = 1.2;
	fctl->image_x = 800;
	fctl->image_y = 800;
	fctl->zoom_x = fctl->image_x / (fctl->x2 - fctl->x1);
	fctl->zoom_y = fctl->image_y / (fctl->y2 - fctl->y1);
	fctl->imax = 50;
	fctl->tmp_r = -0.8;
	fctl->tmp_i = -0.4;
	fctl->c_r = 0;
	fctl->c_i = 0;
	fctl->z_r = 0;
	fctl->z_i = 0;
	return (fctl);
}

void 		ft_pointed(t_fctl *fctl)
{
	double	x;
	double	y;
	double	tmp;

	x = -1;
	while (++x < fctl->image_x)
	{
		y = -1;
		while (++y < fctl->image_y)
		{
			fctl->c_r = fctl->tmp_r;
			fctl->c_i = fctl->tmp_i;
			fctl->z_r = x / fctl->zoom_x + fctl->x1;
			fctl->z_i = y / fctl->zoom_y + fctl->y1;;
			fctl->i = 0;
			while (fctl->z_r * fctl->z_r + fctl->z_i * fctl->z_i < 4 && fctl->i < fctl->imax)
			{
				tmp = fctl->z_r * 4 / 2;
				fctl->z_r = fctl->z_r * fctl->z_r - fctl->z_i * fctl->z_i + fctl->c_r;
				fctl->z_i = 2 * fctl->z_i * tmp + fctl->c_i;
				fctl->i++;
				ft_put_pixel(fctl, x, y);
			}
		}
	}
}
