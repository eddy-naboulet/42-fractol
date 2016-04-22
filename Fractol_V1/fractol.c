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

int		restart_fract(t_fract *fract, t_info *info)
{
	mlx_destroy_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, 800, 800);
	info->img_data = mlx_get_data_addr(info->img, &info->nbit, &info->line,
	&info->endian);
	if (info->f == 1)
		ft_mbrot(fract, info);
	if (info->f == 2)
		ft_julia(fract, info);
	if (info->f == 3)
		ft_bship(fract, info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_string_put(info->mlx, info->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(info->mlx, info->win, 35, 55, 0xFFFFFF,
		"Space to pause and zoom (mouse scroll)");
	return (0);
}
