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

t_fctl		*init_julia(t_fctl *fctl)
{
	fctl->x1 = -1.5;
	fctl->x2 = 1.5;
	fctl->y1 = -1.2;
	fctl->y2 = 1.2;
	fctl->image_x = 800;
	fctl->image_y = 800;
	fctl->zoom_x = fctl->image_x / (fctl->x2 - fctl->x1);
	fctl->zoom_y = fctl->image_y / (fctl->y2 - fctl->y1);
	fctl->imax = 150;
	fctl->tmp_r = -0.8;
	fctl->tmp_i = 0.4;
	fctl->x = -1;
	fctl->i = 0;
	fctl->c_r = 0;
	fctl->c_i = 0;
	fctl->z_r = 0;
	fctl->z_i = 0;
	//fctl->tmp_c_r = 0;
	//fctl->tmp_c_i = 0;
	return (fctl);
}

void 		ft_julia(t_fctl *fctl, t_use *use)
{
	//fctl->tmp_c_r = -0.6;
	//fctl->tmp_c_i = 0.6;
	DEBUG
	while (++fctl->x < fctl->image_x)
	{
		fctl->y = -1;
		while (++fctl->y < fctl->image_y)
		{
			fctl->c_r = fctl->tmp_r;//-0.39;//0.285; +i tmp_c_r
			fctl->c_i = fctl->tmp_i;//0.6;//0.01; tmp_c_i
			fctl->z_r = fctl->x / fctl->zoom_x + fctl->x1;
			fctl->z_i = fctl->y / fctl->zoom_y + fctl->y1;;
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
