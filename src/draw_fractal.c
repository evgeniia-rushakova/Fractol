/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:02:08 by jslave            #+#    #+#             */
/*   Updated: 2019/12/11 17:02:11 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*create_fractal_part(void *data)
{
	int		i;
	t_dt	*data1;

	i = 0;
	data1 = (t_dt *)data;
	while (i < THREADS)
	{
		if (data1->thread.threads[i] == pthread_self())
		{
			data1->thread.y_start = HEIGHT / THREADS * i;
			data1->thread.y_end = HEIGHT / THREADS * (i + 1);
			if ((i + 1) == THREADS)
				data1->thread.y_end = HEIGHT;
			calculate_part(data1);
			break ;
		}
		i++;
	}
	return (data);
}

void		create_fractal(t_dt *data)
{
	int		i;
	t_dt	threads_data[THREADS];

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy(&threads_data[i], data, sizeof(t_dt));
		pthread_create(&data->thread.threads[i], NULL,
				create_fractal_part, &threads_data[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(data->thread.threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
			data->mlx.img_ptr, 0, 0);
	show_menu(data);
}
