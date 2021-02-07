/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:42:16 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 21:48:31 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	background_all(t_fractal *f)
{
	t_point	start;
	t_point	end;

	start = (t_point){.x = 10.0, .y = 615.0};
	end = (t_point){.x = 280.0, .y = 790.0};
	while (start.y < end.y)
	{
		start.x = 10.0;
		while (start.x < end.x)
		{
			f->img_data[(int)start.x + ((int)start.y * W)] = ((start.x == 10.0)
					|| (start.x == end.x - 1) || (start.y == end.y - 1) ||
					(start.y == 615.0)) ? 0xFFFFFF : 0xb3000000;
			start.x++;
		}
		start.y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	background(t_fractal *f)
{
	t_point	start;
	t_point	end;

	start = (t_point){.x = 820.0, .y = 10.0};
	end = (t_point){.x = 990.0, .y = 35.0};
	while (start.y < end.y)
	{
		start.x = 820.0;
		while (start.x < end.x)
		{
			f->img_data[(int)start.x + ((int)start.y * W)] = ((start.x == 820.0)
					|| (start.x == end.x - 1) || (start.y == end.y - 1) ||
					(start.y == 10.0)) ? 0xFFFFFF : 0xb3000000;
			start.x++;
		}
		start.y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	menu(t_fractal *f)
{
	if (f->fractal_nbr == 2)
		mlx_string_put(f->mlx_ptr, f->win_ptr,
				830, 12, 0xffffff, "MOVE/FREEZE : J");
	if (f->fractal_nbr == 6)
		mlx_string_put(f->mlx_ptr, f->win_ptr,
				830, 12, 0xffffff, "MOVE/FREEZE : F");
	if (f->fractal_nbr == 7)
		mlx_string_put(f->mlx_ptr, f->win_ptr,
				830, 12, 0xffffff, "MOVE/FREEZE : B");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			620, 0xffffff, "RESET       :       R ");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			640, 0xffffff, "ITER       :   PLUS/MINUS ");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			660, 0xffffff, "MOVE        :      ARROWS");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			680, 0xffffff, "ZOOM      :   MOUSE WHEEL");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			700, 0xffffff, "NEXT FRACTAL   :     C");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			720, 0xffffff, "CHANGE COLOR   : SPACE");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			740, 0xffffff, "CHANGE METHODE :     M");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 20,
			760, 0xffffff, "EXIT           :   ESC");
}

void	backgrounding(t_fractal *f)
{
	if (f->fractal_nbr == 2 || f->fractal_nbr == 6 || f->fractal_nbr == 7)
		background(f);
	background_all(f);
}
