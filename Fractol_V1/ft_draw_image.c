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
#include <stdio.h>

t_fctl		*ft_draw_image(t_fctl *fctl, t_use *use)
{
	DEBUG
	mlx_destroy_image(use->mlx, use->img);
	DEBUG
	use->img = mlx_new_image(use->mlx, 800, 800);
	DEBUG
	use->data = mlx_get_data_addr(use->img, &use->bpp, &use->sizeline, &use->endian);
	DEBUG
	ft_julia(fctl, use);
	DEBUG
	mlx_put_image_to_window(use->mlx, use->win, use->img, 0, 0);
	DEBUG
	printf("ft_draw_image = %p\n", use->data);
	return (0);
}

t_fctl		*ft_draw_image_2(t_fctl *fctl, t_use *use)
{
	use->img = mlx_new_image(use->mlx, 800, 800);
	use->data = mlx_get_data_addr(use->img, &use->bpp, &use->sizeline, &use->endian);
	init_julia(fctl);
	ft_julia(fctl, use);
	mlx_put_image_to_window(use->mlx, use->win, use->img, 0, 0);
	printf("ft_draw_image_2 = %p\n", use->data);
	return (0);
}

void   ft_put_pixel(t_fctl *fctl, t_use *use)
{
	int 	index;

	index = fctl->x * use->bpp / 8 + (fctl->y * use->sizeline);
	if (fctl->i == fctl->imax)
	{
		use->data[index] = 255;
		use->data[index + 1] = 255;
		use->data[index + 2] = 255;
	}
	else
	{
		use->data[index] = fctl->i * 625 / fctl->imax;
		use->data[index + 1] = fctl->i * 55 / fctl->imax;
		use->data[index + 2] = fctl->i * 255 / fctl->imax;
	}
}
