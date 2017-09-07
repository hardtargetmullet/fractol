/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracs_set_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:02:40 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 18:43:23 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	butter_fly(int x, int y, t_window *win)
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
	win->c_re = fabsl(win->c_re);
	win->c_im = win->c_im / win->c_re;
	while (za * za + zb * zb < 4 && iter < win->max_iter)
	{
		tmp = za;
		za = tmp * tmp - zb * zb + win->c_re;
		zb = 2 * tmp * zb + win->c_im;
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}

void	eye_gasm(int x, int y, t_window *win)
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
	win->c_re = fabsl(win->c_re);
	win->c_im = fabsl(win->c_im);
	while (za * za + zb * zb < 4 && iter < win->max_iter)
	{
		tmp = za;
		za = tmp * tmp - zb * zb + win->c_re;
		zb = 2 * tmp * zb + win->c_im;
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}

void	burning(int x, int y, t_window *win)
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
		za = fabsl(tmp * tmp - zb * zb + win->c_re);
		zb = fabsl(2 * tmp * zb + win->c_im);
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}

void	julia(int x, int y, t_window *win)
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
		za = tmp * tmp - zb * zb + win->c_re;
		zb = 2 * tmp * zb + win->c_im;
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}

void	mandelbrot(int x, int y, t_window *win)
{
	unsigned int	iter;
	long double		za;
	long double		zb;
	long double		tmp;

	iter = 0;
	za = 0.0 + win->factor_x;
	zb = 0.0 + win->factor_y;
	win->c_re = 1.5 * (x - WIDTH / 2) /
	(0.5 * win->zoom * WIDTH) + (win->move_x / WIDTH / 1.32) - 0.5;
	win->c_im = (y - HEIGHT / 2) /
	(0.5 * win->zoom * HEIGHT) - (win->move_y / HEIGHT / 1.92);
	while (za * za + zb * zb < 4 && iter < win->max_iter)
	{
		tmp = za;
		za = tmp * tmp - zb * zb + win->c_re;
		zb = 2 * tmp * zb + win->c_im;
		++iter;
	}
	(win->p_to_i)(x, y, win, iter);
}
