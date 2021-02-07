/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_chosing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 07:53:49 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 13:52:52 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		maptoreal(int x, int imgwidth, double minr, double maxr)
{
	double range;

	range = maxr - minr;
	return (x * (range / imgwidth) + minr);
}

void		fractal_chosing(t_fractal *f, char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		f->fractal_nbr = 1;
	else if (!ft_strcmp(name, "julia"))
		f->fractal_nbr = 2;
	else if (!ft_strcmp(name, "burning_ship"))
		f->fractal_nbr = 3;
	else if (!ft_strcmp(name, "tricorn"))
		f->fractal_nbr = 4;
	else if (!ft_strcmp(name, "teardrop"))
		f->fractal_nbr = 5;
	else if (!ft_strcmp(name, "feigenbaum_point"))
		f->fractal_nbr = 6;
	else if (!ft_strcmp(name, "burning_julia"))
		f->fractal_nbr = 7;
	else
	{
		usage();
		exit(0);
	}
}

void		fractal_help(t_fractal *f)
{
	if (f->f.start == 1)
	{
		f->f.c = (t_complex){.re = 0, .im = 0};
		f->f.xm = -1.401155;
		f->f.ym = 0;
	}
}

void		fractal_filling_help(t_fractal *f)
{
	if (f->fractal_nbr == 3)
		thread_burn(f);
	else if (f->fractal_nbr == 4)
		thread_tri(f);
	else if (f->fractal_nbr == 5)
		thread_tear(f);
}

void		fractal_filling(t_fractal *f)
{
	if (f->fractal_nbr == 1)
		thread_man(f);
	else if (f->fractal_nbr == 2)
	{
		if (f->j.start == 1)
			f->j.c = (t_complex){.re = -0.4, .im = 0.6};
		thread_julia(f);
	}
	else if (f->fractal_nbr == 3 || f->fractal_nbr == 4 || f->fractal_nbr == 5)
		fractal_filling_help(f);
	else if (f->fractal_nbr == 6)
	{
		if (f->f.start == 1)
			fractal_help(f);
		thread_feigenbaum(f);
	}
	else if (f->fractal_nbr == 7)
	{
		if (f->bj.start == 1)
			f->bj.c = (t_complex){.re = 0, .im = 0.297};
		thread_burnjulia(f);
	}
	else
		exit(0);
}
