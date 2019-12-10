/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:57:48 by jslave            #+#    #+#             */
/*   Updated: 2019/11/26 13:57:50 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "stdio.h"//del
# include <pthread.h>
# include "keys_and_struct.h"

int		create_data(t_dt *data);
int		init_mlx(t_dt *data);
void	error_out(t_dt *dt);

void		create_fractal(t_dt *data);
void    calculate_part(t_dt *data);
int		check_arg(t_dt *data, char **av);

int			key_press(int keycode, t_dt *data);
t_num		make_num(double rp, double ip);
int			mouse_move(int x, int y, t_dt *data);
int			find_iterator(t_num pnt, t_dt *data);
int			mouse_click_scroll(int keycode, int x, int y, t_dt *data);


int		rgb_to_color(t_color *color);
void	change_point_color(t_num pnt, int i, t_dt *dt);
int 	show_menu(t_dt *dt);
#endif
