/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:49:54 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/29 11:29:34 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_limit *l, double mousere, double mouseim, double zoomfactor)
{
	double interpolation;

	interpolation = 1.0 / zoomfactor;
	l->remin = interpolate(mousere, l->remin, interpolation);
	l->immin = interpolate(mouseim, l->immin, interpolation);
	l->remax = interpolate(mousere, l->remax, interpolation);
	l->immax = interpolate(mouseim, l->immax, interpolation);
}

int		mouse_press(int button, int x, int y, t_fractal *f)
{
	f->mousere = f->limit.remin +
		(double)x / (W / (f->limit.remax - f->limit.remin));
	f->mouseim = f->limit.immin +
		(double)y / (H / (f->limit.immax - f->limit.immin));
	if (button == 4)
	{
		applyzoom(&f->limit, f->mousere, f->mouseim, f->zoomfactor);
		put_fractal(f);
	}
	if (button == 5)
	{
		applyzoom(&f->limit, f->mousere, f->mouseim, 1 / f->zoomfactor);
		put_fractal(f);
	}
	return (0);
}

int		mouse_move(int x, int y, t_fractal *f)
{
	if (f->fractal_nbr == 2 && f->j.move == 1)
	{
		f->j.c.re = maptoreal((double)x, W, f->limit.remin, f->limit.remax);
		f->j.c.im = maptoreal((double)y, W, f->limit.immin, f->limit.immax);
		put_fractal(f);
	}
	if (f->fractal_nbr == 7 && f->bj.move == 1)
	{
		f->bj.c.re = maptoreal((double)x, W, f->limit.remin, f->limit.remax);
		f->bj.c.im = maptoreal((double)y, W, f->limit.immin, f->limit.immax);
		put_fractal(f);
	}
	if (f->fractal_nbr == 6 && f->f.move == 1)
	{
		f->f.xm = maptoreal((double)x, W, f->limit.remin, f->limit.remax);
		put_fractal(f);
	}
	return (0);
}

void	put_fractal(t_fractal *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	f->img_ptr = mlx_new_image(f->mlx_ptr, W, H);
	f->img_data = (int *)mlx_get_data_addr(f->img_ptr, &f->bpp,
			&f->size_line, &f->endian);
	fractal_filling(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	backgrounding(f);
	menu(f);
}
