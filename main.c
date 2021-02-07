/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 00:13:36 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 14:10:18 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

void		usage(void)
{
	ft_putstr("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	ft_putstr("┃     usage: ./fractol fractal_name     ┃\n");
	ft_putstr("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	ft_putstr("┃             mandelbrot                ┃\n");
	ft_putstr("┃            ━━━━━━━━━━━                ┃\n");
	ft_putstr("┃               julia                   ┃\n");
	ft_putstr("┃            ━━━━━━━━━━━                ┃\n");
	ft_putstr("┃              tricorn                  ┃\n");
	ft_putstr("┃            ━━━━━━━━━━━                ┃\n");
	ft_putstr("┃            burning_ship               ┃\n");
	ft_putstr("┃            ━━━━━━━━━━━                ┃\n");
	ft_putstr("┃              teardrop                 ┃\n");
	ft_putstr("┃            ━━━━━━━━━━━                ┃\n");
	ft_putstr("┃          feigenbaum_point             ┃\n");
	ft_putstr("┃            ━━━━━━━━━━━                ┃\n");
	ft_putstr("┃           burning_julia               ┃\n");
	ft_putstr("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void		init(t_fractal *f)
{
	f->f.move = 0;
	f->j.move = 0;
	f->bj.move = 0;
	f->j.start = 1;
	f->f.start = 1;
	f->bj.start = 1;
	f->c.m = 1;
	f->c.i = 0;
	f->c.j = 0;
	f->c.k = 0;
	f->zoomfactor = 1.4;
}

void		createcolor(t_color *c)
{
	create_gradian(c->tab, 0x690069, 0xffff00, 0x690069);
	create_gradian(c->tab1, 0x1D8348, 0xE5E7E9, 0x1D8348);
	create_gradian(c->tab2, 0xB22222, 0xffff00, 0xB22222);
}

int			main(int argc, char **argv)
{
	t_fractal	f;

	if (argc == 2)
	{
		fractal_chosing(&f, argv[1]);
		color(f.c.t, f.c.t2);
		createcolor(&f.c);
		f.mlx_ptr = mlx_init();
		f.win_ptr = mlx_new_window(f.mlx_ptr, 1000, 800, "FRACTOL");
		f.img_ptr = mlx_new_image(f.mlx_ptr, 1000, 800);
		init(&f);
		f.img_data = (int *)mlx_get_data_addr(f.img_ptr, &f.bpp,
				&f.size_line, &f.endian);
		define_limits(&f);
		fractal_filling(&f);
		mlx_put_image_to_window(f.mlx_ptr, f.win_ptr, f.img_ptr, 0, 0);
		backgrounding(&f);
		menu(&f);
		mlx_hook(f.win_ptr, 6, 0, &mouse_move, (void *)&f);
		mlx_hook(f.win_ptr, 2, 0, &key_press, (void*)&f);
		mlx_hook(f.win_ptr, 4, 0, &mouse_press, (void *)&f);
		mlx_loop(f.mlx_ptr);
	}
	else
		usage();
}
