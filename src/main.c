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

void	error_out(t_dt *dt)
{
	ft_putendl("error");
	free(dt);
	exit(1);
}

void	set_hooks(t_dt *data)
{
	mlx_hook(data->mlx.win_ptr, 2, 0, key_press, data);
	mlx_hook(data->mlx.win_ptr, 6, 0, mouse_move, data);
	mlx_hook(data->mlx.win_ptr, 4, 0, mouse_click_scroll, data);
}

int		main(int ac, char **av)
{
	t_dt *data;

	if (!(data = (t_dt *)ft_memalloc(sizeof(t_dt))))
		error_out(data);
	if (ac == 2 && check_arg(data, av) == 1)
	{
		if (init_mlx(data) == 1 && create_threads(data) == 1)
		{
			create_data(data);
			create_fractal(data);
			set_hooks(data);
			mlx_loop(data->mlx.mlx_ptr);
		}
		else
			error_out(data);
	}
	else if (ac != 2 || (ac == 2 && check_arg(data, av) != 1))
	{
		ft_putendl("usage: ./fractol [fractals]\nChoose"
	" your fractal:\n--> Mandelbrot\n--> Julia\n--> Burnigship\n"
	"--> Buffalo");
		free(data);
		exit(1);
	}
	return (0);
}
