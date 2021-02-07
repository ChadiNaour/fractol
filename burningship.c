/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 02:52:14 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 13:43:09 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		findburn(t_complex c, int max_iter)
{
	t_complex	z;
	int			n;
	double		temp;

	n = 0;
	z = (t_complex){.re = 0, .im = 0};
	while ((z.re * z.re) + (z.im * z.im) <= 4 && n < max_iter)
	{
		temp = z.re;
		z.re = fabs((z.re * z.re) - (z.im * z.im) + c.re);
		z.im = fabs(2 * temp * z.im + c.im);
		n++;
	}
	return (n);
}

void	*filling_burn1(void *t)
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
			n = findburn(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_burn2(void *t)
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
			n = findburn(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_burn3(void *t)
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
			n = findburn(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_burn4(void *t)
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
			n = findburn(c, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
