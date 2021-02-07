/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tear_drop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:26:16 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 17:33:55 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		findteardrop(t_complex c, int max_iter)
{
	int			n;
	t_complex	z;
	double		temp;

	n = 0;
	z.re = c.im;
	z.im = c.re;
	c.re = z.re / (z.re * z.re + z.im * z.im) * -1;
	c.im = z.im / (z.re * z.re + z.im * z.im);
	z.re = 0;
	z.im = 0;
	while (n < max_iter && z.re * z.re + z.im * z.im < 4)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		n++;
	}
	return (n);
}

void	*filling_tear1(void *t)
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
			c.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findteardrop(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_tear2(void *t)
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
			c.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findteardrop(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_tear3(void *t)
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
			c.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findteardrop(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_tear4(void *t)
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
			c.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			c.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findteardrop(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
