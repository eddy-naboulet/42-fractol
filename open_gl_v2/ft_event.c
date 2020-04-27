/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:14:29 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/22 10:14:42 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_funct(int x, int y, void *param)
{
	t_fctl	*fctl;

	fctl = malloc(sizeof(t_fctl));
	fctl = param;
	if (fctl->pause == 0)
	{
		if (x > 0 && y > 0 && x <= 800 && y <= 800)
		{
			fctl->tmp_r = (double)(x - 500) / 500;
			fctl->tmp_i = (double)(y - 500) / 500;
		}
		ft_restart_image(fctl);
	}
	return (0);
}

int 	ft_mouse_zoom(t_fctl *fctl, int button)
{
	if (button == 5)
	{
		fctl->zoom_x *= 2;
		fctl->zoom_y *= 2;
		fctl->imax += 5;
	}
	if (button == 4)
	{
		fctl->zoom_x /= 2;
		fctl->zoom_y /= 2;
		fctl->imax -= 5;
	}
	return (0);
}

int		ft_test_zoom(int button, int x, int y, void *param)
{
	t_fctl	*fctl;
	double		z_x;
	double		z_y;

	fctl = param;
	z_x = fctl->zoom_x;
	z_y = fctl->zoom_y;
	ft_mouse_zoom(fctl, button);
	fctl->x1 += x / z_x - (x / fctl->zoom_x);
	fctl->y1 += y / z_y - (y / fctl->zoom_y);
	ft_restart_image(fctl);
	return (0);
}

int 	ft_key_move(int keycode, t_fctl *fctl)
{
	if (keycode == 49)
		fctl->pause = fctl->pause ^ 1;
	if (keycode == 15)
	{
		fctl->init_fractal = 0;
		ft_select_2(fctl);
		ft_restart_image(fctl);
	}
	if (keycode == 53)
		exit(1);
	return (0);
}
