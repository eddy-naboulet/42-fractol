/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:54:39 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/22 14:54:41 by enaboule         ###   ########.fr       */
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
		ft_julia(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 2)
	{
		if (fctl->init_fractal != 1)
			init_mandelbrot(fctl);
		ft_mandelbrot(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 3)
	{
		if (fctl->init_fractal != 1)
			init_pointed(fctl);
		ft_pointed(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 4)
	{
		if (fctl->init_fractal != 1)
			init_choux(fctl);
		ft_choux(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 5)
	{
		if (fctl->init_fractal != 1)
			init_robot(fctl);
		ft_robot(fctl);
		fctl->init_fractal = 1;
	}
	if (fctl->fractal == 6)
	{
		if (fctl->init_fractal != 1)
			init_hum(fctl);
		ft_hum(fctl);
		fctl->init_fractal = 1;
	}
}
