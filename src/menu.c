/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 21:32:41 by jslave            #+#    #+#             */
/*   Updated: 2019/12/09 21:32:43 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			show_menu(t_dt *dt)
{
	if (dt->mlx.menu_on == 1)
	{
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				40, 0xfffeee, "HOW TO USE");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				70, 0xfffeee, "zoom: mouse wheel");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				90, 0xfffeee, "move: arrows");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				110, 0xfffeee, "iterations: num+/num-");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				130, 0xfffeee, "saturation: num8/num2");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				150, 0xfffeee, "change color: num*");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				170, 0xfffeee, "change fractal: num5");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				190, 0xfffeee, "stop Julia: mouse-left click");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				210, 0xfffeee, "restore changes: num.");
		mlx_string_put(dt->mlx.mlx_ptr, dt->mlx.win_ptr, 50,
				230, 0xfffeee, "hide menu: num0");
	}
	return (0);
}
