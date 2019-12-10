/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:00:13 by jslave            #+#    #+#             */
/*   Updated: 2019/11/26 14:00:16 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			check_movement(int keycode, t_dt *dt)//rp -x ip -y
{
	if (keycode == KEY_RIGHT)
	{
		dt->fract.move.rp = fabs(dt->fract.max.rp - dt->fract.min.rp) * 0.01;
		dt->fract.max.rp -= dt->fract.move.rp;
		dt->fract.min.rp -= dt->fract.move.rp;
	}
	if (keycode == KEY_LEFT)
	{
		dt->fract.move.rp = fabs(dt->fract.max.rp - dt->fract.min.rp) * 0.01;
		dt->fract.max.rp += dt->fract.move.rp;
		dt->fract.min.rp += dt->fract.move.rp;
	}
	if (keycode == KEY_UP)
	{
		dt->fract.move.ip = fabs(dt->fract.max.ip - dt->fract.min.ip) * 0.01;
		dt->fract.max.ip -= dt->fract.move.ip;
		dt->fract.min.ip -= dt->fract.move.ip;
	}
	if (keycode == KEY_DOWN)
	{
		dt->fract.move.ip = fabs(dt->fract.max.ip - dt->fract.min.ip) * 0.01;
		dt->fract.max.ip += dt->fract.move.ip;
		dt->fract.min.ip += dt->fract.move.ip;
	}
	return (0);
}

int			check_other_properties(int keycode, t_dt *dt)
{

	if (keycode == KEY_NUM_P)
		dt->fract.i += 10;
	if (keycode == KEY_NUM_M && dt->fract.i - 10 > 0)
		dt->fract.i -= 10;
	if (keycode == KEY_AST)
	{
		mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
		dt->fract.test+=0.1;
		create_fractal(dt);
	}
	if (keycode == KEY_NUM8)
	{
		mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
		if(dt->fract.sat + 5 <= 127)
			dt->fract.sat+=5;
		create_fractal(dt);
	}
	if (keycode == KEY_NUM2)
	{
		mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
		if(dt->fract.sat - 5 >= 10)
			dt->fract.sat-=5;
		create_fractal(dt);
	}
	return (0);
}

int			key_press(int keycode, t_dt *dt)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(dt->mlx.mlx_ptr, dt->mlx.img_ptr);
		exit(0);
	}
	mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
	check_movement(keycode, dt);
	check_other_properties(keycode, dt);
	dt->fract.dep = make_num((dt->fract.max.rp - dt->fract.min.rp) /
	(WIDTH - 1), (dt->fract.max.ip - dt->fract.min.ip) / (HEIGHT - 1));
	create_fractal(dt);
	return (0);
}
