/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracs_set_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:00:56 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 18:43:23 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	burning_julia(int x, int y, t_window *win)
{
	unsigned int	iter;
	long double		za;
	long double		zb;
	long double		tmp;

	iter = 0;
	win->c_re = -0.7 + win->factor_x;
	win->c_im = 0.27015 + win->factor_y;
	za = 1.5 * (x - WIDTH / 2) /
	(0.5 * win->zoom * WIDTH) + (win->move_x / WIDTH / 1.32);
	zb = (y - HEIGHT / 2) /
	(0.5 * win->zoom * HEIGHT) - (win->move_y / HEIGHT / 1.92);
	while (za * za + zb * zb < 4 && iter < win->max_iter)
	{
		tmp = za;
		za = fabsl(tmp * tmp - zb * zb + win->c_re);
		zb = fabsl(2 * tmp * zb + win->c_im);
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}

void	tri_force(int x, int y, t_window *win)
{
	unsigned int		iter;
	long double			z_re;
	long double			z_im;
	long double			z_re2;
	long double			z_im2;

	iter = 0;
	z_re = win->c_re + win->factor_y;
	z_im = win->c_im + win->factor_x;
	z_re2 = 0;
	z_im2 = 0;
	win->c_im = (y - HEIGHT / 2) /
							(0.5 * win->zoom * HEIGHT) - (win->move_y / HEIGHT);
	win->c_re = 1.5 * (x - WIDTH / 2) /
							(0.5 * win->zoom * WIDTH) + (win->move_x / WIDTH);
	while (z_re2 + z_im2 < 4.0 && iter < win->max_iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		z_re = 2 * z_re * z_im + win->c_re;
		z_im = (z_re2) - (z_im2) + win->c_im;
		iter++;
	}
	(win->p_to_i)(x, y, win, iter);
}

void	bikini(int x, int y, t_window *win)
{
	unsigned int	iter;
	long double		za;
	long double		zb;
	long double		tmp;

	iter = 0;
	za = 0.0 + win->factor_x;
	zb = 0.0 + win->factor_y;
	win->c_im = (y - HEIGHT / 2) /
	(0.5 * win->zoom * HEIGHT) - (win->move_y / HEIGHT / 1.55);
	win->c_re = 1.5 * (x - WIDTH / 2) /
	(0.5 * win->zoom * WIDTH) + (win->move_x / WIDTH / 1.25);
	while (za * za + zb * zb < 4 && iter < win->max_iter)
	{
		tmp = za;
		zb = tmp * tmp - zb * zb + win->c_im;
		za = 2 * tmp * zb + win->c_re;
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}

void	negative(int x, int y, t_window *win)
{
	unsigned int	iter;
	long double		za;
	long double		zb;
	long double		tmp;

	iter = 0;
	za = 0.0 + win->factor_x;
	zb = 0.0 + win->factor_y;
	win->c_re = 1.5 * (x - WIDTH / 2) /
	(0.5 * win->zoom * WIDTH) + (win->move_x / WIDTH / 1.32);
	win->c_im = (y - HEIGHT / 2) /
	(0.5 * win->zoom * HEIGHT) - (win->move_y / HEIGHT / 1.92);
	while (za * za + zb * zb < 4 && iter < win->max_iter)
	{
		tmp = za;
		za = tmp * tmp - zb * zb + sin(win->c_re);
		zb = 2 * tmp * zb + -sin(win->c_im);
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}
