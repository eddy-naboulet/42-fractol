/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_cl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:00:21 by enaboule          #+#    #+#             */
/*   Updated: 2016/05/05 17:40:08 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*get_sources(char *filename)
{
	char	buf[8000];
	int		fd;

	ft_bzero(buf, sizeof(buf));
	fd = open(filename, O_RDONLY);
	read(fd, buf, 7999);
	return (ft_strdup(buf));
}

void pfn_notify(const char *errinfo, const void *private_info, size_t cb, void *user_data)
{
	(void)private_info;
	(void)cb;
	(void)user_data;
    fprintf(stderr, "OpenCL Error (via pfn_notify): %s\n", errinfo);
}

t_cl 		*init_opencl(t_use *use, char *select)
{
	t_cl	*cl;

	cl = ft_memalloc(sizeof(t_cl));
	clGetPlatformIDs(1, &cl->platform_id, &cl->platform_count);
	clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_GPU, 1,
		&cl->device, &cl->device_count);
	cl->properties[0] = CL_CONTEXT_PLATFORM;
	cl->properties[1] = (cl_context_properties)cl->platform_id;
	cl->properties[2] = 0;
	cl->context = clCreateContext(cl->properties, cl->device_count, &cl->device, pfn_notify, NULL, &cl->error);
	cl->sources = get_sources(select);
	cl->cmd_queue = clCreateCommandQueue(cl->context, cl->device, 0, &cl->error);
	cl->program = clCreateProgramWithSource(cl->context, 1, (const char**)&cl->sources, NULL, &cl->error);
	cl->error = clBuildProgram(cl->program, cl->device_count, &cl->device, NULL, NULL, NULL);
	cl->kernel = clCreateKernel(cl->program, "fractal", &cl->error);
	cl->output = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY, 1024 * use->sizeline, NULL, &cl->error);
	cl->global[0] = 1024;
	cl->global[1] = 1024;
	cl->global[2] = 0;
	return (cl);
}
void 		ft_draw_cl(t_fctl *fctl, char *select)
{
	static t_cl	*cl = NULL;
	if (cl == NULL)
		cl = init_opencl(fctl->use, select);
	clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->output);
	clSetKernelArg(cl->kernel, 1, sizeof(double), &fctl->zoom_x);
	clSetKernelArg(cl->kernel, 2, sizeof(double), &fctl->zoom_y);
	clSetKernelArg(cl->kernel, 3, sizeof(double), &fctl->x1);
	clSetKernelArg(cl->kernel, 4, sizeof(double), &fctl->y1);
	clSetKernelArg(cl->kernel, 5, sizeof(double), &fctl->tmp_r);
	clSetKernelArg(cl->kernel, 6, sizeof(double), &fctl->tmp_i);
	clSetKernelArg(cl->kernel, 7, sizeof(int), &fctl->imax);
	clSetKernelArg(cl->kernel, 8, sizeof(int), &fctl->use->sizeline);
	clSetKernelArg(cl->kernel, 9, sizeof(int), &fctl->use->bpp);
	clSetKernelArg(cl->kernel, 10, sizeof(int), &fctl->get_color_r);
	clSetKernelArg(cl->kernel, 11, sizeof(int), &fctl->get_color_g);
	clSetKernelArg(cl->kernel, 12, sizeof(int), &fctl->get_color_b);
	clSetKernelArg(cl->kernel, 13, sizeof(int), &fctl->color_value_1);
	clSetKernelArg(cl->kernel, 14, sizeof(int), &fctl->color_value_2);
	clEnqueueNDRangeKernel(cl->cmd_queue, cl->kernel, 2, NULL, cl->global, NULL, 0, NULL, NULL);
	clFinish(cl->cmd_queue);
	clEnqueueReadBuffer(cl->cmd_queue, cl->output, CL_TRUE, 0, 1024 * fctl->use->sizeline,
	 fctl->use->data, 0, NULL, NULL);
}
