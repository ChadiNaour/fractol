/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:45:57 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 17:33:33 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		findtricorn(t_complex z, int max_iter)
{
	int			n;
	t_complex	c;
	double		temp;

	n = 0;
	c.re = z.re;
	c.im = z.im;
	while (n < max_iter && (z.re * z.re + z.im * z.im) < 4)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = -2 * z.re * z.im + c.im;
		z.re = temp;
		n++;
	}
	return (n);
}

void	*filling_tri1(void *t)
{
	t_fractal	*f;
	t_complex	z;
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
			z.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			z.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findtricorn(z, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_tri2(void *t)
{
	t_fractal	*f;
	t_complex	z;
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
			z.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			z.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findtricorn(z, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_tri3(void *t)
{
	t_fractal	*f;
	t_complex	z;
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
			z.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			z.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findtricorn(z, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_tri4(void *t)
{
	t_fractal	*f;
	t_complex	z;
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
			z.re = maptoreal(x, 1000, f->limit.remin, f->limit.remax);
			z.im = maptoreal(y, 1000, f->limit.immin, f->limit.immax);
			n = findtricorn(z, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + 1000 * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
