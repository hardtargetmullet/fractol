/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:15:41 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 19:29:21 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void	fractol_this_shit(t_window *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			(win->fun)(x, y, win);
			++x;
		}
		++y;
	}
}

void		draw(t_window *win)
{
	int		bpp;
	int		ed;

	win->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->pixels = mlx_get_data_addr(win->img, &bpp, &(win->lsize), &ed);
	fractol_this_shit(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	if (win->hud == 1)
		display_hud(win);
	if (win->hud == 2)
		display_hud_2(win);
	mlx_loop(win->mlx);
}
