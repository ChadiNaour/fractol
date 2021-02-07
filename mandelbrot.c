/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:23:30 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 13:39:47 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		findmandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp;
	int			n;

	n = 0;
	z.re = c.re;
	z.im = c.im;
	while (n < max_iter && z.re * z.re + z.im * z.im <= 4)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		n++;
	}
	return (n);
}

void	*filling_man1(void *t)
{
	t_fractal	*f;
	t_complex	c;
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
			c.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findmandelbrot(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_man2(void *t)
{
	t_fractal	*f;
	t_complex	c;
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
			c.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findmandelbrot(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_man3(void *t)
{
	t_fractal	*f;
	t_complex	c;
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
			c.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findmandelbrot(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_man4(void *t)
{
	t_fractal	*f;
	t_complex	c;
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
			c.re = maptoreal(x, W, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, H, f->limit.immin, f->limit.immax);
			n = findmandelbrot(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
