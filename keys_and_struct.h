/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:30:56 by jslave            #+#    #+#             */
/*   Updated: 2019/12/08 19:30:58 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_KEYS_AND_STRUCT_H
# define FRACTOL_KEYS_AND_STRUCT_H

# define KEY_NUM6 88
# define KEY_NUM4 86
# define KEY_NUM8 91
# define KEY_NUM2 84
# define KEY_NUM5 87
# define KEY_NUM_P 69
# define KEY_NUM_M 78
# define KEY_NUM7 89
# define KEY_NUM9 92
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_AST 67
# define KEY_ESC 53
# define KEY_NUM0 82

# define WIDTH 800
# define HEIGHT 800
# define THREADS 16

typedef struct		s_num
{
	double			rp;
	double			ip;
}					t_num;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_mouse
{
	int				x;
	int				y;
	int				is_press;
}					t_mouse;

typedef struct		s_fract
{
	t_num			min;
	t_num			max;
	t_num			dep;
	t_num			move;
	int				i;
	int				type;
	t_num			k;
	double 			test;
	int 			sat;
}					t_fract;

typedef struct		s_thread
{
	pthread_t		threads[THREADS];
	int				y_start;
	int				y_end;
}					t_thread;

typedef struct		s_mlx
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				endian;
	int				size_line;
}					t_mlx;

typedef struct		s_dt
{
	t_mlx			mlx;
	t_fract			fract;
	t_mouse			mouse;
	t_thread		thread;
}					t_dt;

#endif
