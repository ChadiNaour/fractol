/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:53:21 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 14:09:39 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	limits1(t_fractal *f)
{
	if (f->fractal_nbr == 3)
	{
		f->limit.remax = 2;
		f->limit.remin = -2.5;
		f->limit.immax = 1.5;
		f->limit.immin = -2;
	}
	if (f->fractal_nbr == 7)
	{
		f->limit.remax = 2.2;
		f->limit.remin = -2;
		f->limit.immax = 2;
		f->limit.immin = -1.7;
	}
}

void	limits(t_fractal *f)
{
	if (f->fractal_nbr == 2)
	{
		f->limit.remax = 2.2;
		f->limit.remin = -2.2;
		f->limit.immax = 2;
		f->limit.immin = -1.7;
	}
	if (f->fractal_nbr == 1)
	{
		f->limit.remax = 1;
		f->limit.remin = -2;
		f->limit.immax = 1.3;
		f->limit.immin = -1.3;
	}
	if (f->fractal_nbr == 3 || f->fractal_nbr == 7)
		limits1(f);
}

void	define_limits(t_fractal *f)
{
	f->max_iter = 100;
	if (f->fractal_nbr == 1 || f->fractal_nbr == 2 ||
			f->fractal_nbr == 3 || f->fractal_nbr == 7)
		limits(f);
	if (f->fractal_nbr == 4)
	{
		f->limit.remax = 1.8;
		f->limit.remin = -2.2;
		f->limit.immax = 2.5;
		f->limit.immin = -1.5;
	}
	if (f->fractal_nbr == 5)
	{
		f->limit.remin = -4.5;
		f->limit.immin = -4.5;
		f->limit.remax = 4.5;
		f->limit.immax = 4.5;
	}
	if (f->fractal_nbr == 6)
	{
		f->limit.remax = 1.9;
		f->limit.remin = -1.9;
		f->limit.immax = 1.9;
		f->limit.immin = -1.9;
	}
}
