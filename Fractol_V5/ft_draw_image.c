/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:48:54 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/03 17:17:01 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fctl		*ft_restart_image(t_fctl *fctl)
{
	mlx_destroy_image(fctl->use->mlx, fctl->use->img);
	fctl->use->img = mlx_new_image(fctl->use->mlx, 1024, 1024);
	fctl->use->data = mlx_get_data_addr(fctl->use->img, &fctl->use->bpp, &fctl->use->sizeline, &fctl->use->endian);
	ft_select_2(fctl);
	mlx_put_image_to_window(fctl->use->mlx, fctl->use->win, fctl->use->img, 0, 0);
	return (0);
}

t_fctl		*ft_draw_image(t_fctl *fctl)
{
	fctl->use->img = mlx_new_image(fctl->use->mlx, 1024, 1024);
	fctl->use->data = mlx_get_data_addr(fctl->use->img, &fctl->use->bpp, &fctl->use->sizeline, &fctl->use->endian);
	ft_select_2(fctl);
	mlx_put_image_to_window(fctl->use->mlx, fctl->use->win, fctl->use->img, 0, 0);
	return (0);
}

void   ft_put_pixel(t_fctl *fctl, double x, double y)
{
	int 	index;
	double	ct_index;

	ct_index = fctl->i + 1 - 2 * log(2) / sqrt((fctl->z_r * fctl->z_r) + (fctl->z_i * fctl->z_i));
	index = x * fctl->use->bpp / 8 + (y * fctl->use->sizeline);
	if (fctl->i == fctl->imax)
	{
		fctl->use->data[index] = (sin(0.10 * ct_index + 0) * 50 + 200);//(sin(1.91 * ct_index + 10) * 230 + 25); // 50
		fctl->use->data[index + 1] = (sin(0.10 * ct_index + 2) * 50 + 200);//(sin(17.1 * ct_index + 10) * 230 + 25);
		fctl->use->data[index + 2] = (sin(0.10 * ct_index + 4) * 50 + 200);//(sin(1.1 * ct_index + 10) * 230 + 25);

	}
	else
	{
		fctl->use->data[index] = (sin(0.10 * ct_index + 0) * 50 + 200);// 50 + 200
		fctl->use->data[index + 1] = (sin(0.10 * ct_index + 2) * 50 + 200);
		fctl->use->data[index + 2] = (sin(0.10 * ct_index + 4) * 50 + 200);
	}
}
