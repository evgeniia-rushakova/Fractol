/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:57:31 by jslave            #+#    #+#             */
/*   Updated: 2019/11/26 13:57:33 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_dt *data;

	if (!(data = (t_dt *)ft_memalloc(sizeof(t_dt))))
		exit(1);
	if (ac == 2 && check_arg(data, av) == 1)
	{
		if (create_data(data) == 1)
		{
			mlx_hook(data->mlx.win_ptr, 2, 0, key_press, data);
			mlx_hook(data->mlx.win_ptr, 6, 0, mouse_move, data);
			mlx_hook(data->mlx.win_ptr, 4, 0, mouse_click_scroll, data);
			mlx_loop(data->mlx.mlx_ptr);
			create_fractal(data);
		}
		else
			error_out(data);
	}
	else if (ac != 2 || (ac == 2 && check_arg(data, av) != 1))
	{
		ft_putendl("usage: ./fractol [fractals]\nChoose"
			 " your fractal:\n--> Mandelbrot\n--> Julia\n--> Burnigship");
		free(data);
		exit(1);
	}
	return (0);
}
