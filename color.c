/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:19:11 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/27 18:35:03 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(t_rgb *t, t_rgb *t2)
{
	t[0].r = 255;
	t[0].g = 255;
	t[0].b = 255;
	t[1].r = 255;
	t[1].g = 50;
	t[1].b = 240;
	t2[0].r = 255;
	t2[0].g = 200;
	t2[0].b = 240;
	t2[1].r = 130;
	t2[1].g = 255;
	t2[1].b = 255;
	t[2].r = 250;
	t[2].g = 250;
	t[2].b = 100;
	t2[2].r = 130;
	t2[2].g = 250;
	t2[2].b = 9;
}

void	color_change(int *i)
{
	if (*i >= 0 && *i <= 1)
		*i += 1;
	else if (*i == 2)
		*i = 0;
}

int		methode1(t_color *c, double v)
{
	int red;
	int green;
	int blue;

	blue = (int)(8.5 * (1 - v) * (1 - v) * (1 - v) * v * c->t[c->i].g);
	green = (int)(15 * (1 - v) * (1 - v) * v * v * c->t[c->i].b);
	red = (int)(9 * (1 - v) * v * v * v * c->t[c->i].r);
	return ((red << 16 | green << 8 | blue));
}

int		methode2(t_color *c, int n)
{
	int red;
	int green;
	int blue;

	red = n * c->t2[c->j].r / 50;
	blue = n * c->t2[c->j].b / 50;
	green = n * c->t2[c->j].g / 50;
	return ((red << 16 | green << 8 | blue));
}

int		get_color(t_color *c, int n, t_fractal *f)
{
	int		blue;
	int		red;
	int		green;
	int		*col;
	double	v;

	blue = 0;
	green = 0;
	red = 0;
	v = (double)n / (double)f->max_iter;
	if (c->m == 1)
		return (methode1(c, v));
	if (c->m == 2)
		return (methode2(c, n));
	if (c->m == 3)
	{
		if (c->k == 0)
			col = c->tab;
		else if (c->k == 1)
			col = c->tab1;
		else
			col = c->tab2;
		return (col[(int)maptoreal(n, f->max_iter, 0, 50)]);
	}
	return (0);
}
