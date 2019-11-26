/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <jslave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:22:05 by mgrass            #+#    #+#             */
/*   Updated: 2019/11/19 18:02:08 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>

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

# define WIDTH 400
# define HEIGHT 400
# define MENU_WIDTH 300

typedef struct		s_bres
{
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	int				z_start;
	int				z_end;
	int				dx;
	int				dy;
	int				dx1;
	int				dy1;
	int				px;
	int				py;
	int				color_st;
	int				color_end;
	int				end_x;
	int				end_y;
}					t_bres;

typedef struct		s_fdf
{
	char			*name;
	int				fd;
	int				cols;
	int				rows;
	int				**map;
	int				**color;
	char			dimension;
	char			projection;
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	int				*img_data;
	double			step;
	int				bpp;
	int				endian;
	int				size_line;
	int				x_start;
	int				y_start;
	double			x_rotate;
	double			y_rotate;
	int				x_offset;
	int				y_offset;
	int				z_coeff;
	int				z_min;
	int				z_max;
	double			resize;
}					t_fdf;

/*
** bresenham.c
*/

void				draw(int x, int y, t_bres *data, t_fdf *fdf);
void				draw_dy(t_bres *data, t_fdf *fdf);
void				draw_dx(t_bres *data, t_fdf *fdf);
void				make_line(t_bres *data, t_fdf *fdf);

/*
** color.c
*/

double				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					get_color(int x, int y, t_bres *point);
void				create_color(t_fdf *fdf);
void				change_color(t_fdf *fdf);

/*
** valid.c
*/

int					check_color(char *line);
void				check_line(char *line);
int					check_size(t_fdf *fdf, char *line);

/*
** create.c
*/

void				draw_background(t_fdf *fdf);
void				create_color_map(char *tmp, t_fdf *fdf, int x, int y);
void				create_map(t_fdf *fdf);
void				init_fdf(t_fdf *fdf);
t_fdf				*read_file(char *s);

/*
** draw_utils.c
*/

void				erase_img(t_fdf *fdf);
t_bres				*create_offset_data(char type, int x_st, int y_st, \
					t_fdf *fdf);
void				create_data_and_draw_x(t_fdf *fdf);
void				create_data_and_draw_y(t_fdf *fdf);
void				draw_all(t_fdf *fdf);

/*
** keys.c
*/

void				check_rotates(int keycode, t_fdf *fdf);
void				check_change_size(int keycode, t_fdf *fdf);
void				check_offset_and_projection(int keycode, t_fdf *fdf);
void				check_restore_and_color(int keycode, t_fdf *fdf);
int					key_press(int keycode, t_fdf *fdf);

/*
** menu.c
*/

void				print_menu(t_fdf *lst);
void				add_col_z1(int y, int x, t_bres *data, t_fdf *fdf);
void				add_col_z2(int y, int x, t_bres *data, t_fdf *fdf);

/*
** transform.c
*/

void				x_rotate(int *y, int *z, t_fdf *fdf);
void				y_rotate(int *x, int *z, t_fdf *fdf);
void				iso(int *x, int *y, int *z);
void				change_points(int *x, int *y, int *z, t_fdf *fdf);

/*
** utils.c
*/

void				error_out(void);
void				check_maxmin(t_fdf *fdf, int x, int y);
void				arr_free(int **arr, int rows);
void				free_fdf(t_fdf *fdf);
int					find_step(t_fdf *fdf);

#endif
