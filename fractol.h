/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractiol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:47:34 by cnaour            #+#    #+#             */
/*   Updated: 2019/11/28 16:53:03 by cnaour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define H 800
# define W 1000
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef	struct	s_point
{
	int x;
	int y;
}				t_point;

typedef	struct	s_rgb
{
	double r;
	double g;
	double b;
}				t_rgb;

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

typedef	struct	s_limit
{
	double remin;
	double remax;
	double immax;
	double immin;
}				t_limit;

typedef	struct	s_color
{
	t_rgb	t[3];
	t_rgb	t2[3];
	int		tab[50];
	int		tab1[50];
	int		tab2[50];
	int		m;
	int		i;
	int		j;
	int		k;
}				t_color;

typedef	struct	s_julia
{
	int			move;
	int			start;
	t_complex	c;
}				t_julia;

typedef	struct	s_feigenbaum
{
	int			move;
	int			start;
	double		v;
	double		xm;
	double		ym;
	t_complex	c;
}				t_feigenbaum;

typedef struct	s_fractal
{
	int				fractal_nbr;
	void			*img_ptr;
	void			*img_ptr2;
	void			*mlx_ptr;
	int				*img_data;
	void			*win_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				n;
	double			mousere;
	double			mouseim;
	double			zoomfactor;
	int				max_iter;
	t_julia			j;
	t_julia			bj;
	t_feigenbaum	f;
	t_limit			limit;
	t_color			c;
	pthread_t		thread[4];
}				t_fractal;

int				ft_strcmp(const char *s1, const char *s2);
double			maptoimg(int y, int imgheight, double mini, double maxi);
double			maptoreal(int x, int imgwidth, double minr, double maxr);
void			*filling_man1(void *t);
void			*filling_man2(void *t);
void			*filling_man3(void *t);
void			*filling_man4(void *t);
void			thread_man(t_fractal *f);
void			*filling_julia1(void *t);
void			*filling_julia2(void *t);
void			*filling_julia3(void *t);
void			*filling_julia4(void *t);
void			thread_julia(t_fractal *f);
void			*filling_burn1(void *t);
void			*filling_burn2(void *t);
void			*filling_burn3(void *t);
void			*filling_burn4(void *t);
void			thread_burn(t_fractal *f);
void			*filling_tri1(void *t);
void			*filling_tri2(void *t);
void			*filling_tri3(void *t);
void			*filling_tri4(void *t);
void			thread_tri(t_fractal *f);
void			*filling_tear1(void *t);
void			*filling_tear2(void *t);
void			*filling_tear3(void *t);
void			*filling_tear4(void *t);
void			thread_tear(t_fractal *f);
void			define_limits(t_fractal *f);
void			*filling_feigenbaum1(void *t);
void			*filling_feigenbaum2(void *t);
void			*filling_feigenbaum3(void *t);
void			*filling_feigenbaum4(void *t);
void			thread_feigenbaum(t_fractal *f);
void			*filling_burnjulia1(void *t);
void			*filling_burnjulia2(void *t);
void			*filling_burnjulia3(void *t);
void			*filling_burnjulia4(void *t);
void			thread_burnjulia(t_fractal *f);
int				mouse_move(int x, int y, t_fractal *f);
void			put_fractal(t_fractal *f);
void			fractal_chosing(t_fractal *f, char *name);
void			color(t_rgb *t, t_rgb *t2);
int				get_color(t_color *c, int n, t_fractal *f);
void			change_fractal(t_fractal *f);
void			fractal_filling(t_fractal *f);
int				key_press(int keycode, t_fractal *f);
void			color_change(int *i);
void			menu(t_fractal *f);
void			backgrounding(t_fractal *f);
int				mouse_press(int button, int x, int y, t_fractal *f);
void			create_gradian(int *tab, int col1, int col2, int col3);
void			usage(void);
void			my_close(t_fractal *f);
void			help2(int keycode, t_fractal *f);
void			help(int keycode, t_fractal *f);
void			arrows(int keycode, t_limit *l);
void			help3(int keycode, t_fractal *f);

#endif
