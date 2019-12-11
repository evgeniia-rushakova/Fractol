/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:38:47 by jslave            #+#    #+#             */
/*   Updated: 2019/11/28 17:38:49 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_mlx(t_dt *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT,
			"FRACTOL");
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT);
	data->mlx.img_data = (int *)mlx_get_data_addr(data->mlx.img_ptr,
			&(data->mlx.bpp), &(data->mlx.size_line), &(data->mlx.endian));
	data->mlx.menu_on = 1;
	if (data->mlx.win_ptr == NULL || data->mlx.img_ptr == NULL ||
	data->mlx.img_data == 0)
		return (0);
	return (1);
}

void		create_data(t_dt *data)
{
	data->fract.min = make_num(-3, -2.0);
	data->fract.max = make_num(3, 2);
	data->fract.dep = make_num((data->fract.max.rp - data->fract.min.rp) /
	(WIDTH - 1), (data->fract.max.ip - data->fract.min.ip) / (HEIGHT - 1));
	data->fract.i = 50;
	data->fract.col_step = 1;
	data->fract.sat = 65;
	zero_num(&data->fract.move);
	zero_num(&data->fract.k);
}
