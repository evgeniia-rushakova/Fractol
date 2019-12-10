/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:04:57 by jslave            #+#    #+#             */
/*   Updated: 2019/12/08 16:04:59 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_in(int x, int y, t_dt *d)
{
	t_num k;

	k.rp = x * (d->fract.max.rp - d->fract.min.rp) / WIDTH + d->fract.min.rp;
	k.ip = y * (d->fract.max.ip - d->fract.min.ip) / HEIGHT + d->fract.min.ip;
	d->fract.max.rp = k.rp + (d->fract.max.rp - k.rp) * 1.1;
	d->fract.max.ip = k.ip + (d->fract.max.ip - k.ip) * 1.1;
	d->fract.min.rp = k.rp + (d->fract.min.rp - k.rp) * 1.1;
	d->fract.min.ip = k.ip + (d->fract.min.ip - k.ip) * 1.1;
	d->fract.dep.rp = (d->fract.max.rp - d->fract.min.rp) / WIDTH;
	d->fract.dep.ip = (d->fract.max.ip - d->fract.min.ip) / HEIGHT;
}

void		zoom_out(int x, int y, t_dt *d)
{
	t_num k;

	k.rp = x * (d->fract.max.rp - d->fract.min.rp) / WIDTH + d->fract.min.rp;
	k.ip = y * (d->fract.max.ip - d->fract.min.ip) / HEIGHT + d->fract.min.ip;
	d->fract.max.rp = k.rp + (d->fract.max.rp - k.rp) / 1.1;
	d->fract.max.ip = k.ip + (d->fract.max.ip - k.ip) / 1.1;
	d->fract.min.rp = k.rp + (d->fract.min.rp - k.rp) / 1.1;
	d->fract.min.ip = k.ip + (d->fract.min.ip - k.ip) / 1.1;
	d->fract.dep.rp = (d->fract.max.rp - d->fract.min.rp) / WIDTH;
	d->fract.dep.ip = (d->fract.max.ip - d->fract.min.ip) / HEIGHT;
}

int			mouse_move(int x, int y, t_dt *data)
{
	if (data->fract.type == 2 && x >= 0 && x <= WIDTH && y >= 0 &&
	y <= HEIGHT && data->mouse.is_press != 1)
	{
		mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		data->fract.k.rp = (double)x / (WIDTH / (data->fract.max.rp
				- data->fract.min.rp)) + data->fract.min.rp;
		data->fract.k.ip = (double)y / (HEIGHT / (data->fract.max.ip
				- data->fract.min.ip)) + data->fract.min.ip;
		create_fractal(data);
	}
	return (0);
}

int			mouse_click_scroll(int keycode, int x, int y, t_dt *data)
{
	if (keycode == 1 && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (data->mouse.is_press == 0)
			data->mouse.is_press = 1;
		else
			data->mouse.is_press = 0;
	}
	if (keycode == 4 && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		zoom_in(x, y, data);
		create_fractal(data);
	}
	if (keycode == 5 && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		zoom_out(x, y, data);
		create_fractal(data);
	}
	return (0);
}
