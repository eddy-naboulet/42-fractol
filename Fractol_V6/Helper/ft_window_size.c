/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:02:18 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 14:31:02 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Src/fractol.h"

void	ft_window_size(t_fctl *fctl)
{
	if (fctl->open_cl == 1)
	{
		fctl->window_size = 1024;
		fctl->window_name = "fractol OpenCl";
	}
	else
	{
		fctl->window_size = 600;
		fctl->window_name = "fractol";
	}
}
