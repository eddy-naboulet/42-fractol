/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:47:13 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 17:23:15 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_select_all(t_fctl *fctl)
{
	if (fctl->fractal == 1 || fctl->fractal == 2)
		ft_select_draw_1(fctl);
	if (fctl->fractal == 3 || fctl->fractal == 4)
		ft_select_draw_2(fctl);
	if (fctl->fractal == 5 || fctl->fractal == 6)
		ft_select_draw_3(fctl);
	if (fctl->fractal == 7)
		ft_select_draw_4(fctl);
}

int		ft_select_open(char *argv, t_fctl *fctl)
{
	if (ft_strcmp(argv, "cl") == 0)
		fctl->open_cl = 1;
	else
	{
		fctl->open_cl = 0;
		ft_help();
	}
	return (0);
}

int		ft_select_fractal(char *argv, t_fctl *fctl)
{
	if (ft_strcmp(argv, "julia") == 0 || ft_strcmp(argv, "1") == 0)
		fctl->fractal = 1;
	else if (ft_strcmp(argv, "mandelbrot") == 0 || ft_strcmp(argv, "2") == 0)
		fctl->fractal = 2;
	else if (ft_strcmp(argv, "pointed") == 0 || ft_strcmp(argv, "3") == 0)
		fctl->fractal = 3;
	else if (ft_strcmp(argv, "choux") == 0 || ft_strcmp(argv, "4") == 0)
		fctl->fractal = 4;
	else if (ft_strcmp(argv, "robot") == 0 || ft_strcmp(argv, "5") == 0)
		fctl->fractal = 5;
	else if (ft_strcmp(argv, "hum") == 0 || ft_strcmp(argv, "6") == 0)
		fctl->fractal = 6;
	else if (ft_strcmp(argv, "burningship") == 0 || ft_strcmp(argv, "7") == 0)
		fctl->fractal = 7;
	else
		ft_help();
	return (0);
}
