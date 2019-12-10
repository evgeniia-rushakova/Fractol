
#include "fractol.h"

int		rgb_to_color(t_color *color)
{
	int r;
	int g;
	int b;

	r = color->r;
	g = color->g;
	b = color->b;
	return ((r << 16) | (g << 8) | b);
}

void	change_point_color(t_num pnt, int i, t_dt *dt)
{
	t_color col;

	col.r   = sin(0.25 * i + dt->fract.test) * dt->fract.sat + 128;
	col.g = sin(0.25 * i + dt->fract.test + 2) * dt->fract.sat + 128;
	col.b  = sin(0.25 * i + dt->fract.test + 4) * dt->fract.sat + 128;
	dt->mlx.img_data[(int)pnt.rp * WIDTH + (int)pnt.ip] = rgb_to_color(&col);
}