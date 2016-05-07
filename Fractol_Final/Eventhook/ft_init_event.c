/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:23:57 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 12:48:44 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Src/fractol.h"

int		ft_init_event(int keycode, t_fctl *fctl)
{
	if (fctl->fractal == 1)
		ft_select_key_julia(keycode, fctl);
	if (fctl->fractal == 4)
		ft_select_key_choux(keycode, fctl);
	if (fctl->fractal == 5)
		ft_select_key_robot(keycode, fctl);
	if (fctl->fractal == 6)
		ft_select_key_hum(keycode, fctl);
	ft_select_key_color(keycode, fctl);
	ft_select_key_move(keycode, fctl);
	return (0);
}
