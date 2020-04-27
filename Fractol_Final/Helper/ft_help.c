/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 14:54:04 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 17:23:13 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Src/fractol.h"

void	ft_help(void)
{
	ft_putstr("Please, write ./fractol and select a fractal\n");
	ft_putstr("write 'cl' to run opencl mode\n");
	ft_putstr(" 1 - julia\n");
	ft_putstr(" 2 - mandelbrot\n");
	ft_putstr(" 3 - pointed\n");
	ft_putstr(" 4 - choux\n");
	ft_putstr(" 5 - robot\n");
	ft_putstr(" 6 - hum\n");
	ft_putstr(" 7 - burningship\n");
	exit(1);
}
