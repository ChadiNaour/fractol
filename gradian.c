/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradian.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 02:58:44 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/27 15:50:50 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_gradian(int ind, int max, int col1, int col2)
{
	double	per;
	int		r;
	int		g;
	int		b;

	per = (double)ind / max;
	r = (col1 >> 16) & 0xff;
	g = (col1 >> 8) & 0xff;
	b = col1 & 0xff;
	r = r + (int)(((col2 >> 16) & 0xff) - r) * per;
	g = g + (int)(((col2 >> 8) & 0xff) - g) * per;
	b = b + (int)((col2 & 0xff) - b) * per;
	return ((r << 16) | (g << 8) | b);
}

void	create_gradian(int *tab, int col1, int col2, int col3)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		tab[i] = get_gradian(i, 20, col1, col2);
		i++;
	}
	while (i < 50)
	{
		tab[i] = get_gradian(i - 20, 30, col2, col3);
		i++;
	}
}
