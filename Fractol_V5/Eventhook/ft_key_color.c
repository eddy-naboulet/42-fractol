/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:56:07 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/04 18:22:10 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int 	ft_select_key_color(int keycode, t_fctl *fctl)
{
	ft_color_profil_1(keycode, fctl);
	ft_color_profil_2(keycode, fctl);
	ft_color_psy(keycode, fctl);
	return (0);
}

int		ft_color_profil_1(int keycode, t_fctl *fctl)
{
	if (keycode == 18)
	{
		fctl->get_color_r = 0;
		fctl->get_color_g = 2;
		fctl->get_color_b = 4;
	}
	if (keycode == 19)
	{
		fctl->get_color_r = 2;
		fctl->get_color_g = 2;
		fctl->get_color_b = 4;
	}
	if (keycode == 20)
	{
		fctl->get_color_r = 4;
		fctl->get_color_g = 4;
		fctl->get_color_b = 4;
	}
	ft_restart_image(fctl);
	return (0);
}

int 	ft_color_profil_2(int keycode, t_fctl *fctl)
{
	if (keycode == 21)
	{
		fctl->get_color_r = 5;
		fctl->get_color_g = 2;
		fctl->get_color_b = 5;
	}
	if (keycode == 23)
	{
		fctl->get_color_r = 6;
		fctl->get_color_g = 5;
		fctl->get_color_b = 4;
	}
	ft_restart_image(fctl);
	return (0);
}

int		ft_color_psy(int keycode, t_fctl *fctl)
{
	if (keycode == 50)
	{
		fctl->color_value_1 = fctl->color_value_1 ^ 800;
		fctl->color_value_2 = fctl->color_value_2 ^ 800;
		ft_restart_image(fctl);
	}
	return (0);
}
