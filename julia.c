/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:18:40 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 13:41:53 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		findjulia(t_complex c, t_complex z0, int max_iter)
{
	int			n;
	double		temp;

	n = 0;
	while (z0.re * z0.re + z0.im * z0.im < 4 && n < max_iter)
	{
		temp = z0.re * z0.re - z0.im * z0.im + c.re;
		z0.im = 2 * z0.re * z0.im + c.im;
		z0.re = temp;
		n++;
	}
	return (n);
}

void	*filling_julia1(void *t)
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
			n = findjulia(f->j.c, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_julia2(void *t)
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
			n = findjulia(f->j.c, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_julia3(void *t)
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
			n = findjulia(f->j.c, z0, f->max_iter);
			if (n < f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_julia4(void *t)
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
			n = findjulia(f->j.c, z0, f->max_iter);
			if (n < f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
