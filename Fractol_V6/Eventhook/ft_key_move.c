/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:00:27 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 14:53:51 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Src/fractol.h"

int		ft_select_key_move(int keycode, t_fctl *fctl)
{
	ft_utils(keycode, fctl);
	return (0);
}

int		ft_key_zoom(int keycode, t_fctl *fctl)
{
	if (keycode == 116)
	{
		fctl->zoom_x *= 1.5;
		fctl->zoom_y *= 1.5;
		fctl->imax += 5;
	}
	if (keycode == 121)
	{
		fctl->zoom_x /= 1.5;
		fctl->zoom_y /= 1.5;
		fctl->imax -= 5;
	}
	return (0);
}

int		ft_move_key(int keycode, t_fctl *fctl)
{
	if (keycode == 0)
		fctl->x1 += 5 / (fctl->zoom_x);
	if (keycode == 2)
		fctl->x1 -= 5 / (fctl->zoom_y);
	if (keycode == 1)
		fctl->y1 -= 5 / (fctl->zoom_x);
	if (keycode == 13)
		fctl->y1 += 5 / (fctl->zoom_y);
	ft_restart_image(fctl);
	return (0);
}

int		ft_utils(int keycode, t_fctl *fctl)
{
	ft_key_zoom(keycode, fctl);
	ft_move_key(keycode, fctl);
	if (keycode == 49)
		fctl->pause = fctl->pause ^ 1;
	if (keycode == 15)
	{
		fctl->init_fractal = 0;
		ft_select_all(fctl);
		ft_restart_image(fctl);
	}
	if (keycode == 53)
		exit(1);
	return (0);
}
