/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_key_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:23:28 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/04 18:22:01 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int 	ft_select_key_julia(int keycode, t_fctl *fctl)
{
	ft_key_init_julia_1(keycode, fctl);
	ft_key_init_julia_2(keycode, fctl);
	ft_key_init_julia_3(keycode, fctl);
	return (0);
}

int		ft_key_init_julia_1(int keycode, t_fctl *fctl)
{
	if (keycode == 83)
	{
		fctl->tmp_r = -0.8;
		fctl->tmp_i = 0.4;
	}
	if (keycode == 84)
	{
		fctl->tmp_r = -0.8;
		fctl->tmp_i = 0.2;
	}
	if (keycode == 85)
	{
		fctl->tmp_r = -0.79;
		fctl->tmp_i = -0.14;
	}
	if (keycode == 86)
	{
		fctl->tmp_r = -1;
		fctl->tmp_i = 0.4;
	}
	ft_restart_image(fctl);
	return (0);
}

int		ft_key_init_julia_2(int keycode, t_fctl *fctl)
{
	if (keycode == 87)
	{
		fctl->tmp_r = 0.42;
		fctl->tmp_i = 0.13;
	}
	if (keycode == 88)
	{
		fctl->tmp_r = 0;
		fctl->tmp_i = 1;
	}
	if (keycode == 89)
	{
		fctl->tmp_r = -0.4;
		fctl->tmp_i = 0.8;
	}
	if (keycode == 91)
	{
		fctl->tmp_r = 0.19;
		fctl->tmp_i = 0.6;
	}
	ft_restart_image(fctl);
	return (0);
}

int 	ft_key_init_julia_3(int keycode, t_fctl *fctl)
{
	if (keycode == 92)
	{
		fctl->tmp_r = -0.6;
		fctl->tmp_i = 0.6;
	}
	ft_restart_image(fctl);
	return (0);
}
