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

#include "fractol.h"

int				main(int argc, char **argv)
{
	t_fctl		*fctl;

	if (argc != 2)
		return (0);
	fctl = malloc(sizeof(t_fctl));
	fctl->use = malloc(sizeof(t_use));
	fctl->use->mlx = mlx_init();
	fctl->use->win = mlx_new_window(fctl->use->mlx, 800, 800, "fractol");
	ft_select_fractal(argv[1], fctl);
	ft_draw_image(fctl);
	glutInitWindowSize(800, 600);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLU_RGBA | GLUT_DOUBLE);
	glutCreateWindow("test");
	//mlx_mouse_hook(fctl->use->win, ft_key_move, fctl);
	//mlx_hook(fctl->use->win, 4, 0, ft_mouse_zoom, fctl);
	mlx_hook(fctl->use->win, 4, 0, ft_test_zoom, fctl);
	mlx_hook(fctl->use->win, 2, 0, ft_key_move, fctl);
	mlx_hook(fctl->use->win, 6, 0, ft_mouse_funct, fctl);
	mlx_loop(fctl->use->mlx);
}
