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
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
#include "stdio.h"//del

t_num   make_num(double rp, double ip)
{
    t_num num;

    num.rp = rp;
    num.ip = ip;
    return (num);
}

void    create_fractal(t_mlxdata *data)
{
    t_num min;
    t_num max;
    t_num dependence;
    t_num pnt;
    t_num z;
    int x = 0;
    int y = 0;
    int i_max;
    int i = 0;

    i_max = 50;
    min = make_num(-2, -2);
    max = make_num(2, (min.ip + (max.rp - min.rp) * HEIGHT / WIDTH));
    dependence = make_num((max.rp - min.rp) / (WIDTH - 1), (max.ip - min.ip) / (HEIGHT - 1));
    pnt = make_num(min.rp + x * dependence.rp,  max.ip - y *dependence.ip);
    y = 0;
    while (y < HEIGHT)
    {
        pnt.ip = max.ip - y * dependence.ip;
        x = 0;
        while (x < WIDTH)
        {
            pnt.rp = min.rp + x * dependence.rp;
            z = make_num(pnt.rp, pnt.ip);
            i = 0;
            while ((pow(pnt.rp, 2.0) + pow(pnt.ip, 2.0) <= 4) && i < i_max)
            {
               z = make_num((pow(pnt.rp, 2.0)),(pow(pnt.ip, 2.0)));
               data->img_data[y * WIDTH + x] = 0x3cb371;
               i++;
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

int     key_press(int keycode, t_mlxdata *data)
{
    if (keycode == KEY_ESC && data)//del
    {
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);
        exit(0);
    }
    return(0);
}

void    create_data(t_mlxdata *data)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FRACTOL");
    data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->img_data = (int *)mlx_get_data_addr(data->img_ptr, &(data->bpp), &(data->size_line), &(data->endian));
}

int     main()
{
    t_mlxdata *data;
/*    (void)av;
    if (ac != 2)
    {
        ft_putendl("usage: ./fractol file");
        exit(1);
    }
    else if (ac == 2)
    {*/
        data = (t_mlxdata *)ft_memalloc(sizeof(t_mlxdata));
        create_data(data);
        create_fractal(data);
        mlx_hook(data->win_ptr, 2, 0, key_press, data);
        mlx_loop(data->mlx_ptr);
    //}
    return (0);
}
