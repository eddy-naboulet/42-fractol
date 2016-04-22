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

int		ft_mouse_funct(int x, int y, void *param, t_fctl *fctl, t_use *use)
{
	//t_fctl	*fctl;
	//t_use	*use;

	x = 1;
	y = 1;
	use = param;
	//fctl = use->fctl;
	DEBUG
	//if (x > 0 && y > 0 && x <= 800 && y <= 800)
	//{
	/*use->*/fctl->tmp_r = (double)(x - 500) / 500;
	DEBUG
	/*use->*/fctl->tmp_i = (double)(y - 500) / 500;
	//}
	DEBUG
	ft_draw_image(fctl, use);
	DEBUG
	return (0);
}
