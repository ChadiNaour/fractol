/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feigenbaum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:06:15 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 13:42:56 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		findfeigenbaum(t_feigenbaum f, t_complex z0, int max_iter)
{
	t_complex	z;
	int			n;
	double		temp;

	n = 0;
	z = z0;
	f.c.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im;
	f.c.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im;
	z.re = 0;
	z.im = 0;
	while (n < max_iter && z.re * z.re + z.im * z.im <= 4)
	{
		temp = z.re * z.re - z.im * z.im + f.c.re + f.xm;
		z.im = 2 * z.re * z.im + f.c.im - f.ym;
		z.re = temp;
		n++;
	}
	return (n);
}

void	*filling_feigenbaum1(void *t)
{
	t_fractal	*f;
	t_complex	z0;
	int			n;
	int			x;
	int			y;

	f = (t_fractal *)t;
	x = 0;
	n = 0;
	while (x < W / 2)
	{
		y = 0;
		while (y < H / 2)
		{
			z0.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			z0.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findfeigenbaum(f->f, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_feigenbaum2(void *t)
{
	t_fractal	*f;
	t_complex	z0;
	int			n;
	int			x;
	int			y;

	f = (t_fractal *)t;
	x = W / 2;
	n = 0;
	while (x < W)
	{
		y = 0;
		while (y < H / 2)
		{
			z0.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			z0.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findfeigenbaum(f->f, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_feigenbaum3(void *t)
{
	t_fractal	*f;
	t_complex	z0;
	int			n;
	int			x;
	int			y;

	f = (t_fractal *)t;
	x = 0;
	n = 0;
	while (x < W / 2)
	{
		y = H / 2;
		while (y < H)
		{
			z0.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			z0.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findfeigenbaum(f->f, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_feigenbaum4(void *t)
{
	t_fractal	*f;
	t_complex	z0;
	int			n;
	int			x;
	int			y;

	f = (t_fractal *)t;
	x = W / 2;
	n = 0;
	while (x < W)
	{
		y = H / 2;
		while (y < H)
		{
			z0.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			z0.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findfeigenbaum(f->f, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
