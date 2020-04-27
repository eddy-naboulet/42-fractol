/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:48:54 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 14:54:14 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fctl		*ft_restart_image(t_fctl *fctl)
{
	mlx_destroy_image(fctl->use->mlx, fctl->use->img);
	fctl->use->img = mlx_new_image(fctl->use->mlx, fctl->window_size,
		fctl->window_size);
	fctl->use->data = mlx_get_data_addr(fctl->use->img, &fctl->use->bpp,
		&fctl->use->sizeline, &fctl->use->endian);
	ft_select_all(fctl);
	mlx_put_image_to_window(fctl->use->mlx, fctl->use->win, fctl->use->img,
		0, 0);
	return (0);
}

t_fctl		*ft_draw_image(t_fctl *fctl)
{
	fctl->use->img = mlx_new_image(fctl->use->mlx, fctl->window_size,
		fctl->window_size);
	fctl->use->data = mlx_get_data_addr(fctl->use->img, &fctl->use->bpp,
		&fctl->use->sizeline, &fctl->use->endian);
	ft_select_all(fctl);
	mlx_put_image_to_window(fctl->use->mlx, fctl->use->win, fctl->use->img,
		0, 0);
	return (0);
}

void		ft_put_pixel(t_fctl *fctl, double x, double y)
{
	int		index;

	index = x * fctl->use->bpp / 8 + (y * fctl->use->sizeline);
	if (fctl->i == fctl->imax)
	{
		fctl->use->data[index] = 0;
		fctl->use->data[index + 1] = 0;
		fctl->use->data[index + 2] = 0;
	}
	else
	{
		fctl->use->data[index] = fctl->i * 625 / fctl->imax;
		fctl->use->data[index + 1] = fctl->i * 55 / fctl->imax;
		fctl->use->data[index + 2] = fctl->i * 255 / fctl->imax;
	}
}
