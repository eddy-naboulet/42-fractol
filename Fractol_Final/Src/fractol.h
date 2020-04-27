/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:35:42 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/07 16:33:35 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <openCL/opencl.h>

typedef struct				s_cl
{
	cl_platform_id			platform_id;
	cl_uint					platform_count;
	cl_int					error;
	cl_device_id			device;
	cl_uint					device_count;
	cl_context				context;
	cl_context_properties	properties[3];
	cl_command_queue		cmd_queue;
	cl_program				program;
	char					*sources;
	size_t					size_sources;
	cl_kernel				kernel;
	cl_mem					output;
	size_t					global[3];
	size_t					local;
}							t_cl;

typedef struct				s_use
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						bpp;
	int						sizeline;
	int						endian;
}							t_use;

typedef struct				s_hud
{
	void					*mlx;
	void					*win;
}							t_hud;

typedef struct				s_fctl
{
	double					image_x;
	double					image_y;
	double					zoom_x;
	double					zoom_y;
	double					tmp_r;
	double					tmp_i;
	double					c_r;
	double					c_i;
	double					z_r;
	double					z_i;
	double					x1;
	double					x2;
	double					y1;
	double					y2;
	int						color_value_1;
	int						color_value_2;
	char					*window_name;
	int						init_fractal;
	int						get_color_r;
	int						get_color_g;
	int						get_color_b;
	int						window_size;
	int						fractal;
	int						open_cl;
	int						pause;
	int						imax;
	int						x;
	int						y;
	int						i;
	t_use					*use;
}							t_fctl;

int							ft_key_init_choux_1(int keycode, t_fctl *fctl);
int							ft_key_init_choux_2(int keycode, t_fctl *fctl);
int							ft_key_init_choux_3(int keycode, t_fctl *fctl);
int							ft_key_init_julia_1(int keycode, t_fctl *fctl);
int							ft_key_init_julia_2(int keycode, t_fctl *fctl);
int							ft_key_init_julia_3(int keycode, t_fctl *fctl);
int							ft_key_init_robot_1(int keycode, t_fctl *fctl);
int							ft_key_init_robot_2(int keycode, t_fctl *fctl);
int							ft_key_init_robot_3(int keycode, t_fctl *fctl);
int							ft_key_init_hum_1(int keycode, t_fctl *fctl);
int							ft_key_init_hum_2(int keycode, t_fctl *fctl);
int							ft_key_init_hum_3(int keycode, t_fctl *fctl);
int							ft_key_zoom(int keycode, t_fctl *fctl);
int							ft_key_move(int keycode, t_fctl *fctl);
int							ft_select_key_color(int keycode, t_fctl *fctl);
int							ft_select_key_choux(int keycode, t_fctl *fctl);
int							ft_select_key_julia(int keycode, t_fctl *fctl);
int							ft_select_key_robot(int keycode, t_fctl *fctl);
int							ft_select_key_move(int keycode, t_fctl *fctl);
int							ft_select_key_hum(int keycode, t_fctl *fctl);
int							ft_select_fractal(char *argv, t_fctl *fctl);
int							ft_select_open(char *argv, t_fctl *fctl);
void						ft_select_draw_1(t_fctl *fctl);
void						ft_select_draw_2(t_fctl *fctl);
void						ft_select_draw_3(t_fctl *fctl);
void						ft_select_draw_4(t_fctl *fctl);
void						ft_select_all(t_fctl *fctl);
void						ft_put_pixel(t_fctl *fctl, double x, double y);
void						ft_put_hud_color(t_fctl *fctl);
void						ft_put_hud_value(t_fctl *fctl);
void						ft_put_hud(t_fctl *fctl);
int							ft_color_profil_1(int keycode, t_fctl *fctl);
int							ft_color_profil_2(int keycode, t_fctl *fctl);
int							ft_color_psy(int keycode, t_fctl *fctl);
int							ft_mouse_zoom_init(int button, int x, int y,
							void *param);
int							ft_mouse_zoom(t_fctl *fctl, int button);
int							ft_mouse_funct(int x, int y, void *param);
t_fctl						*init_burningship(t_fctl *fctl);
t_fctl						*init_mandelbrot(t_fctl *fctl);
t_fctl						*init_pointed(t_fctl *fctl);
t_fctl						*init_robot(t_fctl *fctl);
t_fctl						*init_julia(t_fctl *fctl);
t_fctl						*init_choux(t_fctl *fctl);
t_fctl						*init_hum(t_fctl *fctl);
t_fctl						*ft_restart_image(t_fctl *fctl);
t_fctl						*ft_draw_image(t_fctl *fctl);
int							ft_init_event(int keycode, t_fctl *fctl);
int							ft_utils(int keycode, t_fctl *fctl);
void						ft_draw_cl(t_fctl *fctl, char *select);
void						ft_help(void);
void						ft_window_size(t_fctl *fctl);
void						ft_burningship(t_fctl *fctl);
void						ft_mandelbrot(t_fctl *fctl);
void						ft_pointed(t_fctl *fctl);
void						ft_choux(t_fctl *fctl);
void						ft_robot(t_fctl *fctl);
void						ft_julia(t_fctl *fctl);
void						ft_hum(t_fctl *fctl);

#endif
