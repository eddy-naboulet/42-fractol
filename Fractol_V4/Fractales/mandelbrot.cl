
__kernel void	fractal(__global	char * img,
									double zoom_x,
									double zoom_y,
									double x1,
									double y1,
									double tmp_r,
									double tmp_i,
									int imax,
									int sizeline,
									int bpp)
{
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int i;
	double tmp;
	int x;
	int y;
	int index;
	double ct_index;

	x = get_global_id(0);
	y = get_global_id(1);
	c_r = x / zoom_x + x1;
	c_i = y / zoom_y + y1;
	z_r = tmp_r;
	z_i = tmp_i;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < imax)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	ct_index = i + 1 - (2/* * log(2)*/) / sqrt((z_r * z_r) + (z_i * z_i));
	index = x * bpp / 8 + (y * sizeline);
	if (i == imax)
	{
		img[index] = (sin(0.10 * ct_index + 0) * 39 + 200);
		img[index + 1] = (sin(0.10 * ct_index + 2) * 39 + 200);
		img[index + 2] = (sin(0.10 * ct_index + 4) * 39 + 200);

	}
	else
	{
		img[index] = (sin(0.10 * ct_index + 0) * 39 + 200);
		img[index + 1] = (sin(0.10 * ct_index + 2) * 39 + 200);
		img[index + 2] = (sin(0.10 * ct_index + 4) * 39 + 200);
	}
}
