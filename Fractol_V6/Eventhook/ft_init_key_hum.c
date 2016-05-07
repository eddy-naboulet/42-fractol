/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_key_hum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:23:28 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 12:50:03 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Src/fractol.h"

int		ft_select_key_hum(int keycode, t_fctl *fctl)
{
	ft_key_init_hum_1(keycode, fctl);
	ft_key_init_hum_2(keycode, fctl);
	ft_key_init_hum_3(keycode, fctl);
	return (0);
}

int		ft_key_init_hum_1(int keycode, t_fctl *fctl)
{
	if (keycode == 83)
	{
		fctl->tmp_r = 0.32;
		fctl->tmp_i = -0.86;
	}
	if (keycode == 84)
	{
		fctl->tmp_r = 0.26;
		fctl->tmp_i = -0.17;
	}
	if (keycode == 85)
	{
		fctl->tmp_r = -0.99;
		fctl->tmp_i = 0.27;
	}
	if (keycode == 86)
	{
		fctl->tmp_r = 0.46;
		fctl->tmp_i = -0.96;
	}
	ft_restart_image(fctl);
	return (0);
}

int		ft_key_init_hum_2(int keycode, t_fctl *fctl)
{
	if (keycode == 87)
	{
		fctl->tmp_r = 0.24;
		fctl->tmp_i = 0.60;
	}
	if (keycode == 88)
	{
		fctl->tmp_r = -0.73;
		fctl->tmp_i = 0.85;
	}
	if (keycode == 89)
	{
		fctl->tmp_r = 0.28;
		fctl->tmp_i = 0.49;
	}
	if (keycode == 91)
	{
		fctl->tmp_r = 0.65;
		fctl->tmp_i = -0.98;
	}
	ft_restart_image(fctl);
	return (0);
}

int		ft_key_init_hum_3(int keycode, t_fctl *fctl)
{
	if (keycode == 92)
	{
		fctl->tmp_r = 0.30;
		fctl->tmp_i = -0.75;
	}
	ft_restart_image(fctl);
	return (0);
}
