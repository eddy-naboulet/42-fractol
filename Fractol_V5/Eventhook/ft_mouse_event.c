/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:25:03 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/05 17:40:31 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_mouse_funct(int x, int y, void *param)
{
	t_fctl	*fctl;

	fctl = malloc(sizeof(t_fctl));
	fctl = param;
	if (fctl->pause == 0)
	{
		if (x > 0 && y > 0 && x <= 1024 && y <= 1024)
		{
			fctl->tmp_r = (double)(x - 512) / 512;
			fctl->tmp_i = (double)(y - 512) / 512;
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
	fctl->x_save = fctl->x_save + (x - fctl->x) / fctl->zoom_x;
	fctl->y_save = (fctl->y_save - y) / fctl->zoom_y;
	fctl->x1 += x / z_x - (x / fctl->zoom_x);
	fctl->y1 += y / z_y - (y / fctl->zoom_y);
	fctl->x = x;
	fctl->y = y;
	ft_restart_image(fctl);
	return (0);
}
