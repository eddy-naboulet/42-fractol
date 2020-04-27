/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:57:22 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/13 14:18:09 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				main(int argc, char **argv)
{
	t_fctl		*fctl;

	if (argc != 2 && argc != 3)
		ft_help();
	fctl = malloc(sizeof(t_fctl));
	fctl->use = malloc(sizeof(t_use));
	if (argc == 3)
		ft_select_open(argv[2], fctl);
	ft_window_size(fctl);
	fctl->use->mlx = mlx_init();
	fctl->use->win = mlx_new_window(fctl->use->mlx, 500, 340, "Helper");
	ft_put_hud(fctl);
	fctl->use->win = mlx_new_window(fctl->use->mlx, fctl->window_size,
		fctl->window_size, fctl->window_name);
	ft_select_fractal(argv[1], fctl);
	ft_draw_image(fctl);
	mlx_hook(fctl->use->win, 4, 0, ft_mouse_zoom_init, fctl);
	mlx_hook(fctl->use->win, 2, 0, ft_init_event, fctl);
	mlx_hook(fctl->use->win, 6, 0, ft_mouse_funct, fctl);
	mlx_loop(fctl->use->mlx);
}
