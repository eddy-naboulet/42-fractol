/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:57:22 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/20 11:57:28 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int				main(int argc, char **argv)
{
	t_fctl		*fctl;
	t_use		*use;

	use = malloc(sizeof(t_use));
	fctl = malloc(sizeof(t_fctl));
	use->mlx = mlx_init();
	use->win = mlx_new_window(use->mlx, 800, 800, "fractol");
	ft_draw_image_2(fctl, use);
	mlx_hook(use->win, 6, 0, ft_mouse_funct, use);
	mlx_loop(use->mlx);
}
