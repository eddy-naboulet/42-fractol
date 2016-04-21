/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:48:54 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/21 14:49:01 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fctl		*ft_restart_image(t_fctl *fctl)
{
	mlx_destroy_image(fctl->use->mlx, fctl->use->img);
	fctl->use->img = mlx_new_image(fctl->use->mlx, 800, 800);
	fctl->use->data = mlx_get_data_addr(fctl->use->img, &fctl->use->bpp, &fctl->use->sizeline, &fctl->use->endian);
	ft_select_2(fctl);
	//printf("lol = %f\n", fctl->x1);
	mlx_put_image_to_window(fctl->use->mlx, fctl->use->win, fctl->use->img, 0, 0);
	return (0);
}

t_fctl		*ft_draw_image(t_fctl *fctl)
{
	fctl->use->img = mlx_new_image(fctl->use->mlx, 800, 800);
	fctl->use->data = mlx_get_data_addr(fctl->use->img, &fctl->use->bpp, &fctl->use->sizeline, &fctl->use->endian);
	ft_select_2(fctl);
	mlx_put_image_to_window(fctl->use->mlx, fctl->use->win, fctl->use->img, 0, 0);
	return (0);
}

void   ft_put_pixel(t_fctl *fctl, double x, double y)
{
	int 	index;

	index = x * fctl->use->bpp / 8 + (y * fctl->use->sizeline);
	if (fctl->i == fctl->imax)
	{
		fctl->use->data[index] = 255;
		fctl->use->data[index + 1] = 255;
		fctl->use->data[index + 2] = 255;
	}
	else
	{
		fctl->use->data[index] = fctl->i * 625 / fctl->imax;
		fctl->use->data[index + 1] = fctl->i * 55 / fctl->imax;
		fctl->use->data[index + 2] = fctl->i * 255 / fctl->imax;
	}
}
