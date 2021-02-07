/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:17:57 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 21:51:25 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_close(t_fractal *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	exit(0);
}

void	change_fractal(t_fractal *f)
{
	if (f->fractal_nbr >= 1 && f->fractal_nbr <= 6)
	{
		f->fractal_nbr++;
		define_limits(f);
		put_fractal(f);
	}
	else if (f->fractal_nbr == 7)
	{
		f->fractal_nbr = 1;
		define_limits(f);
		put_fractal(f);
	}
}

void	arrows(int keycode, t_limit *l)
{
	if (keycode == 123)
	{
		l->remin += 0.05 * (l->remax - l->remin);
		l->remax += 0.05 * (l->remax - l->remin);
	}
	if (keycode == 124)
	{
		l->remin -= 0.05 * (l->remax - l->remin);
		l->remax -= 0.05 * (l->remax - l->remin);
	}
	if (keycode == 126)
	{
		l->immin += 0.05 * (l->immax - l->immin);
		l->immax += 0.05 * (l->immax - l->immin);
	}
	if (keycode == 125)
	{
		l->immin -= 0.05 * (l->immax - l->immin);
		l->immax -= 0.05 * (l->immax - l->immin);
	}
}

void	reset(int keycode, t_fractal *f)
{
	if (keycode == 15)
	{
		define_limits(f);
		put_fractal(f);
	}
}

int		key_press(int keycode, t_fractal *f)
{
	if (keycode == 8 || keycode == 53 || keycode == 126 || keycode == 69 ||
			keycode == 125 || keycode == 123 || keycode == 124)
		help2(keycode, f);
	if (keycode == 38 && f->fractal_nbr == 2)
	{
		f->j.start = 0;
		if (f->j.move == 1)
			f->j.move = 0;
		else
			f->j.move = 1;
	}
	if ((keycode == 11 && f->fractal_nbr == 7) ||
			(keycode == 3 && f->fractal_nbr == 6) || keycode == 15)
		help3(keycode, f);
	if (keycode == 46 || keycode == 49 || keycode == 69)
		help(keycode, f);
	if (keycode == 78 && f->max_iter >= 30)
	{
		f->max_iter -= 10;
		put_fractal(f);
	}
	if (keycode == 15)
		reset(keycode, f);
	return (0);
}
