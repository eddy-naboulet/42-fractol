/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_key_robot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:23:28 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/05 10:50:48 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int 	ft_select_key_robot(int keycode, t_fctl *fctl)
{
	ft_key_init_robot_1(keycode, fctl);
	ft_key_init_robot_2(keycode, fctl);
	ft_key_init_robot_3(keycode, fctl);
	return (0);
}


int		ft_key_init_robot_1(int keycode, t_fctl *fctl)
{
	if (keycode == 83)
	{
		fctl->tmp_r = 0.55;
		fctl->tmp_i = -0.84;
	}
	if (keycode == 84)
	{
		fctl->tmp_r = -0.11;
		fctl->tmp_i = 0.24;
	}
	if (keycode == 85)
	{
		fctl->tmp_r = 0.59;
		fctl->tmp_i = -0.93;
	}
	if (keycode == 86)
	{
		fctl->tmp_r = -0.56;
		fctl->tmp_i = 0.08;
	}
	ft_restart_image(fctl);
	return (0);
}

int		ft_key_init_robot_2(int keycode, t_fctl *fctl)
{
	if (keycode == 87)
	{
		fctl->tmp_r = 0.25;
		fctl->tmp_i = -0.10;
	}
	if (keycode == 88)
	{
		fctl->tmp_r = -0.45;
		fctl->tmp_i = 0.09;
	}
	if (keycode == 89)
	{
		fctl->tmp_r = -0.39;
		fctl->tmp_i = 0.17;
	}
	if (keycode == 91)
	{
		fctl->tmp_r = -0.19;
		fctl->tmp_i = 0.18;
	}
	ft_restart_image(fctl);
	return (0);
}

int 	ft_key_init_robot_3(int keycode, t_fctl *fctl)
{
	if (keycode == 92)
	{
		fctl->tmp_r = -0.26;
		fctl->tmp_i = -0.15;
	}
	ft_restart_image(fctl);
	return (0);
}
