/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:03:29 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 13:42:08 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		findburnjulia(t_complex c, t_complex z0, int max_iter)
{
	int			n;
	double		temp;

	n = 0;
	while (z0.re * z0.re + z0.im * z0.im < 4 && n < max_iter)
	{
		temp = z0.re * z0.re - z0.im * z0.im + c.re;
		z0.im = fabs(2 * z0.re * z0.im) + c.im;
		z0.re = fabs(temp);
		n++;
	}
	return (n);
}

void	*filling_burnjulia1(void *t)
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
			n = findburnjulia(f->bj.c, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_burnjulia2(void *t)
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
			n = findburnjulia(f->bj.c, z0, f->max_iter);
			if (n != f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_burnjulia3(void *t)
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
			n = findburnjulia(f->bj.c, z0, f->max_iter);
			if (n < f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*filling_burnjulia4(void *t)
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
			n = findburnjulia(f->bj.c, z0, f->max_iter);
			if (n < f->max_iter)
				f->img_data[x + W * y] = get_color(&f->c, n, f);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
