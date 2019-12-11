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

void		change_move(int keycode, t_dt *dt)
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
}

int			check_movement(int keycode, t_dt *dt)
{
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT ||
	keycode == KEY_UP || keycode == KEY_DOWN)
	{
		mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
		change_move(keycode, dt);
		dt->fract.dep = make_num((dt->fract.max.rp - dt->fract.min.rp) /
		(WIDTH - 1), (dt->fract.max.ip - dt->fract.min.ip) / (HEIGHT - 1));
		create_fractal(dt);
	}
	return (0);
}

int			check_other_properties(int keycode, t_dt *dt)
{
	if (keycode == KEY_NUM_P || keycode == KEY_NUM_M ||
	keycode == KEY_AST || keycode == KEY_NUM8 ||
	keycode == KEY_NUM2 || keycode == KEY_NUM5)
	{
		mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
		if (keycode == KEY_NUM_P)
			dt->fract.i += 10;
		if (keycode == KEY_NUM_M && dt->fract.i - 10 > 0)
			dt->fract.i -= 10;
		if (keycode == KEY_AST)
			dt->fract.col_step += 0.1;
		if (keycode == KEY_NUM8 && dt->fract.sat + 5 <= 127)
			dt->fract.sat += 5;
		if (keycode == KEY_NUM2 && dt->fract.sat - 5 >= 10)
			dt->fract.sat -= 5;
		if (keycode == KEY_NUM5)
		{
			if (dt->fract.type < 4)
				dt->fract.type += 1;
			else
				dt->fract.type = 1;
		}
		create_fractal(dt);
	}
	return (0);
}

int			check_menu(int keycode, t_dt *dt)
{
	if (keycode == KEY_NUM0)
	{
		mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
		if (dt->mlx.menu_on == 1)
			dt->mlx.menu_on = 0;
		else
			dt->mlx.menu_on = 1;
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
	if (keycode == KEY_NUM_PNT)
	{
		mlx_clear_window(dt->mlx.mlx_ptr, dt->mlx.win_ptr);
		create_data(dt);
		create_fractal(dt);
	}
	check_movement(keycode, dt);
	check_other_properties(keycode, dt);
	check_menu(keycode, dt);
	return (0);
}
