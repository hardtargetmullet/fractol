/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:19:30 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 18:19:42 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int		mouse_move_event(int x, int y, t_window *win)
{
	win->x_mouse = x;
	win->y_mouse = y;
	if (win->lock == 0)
	{
		win->factor_x = x * .5 / (HEIGHT / 2);
		win->factor_y = y * .5 / (WIDTH / 2);
	}
	mlx_destroy_image(win->mlx, win->img);
	draw(win);
	return (1);
}

int		mouse_wheel(int button, int x, int y, t_window *win)
{
	if (y > 0 && y < HEIGHT && x > 0 && x < WIDTH)
	{
		if (button == 5 || button == 1)
		{
			x -= WIDTH / 2;
			y -= HEIGHT / 2;
			win->zoom *= 1.1;
			win->move_x += x / win->zoom / 2.2;
			win->move_y -= y / win->zoom / 1.8;
		}
		else if (button == 4 || button == 2)
		{
			win->zoom /= (win->zoom > 0.1 ? 1.1 : 1);
		}
	}
	mlx_destroy_image(win->mlx, win->img);
	draw(win);
	return (1);
}
