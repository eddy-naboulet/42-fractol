/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:54:39 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/03 13:58:54 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	ft_select_fractal(char *argv, t_fctl *fctl)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_strcmp(&argv[i], "julia") == 0)
			fctl->fractal = 1;
		if (ft_strcmp(&argv[i], "mandelbrot") == 0)
			fctl->fractal = 2;
		if (ft_strcmp(&argv[i], "pointed") == 0)
			fctl->fractal = 3;
		if (ft_strcmp(&argv[i], "choux") == 0)
			fctl->fractal = 4;
		if (ft_strcmp(&argv[i], "robot") == 0)
			fctl->fractal = 5;
		if (ft_strcmp(&argv[i], "hum") == 0)
			fctl->fractal = 6;
		if (ft_strcmp(&argv[i], "burning") == 0)
			fctl->fractal = 7;
		i++;
	}
	return (0);
}

void	ft_select_2(t_fctl *fctl)
{
	if (fctl->fractal == 1)
	{
		if (fctl->init_fractal != 1)
			init_julia(fctl);
		ft_draw_cl(fctl, "Fractales/kernel/julia.cl");
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 2)
	{
		if (fctl->init_fractal != 1)
			init_mandelbrot(fctl);
		ft_draw_cl(fctl, "Fractales/kernel/mandelbrot.cl");
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 3)
	{
		if (fctl->init_fractal != 1)
			init_pointed(fctl);
		ft_draw_cl(fctl, "Fractales/kernel/pointed.cl");
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 4)
	{
		if (fctl->init_fractal != 1)
			init_choux(fctl);
		ft_draw_cl(fctl, "Fractales/kernel/choux.cl");
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 5)
	{
		if (fctl->init_fractal != 1)
			init_robot(fctl);
		ft_draw_cl(fctl, "Fractales/kernel/robot.cl");
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 6)
	{
		if (fctl->init_fractal != 1)
			init_hum(fctl);
		ft_draw_cl(fctl, "Fractales/kernel/hum.cl");
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 7)
	{
		if (fctl->init_fractal != 1)
			init_burningship(fctl);
		ft_draw_cl(fctl, "Fractales/kernel/burningship.cl");
		fctl->init_fractal = 1;
	}
}
