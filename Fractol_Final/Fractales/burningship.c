/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:55:46 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/09 09:41:21 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Src/fractol.h"

t_fctl		*init_burningship(t_fctl *fctl)
{
	fctl->x1 = -2.1;
	fctl->x2 = 0.6;
	fctl->y1 = -1.2;
	fctl->y2 = 1.2;
	fctl->image_x = fctl->window_size;
	fctl->image_y = fctl->window_size;
	fctl->zoom_x = fctl->image_x / (fctl->x2 - fctl->x1);
	fctl->zoom_y = fctl->image_y / (fctl->y2 - fctl->y1);
	fctl->imax = 30;
	fctl->tmp_r = 0;
	fctl->tmp_i = 0;
	fctl->x = -1;
	fctl->c_r = 0;
	fctl->c_i = 0;
	fctl->z_r = 0;
	fctl->z_i = 0;
	fctl->color_value_1 = 127;
	fctl->color_value_2 = 128;
	return (fctl);
}

void		ft_burningship_init(t_fctl *fctl)
{
	double	tmp;

	tmp = fabs(fctl->z_r * fctl->z_i);
	fctl->z_r = fctl->z_r * fctl->z_r - fctl->z_i * fctl->z_i + fctl->c_r;
	fctl->z_i = tmp + tmp + fctl->c_i;
}

void		ft_burningship(t_fctl *fctl)
{
	double	x;
	double	y;

	x = -1;
	while (++x < fctl->image_x)
	{
		y = -1;
		while (++y < fctl->image_y)
		{
			fctl->c_r = x / fctl->zoom_x + fctl->x1;
			fctl->c_i = y / fctl->zoom_y + fctl->y1;
			fctl->z_r = fctl->tmp_r;
			fctl->z_i = fctl->tmp_i;
			fctl->i = 0;
			while (fctl->z_r * fctl->z_r + fctl->z_i * fctl->z_i < 4
				&& fctl->i < fctl->imax)
			{
				ft_burningship_init(fctl);
				fctl->i++;
				ft_put_pixel(fctl, x, y);
			}
		}
	}
}
