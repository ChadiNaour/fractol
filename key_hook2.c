/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:34:39 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 17:05:55 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help2(int keycode, t_fractal *f)
{
	(keycode == 8) ? change_fractal(f) : 1;
	(keycode == 53) ? my_close(f) : 1;
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		arrows(keycode, &f->limit);
		put_fractal(f);
	}
	if (keycode == 69)
	{
		f->max_iter += 10;
		put_fractal(f);
	}
}

void	help(int keycode, t_fractal *f)
{
	if (keycode == 46)
	{
		if (f->c.m == 1)
		{
			f->c.m = 2;
			f->c.j = 0;
		}
		else if (f->c.m == 2)
			f->c.m = 3;
		else if (f->c.m == 3)
			f->c.m = 1;
		put_fractal(f);
	}
	if (keycode == 49)
	{
		if (f->c.m == 1)
			color_change(&f->c.i);
		else if (f->c.m == 2)
			color_change(&f->c.j);
		else if (f->c.m == 3)
			color_change(&f->c.k);
		put_fractal(f);
	}
}

void	help3(int keycode, t_fractal *f)
{
	if (keycode == 11 && f->fractal_nbr == 7)
	{
		f->bj.start = 0;
		if (f->bj.move == 1)
			f->bj.move = 0;
		else
			f->bj.move = 1;
	}
	if (keycode == 3 && f->fractal_nbr == 6)
	{
		f->f.start = 0;
		if (f->f.move == 1)
			f->f.move = 0;
		else
			f->f.move = 1;
	}
}

void	thread_man(t_fractal *f)
{
	int i;

	pthread_create(&f->thread[0], NULL, filling_man1, (void *)f);
	pthread_create(&f->thread[1], NULL, filling_man2, (void *)f);
	pthread_create(&f->thread[2], NULL, filling_man3, (void *)f);
	pthread_create(&f->thread[3], NULL, filling_man4, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->thread[i], NULL);
		i++;
	}
}

void	thread_julia(t_fractal *f)
{
	int i;

	pthread_create(&f->thread[0], NULL, filling_julia1, (void *)f);
	pthread_create(&f->thread[1], NULL, filling_julia2, (void *)f);
	pthread_create(&f->thread[2], NULL, filling_julia3, (void *)f);
	pthread_create(&f->thread[3], NULL, filling_julia4, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->thread[i], NULL);
		i++;
	}
}
