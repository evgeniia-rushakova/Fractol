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
#define FRACTOL_H

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

typedef struct      s_mlxdata
{
    void			*win_ptr;
    void			*mlx_ptr;
    void			*img_ptr;
    int				*img_data;
    int				bpp;
    int				endian;
    int				size_line;
}                   t_mlxdata;

typedef struct      s_num
{
    double rp;
    double ip;
}                   t_num;

#endif
