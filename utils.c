/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:58:49 by jslave            #+#    #+#             */
/*   Updated: 2019/12/10 15:58:50 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int		check_arg(t_dt *data, char **av)
{
	if (ft_strequ(av[1], "Mandelbrot") == 1)
	{
		data->fract.type = 1;
		return (1);
	}
	else if (ft_strequ(av[1], "Julia") == 1)
	{
		data->fract.type = 2;
		return (1);
	}
	else if (ft_strequ(av[1], "Burningship") == 1)
	{
		data->fract.type = 3;
		return (1);
	}
	return (-1);
}

void	error_out(t_dt *dt)
{
	ft_putendl("error");
	free(dt);
	exit(1);
}

t_num		make_num(double rp, double ip)
{
	t_num num;

	num.rp = rp;
	num.ip = ip;
	return (num);
}

