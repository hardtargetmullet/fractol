/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:28:57 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 18:35:12 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void		lock_reset_zoom(t_window *win, int key)
{
	if (key == KEY_R)
	{
		win->max_iter = 256;
		win->zoom = 1.0;
		win->move_x = -0.5;
		win->move_y = 0.0;
		win->factor_x = 0;
		win->factor_y = 0;
	}
	else if (key == KEY_PLUS)
		win->zoom *= 1.32;
	else if (key == KEY_MINUS)
		win->zoom /= 1.32;
	else if (key == KEY_L)
	{
		if (win->lock)
			win->lock = 0;
		else
			win->lock = 1;
	}
	mlx_destroy_image(win->mlx, win->img);
	draw(win);
}

static void		iter_up_or_down(t_window *win, int key)
{
	if (key == KEY_NUM_PAD_PLUS)
	{
		if (win->max_iter < 1000 && win->max_iter >= 10)
			win->max_iter += 10;
		else if (win->max_iter < 10)
			win->max_iter++;
	}
	else if (key == KEY_NUM_PAD_MINUS)
	{
		if (win->max_iter > 20)
			win->max_iter -= 10;
		else if (win->max_iter > 2)
			win->max_iter--;
	}
	mlx_destroy_image(win->mlx, win->img);
	draw(win);
}

static void		displace_with_arrows(t_window *win, int key)
{
	if (key == KEY_ARROW_LEFT)
		win->move_x += 50 / win->zoom;
	else if (key == KEY_ARROW_RIGHT)
		win->move_x -= 50 / win->zoom;
	else if (key == KEY_ARROW_DOWN)
		win->move_y += 50 / win->zoom;
	else if (key == KEY_ARROW_UP)
		win->move_y -= 50 / win->zoom;
	mlx_destroy_image(win->mlx, win->img);
	draw(win);
}

static void		change_fractol(t_window *win, int key)
{
	if (key != 24 || key != 27)
	{
		if (key == 18)
			win->fun = &mandelbrot;
		else if (key == 19)
			win->fun = &julia;
		else if (key == 20)
			win->fun = &burning;
		else if (key == 21)
			win->fun = &eye_gasm;
		else if (key == 23)
			win->fun = &butter_fly;
		else if (key == 22)
			win->fun = &negative;
		else if (key == 26)
			win->fun = &bikini;
		else if (key == 28)
			win->fun = &tri_force;
		else if (key == 25)
			win->fun = &burning_julia;
		mlx_destroy_image(win->mlx, win->img);
		draw(win);
	}
}

int				key_event(int key, t_window *win)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_H)
	{
		if (win->hud == 0)
			win->hud = 1;
		else if (win->hud == 1)
			win->hud = 2;
		else
			win->hud = 0;
		mlx_destroy_image(win->mlx, win->img);
		draw(win);
	}
	else if (key >= 18 && key <= 28 && key != 27 && key != 24)
		change_fractol(win, key);
	else if (key == 15 || key == 24 || key == 27 || key == 37)
		lock_reset_zoom(win, key);
	else if (key == 69 || key == 78)
		iter_up_or_down(win, key);
	else if (key >= 82 && key <= 86)
		change_color(win, key);
	else if (key >= KEY_ARROW_LEFT && key <= KEY_ARROW_UP)
		displace_with_arrows(win, key);
	return (1);
}
