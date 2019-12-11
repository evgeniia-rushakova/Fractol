/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:53:36 by jslave            #+#    #+#             */
/*   Updated: 2019/12/10 15:53:37 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			find_iterator(t_num pnt, t_dt *data)
{
	int		i;
	t_num	z;

	z = make_num(pnt.rp, pnt.ip);
	i = 0;
	while ((pow(z.rp, 2.0) + pow(z.ip, 2.0)) <= 4 && i < data->fract.i)
	{
		if (data->fract.type == 1)
			z = make_num((pow(z.rp, 2.0) - pow(z.ip, 2.0) + pnt.rp),
				(2.0 * z.rp * z.ip + pnt.ip));
		if (data->fract.type == 2)
			z = make_num((pow(z.rp, 2.0) - pow(z.ip, 2.0) -
				data->fract.k.rp), (2 * z.rp * z.ip) + data->fract.k.ip);
		if (data->fract.type == 3)
			z = make_num((pow(z.rp, 2.0) - pow(z.ip, 2.0) + pnt.rp),
				(-2.0 * fabs(z.rp * z.ip) + pnt.ip));
		if (data->fract.type == 4)
			z = make_num((pow(z.rp, 2.0) - pow(z.ip, 2.0) + pnt.rp),
					(-2.0 * z.rp * fabs(z.ip) + pnt.ip));
		i++;
	}
	return (i);
}

int			is_pnt_in_cardiola(t_num pnt)
{
	double ro;
	double t;
	double roc;
	double r;

	r = pow(pnt.rp + 1, 2.0) + pow(pnt.ip, 2.0);
	ro = pow(pnt.rp - 0.25, 2.0) + pow(pnt.ip, 2.0);
	t = atan2(pnt.ip, pnt.rp - 0.25);
	roc = 0.5 - 0.5 * cos(t);
	if (ro < pow(roc, 2.0) || r < 0.0625)
		return (1);
	return (-1);
}

void		calculate_part(t_dt *data)
{
	t_num	pnt;
	t_num	it;
	int		i;

	it = make_num(data->thread.y_start, 0);
	while (it.rp < data->thread.y_end)
	{
		pnt.ip = data->fract.max.ip - it.rp * data->fract.dep.ip;
		it.ip = 0;
		while (it.ip < WIDTH)
		{
			pnt.rp = data->fract.min.rp + it.ip * data->fract.dep.rp;
			if (data->fract.type == 1 && is_pnt_in_cardiola(pnt) == 1)
				i = data->fract.i;
			else
				i = find_iterator(pnt, data);
			change_point_color(it, i, data);
			it.ip++;
		}
		it.rp++;
	}
}
