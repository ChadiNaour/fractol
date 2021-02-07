/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:28:35 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 17:09:05 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	thread_burn(t_fractal *f)
{
	int i;

	pthread_create(&f->thread[0], NULL, filling_burn1, (void *)f);
	pthread_create(&f->thread[1], NULL, filling_burn2, (void *)f);
	pthread_create(&f->thread[2], NULL, filling_burn3, (void *)f);
	pthread_create(&f->thread[3], NULL, filling_burn4, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->thread[i], NULL);
		i++;
	}
}

void	thread_tri(t_fractal *f)
{
	int i;

	pthread_create(&f->thread[0], NULL, filling_tri1, (void *)f);
	pthread_create(&f->thread[1], NULL, filling_tri2, (void *)f);
	pthread_create(&f->thread[2], NULL, filling_tri3, (void *)f);
	pthread_create(&f->thread[3], NULL, filling_tri4, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->thread[i], NULL);
		i++;
	}
}

void	thread_tear(t_fractal *f)
{
	int i;

	pthread_create(&f->thread[0], NULL, filling_tear1, (void *)f);
	pthread_create(&f->thread[1], NULL, filling_tear2, (void *)f);
	pthread_create(&f->thread[2], NULL, filling_tear3, (void *)f);
	pthread_create(&f->thread[3], NULL, filling_tear4, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->thread[i], NULL);
		i++;
	}
}

void	thread_feigenbaum(t_fractal *f)
{
	int i;

	pthread_create(&f->thread[0], NULL, filling_feigenbaum1, (void *)f);
	pthread_create(&f->thread[1], NULL, filling_feigenbaum2, (void *)f);
	pthread_create(&f->thread[2], NULL, filling_feigenbaum3, (void *)f);
	pthread_create(&f->thread[3], NULL, filling_feigenbaum4, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->thread[i], NULL);
		i++;
	}
}

void	thread_burnjulia(t_fractal *f)
{
	int i;

	pthread_create(&f->thread[0], NULL, filling_burnjulia1, (void *)f);
	pthread_create(&f->thread[1], NULL, filling_burnjulia2, (void *)f);
	pthread_create(&f->thread[2], NULL, filling_burnjulia3, (void *)f);
	pthread_create(&f->thread[3], NULL, filling_burnjulia4, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->thread[i], NULL);
		i++;
	}
}
