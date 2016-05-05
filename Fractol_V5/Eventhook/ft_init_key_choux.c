/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_key_choux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:23:28 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/05 10:38:15 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int 	ft_select_key_choux(int keycode, t_fctl *fctl)
{
	ft_key_init_choux_1(keycode, fctl);
	ft_key_init_choux_2(keycode, fctl);
	ft_key_init_choux_3(keycode, fctl);
	return (0);
}

int		ft_key_init_choux_1(int keycode, t_fctl *fctl)
{
	if (keycode == 83)
	{
		fctl->tmp_r = -0.98;
		fctl->tmp_i = -0.99;
	}
	if (keycode == 84)
	{
		fctl->tmp_r = 0.64;
		fctl->tmp_i = -0.97;
	}
	if (keycode == 85)
	{
		fctl->tmp_r = -0.57;
		fctl->tmp_i = 0.15;
	}
	if (keycode == 86)
	{
		fctl->tmp_r = -0.35;
		fctl->tmp_i = 0.13;
	}
	ft_restart_image(fctl);
	return (0);
}

int		ft_key_init_choux_2(int keycode, t_fctl *fctl)
{
	if (keycode == 87)
	{
		fctl->tmp_r = -0.54;
		fctl->tmp_i = 0.08;
	}
	if (keycode == 88)
	{
		fctl->tmp_r = 0.39;
		fctl->tmp_i = -0.56;
	}
	if (keycode == 89)
	{
		fctl->tmp_r = -0.13;
		fctl->tmp_i = 0.25;
	}
	if (keycode == 91)
	{
		fctl->tmp_r = 0.46;
		fctl->tmp_i = 0.25;
	}
	ft_restart_image(fctl);
	return (0);
}

int 	ft_key_init_choux_3(int keycode, t_fctl *fctl)
{
	if (keycode == 92)
	{
		fctl->tmp_r = 0.34;
		fctl->tmp_i = -0.55;
	}
	ft_restart_image(fctl);
	return (0);
}
