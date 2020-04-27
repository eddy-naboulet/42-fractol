/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 12:17:53 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 14:46:57 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_select_draw_1(t_fctl *fctl)
{
	if (fctl->fractal == 1)
	{
		if (fctl->init_fractal != 1)
			init_julia(fctl);
		if (fctl->open_cl == 1)
			ft_draw_cl(fctl, "Fractales/kernel/julia.cl");
		else
			ft_julia(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 2)
	{
		if (fctl->init_fractal != 1)
			init_mandelbrot(fctl);
		if (fctl->open_cl == 1)
			ft_draw_cl(fctl, "Fractales/kernel/mandelbrot.cl");
		else
			ft_mandelbrot(fctl);
		fctl->init_fractal = 1;
	}
}

void	ft_select_draw_2(t_fctl *fctl)
{
	if (fctl->fractal == 3)
	{
		if (fctl->init_fractal != 1)
			init_pointed(fctl);
		if (fctl->open_cl == 1)
			ft_draw_cl(fctl, "Fractales/kernel/pointed.cl");
		else
			ft_pointed(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 4)
	{
		if (fctl->init_fractal != 1)
			init_choux(fctl);
		if (fctl->open_cl == 1)
			ft_draw_cl(fctl, "Fractales/kernel/choux.cl");
		else
			ft_choux(fctl);
		fctl->init_fractal = 1;
	}
}

void	ft_select_draw_3(t_fctl *fctl)
{
	if (fctl->fractal == 5)
	{
		if (fctl->init_fractal != 1)
			init_robot(fctl);
		if (fctl->open_cl == 1)
			ft_draw_cl(fctl, "Fractales/kernel/robot.cl");
		else
			ft_robot(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 6)
	{
		if (fctl->init_fractal != 1)
			init_hum(fctl);
		if (fctl->open_cl == 1)
			ft_draw_cl(fctl, "Fractales/kernel/hum.cl");
		else
			ft_hum(fctl);
		fctl->init_fractal = 1;
	}
}

void	ft_select_draw_4(t_fctl *fctl)
{
	if (fctl->fractal == 7)
	{
		if (fctl->init_fractal != 1)
			init_burningship(fctl);
		if (fctl->open_cl == 1)
			ft_draw_cl(fctl, "Fractales/kernel/burningship.cl");
		else
			ft_burningship(fctl);
		fctl->init_fractal = 1;
	}
}
