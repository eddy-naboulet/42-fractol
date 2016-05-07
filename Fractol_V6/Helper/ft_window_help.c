/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:31:30 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 14:31:45 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Src/fractol.h"

void		ft_put_hud(t_fctl *fctl)
{
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 10, 0xFFFFFF,
		"press esc = quit");
	ft_put_hud_color(fctl);
	ft_put_hud_value(fctl);
}

void		ft_put_hud_color(t_fctl *fctl)
{
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 55, 0xFFFFFF,
		"press 1 = color profile Rainbow");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 75, 0xFFFFFF,
		"press 2 = color profile Fire & Ice");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 95, 0xFFFFFF,
		"press 3 = color profile Black & White");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 115, 0xFFFFFF,
		"press 4 = color profile Joker");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 135, 0xFFFFFF,
		"press 5 = color profile Sand & water");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 155, 0xFFFFFF,
		"press '~' = to set psychedelic color ");
}

void		ft_put_hud_value(t_fctl *fctl)
{
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 200, 0xFFFFFF,
		"press 1 - 9 (numpad) = to set new position");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 220, 0xFFFFFF,
		"press r = to restart fractal");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 240, 0xFFFFFF,
		"press space = to pause fractal");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 260, 0xFFFFFF,
		"press page up / down = to zoom with keyboard");
	mlx_string_put(fctl->use->mlx, fctl->use->win, 10, 280, 0xFFFFFF,
		"press a/w/d/s = to move fractal");
}
