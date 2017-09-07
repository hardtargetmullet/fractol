/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:54:30 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 19:44:55 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	ptoi_4(int x, int y, t_window *win, unsigned int i)
{
	int	j;
	int c[5];

	j = (4 * x) + (y * win->lsize);
	c[0] = 0xFF0000;
	c[1] = 0x0000FF;
	c[2] = 0x00FF00;
	c[3] = 0xFFFF00;
	c[4] = 0xFFAA00;
	if (i < win->max_iter)
	{
		win->pixels[j] = (i * ((c[win->c % 5] >> 16) & 0xFF)) / win->max_iter;
		win->pixels[++j] = (i * ((c[win->c % 5] >> 8) & 0xFF)) / win->max_iter;
		win->pixels[++j] = (i * ((c[win->c % 5]) & 0xFF)) / win->max_iter;
	}
	else
	{
		win->pixels[j] = 0x00;
		win->pixels[++j] = 0x00;
		win->pixels[++j] = 0x00;
	}
}

void	ptoi_3(int x, int y, t_window *win, unsigned int iter)
{
	int	i;

	i = (4 * x) + (y * win->lsize);
	if (iter < win->max_iter)
	{
		win->pixels[i] = 0x42 + iter;
		win->pixels[i + 1] = 0x00 + iter;
		win->pixels[i + 2] = 0x00 + iter;
	}
	else
	{
		win->pixels[i] = 0x00;
		win->pixels[i + 1] = 0x00;
		win->pixels[i + 2] = 0x00;
	}
}

void	ptoi_2(int x, int y, t_window *win, unsigned int iter)
{
	int i;

	i = (4 * x) + (y * win->lsize);
	if (iter < win->max_iter)
	{
		win->pixels[i] = (sin(iter + win->c / M_PI) + 1) * 255;
		win->pixels[i + 1] = (-cos(iter + win->c / M_PI) + 1) * 255;
		win->pixels[i + 2] = (-sin(iter + win->c / M_PI) + 1) * 255;
	}
	else
	{
		win->pixels[i] = 0x00;
		win->pixels[i + 1] = 0x00;
		win->pixels[i + 2] = 0x00;
	}
}

void	ptoi(int x, int y, t_window *win, unsigned int iter)
{
	int i;

	i = (4 * x) + (y * win->lsize);
	if (iter < win->max_iter)
	{
		win->pixels[i] = sin((float)iter / 6.0) * 100;
		win->pixels[i + 1] = -cos((float)iter / 9.0) * 100;
		win->pixels[i + 2] = cos((float)iter / 2.0 + 3.14 / 2.0) * 100;
	}
	else
	{
		win->pixels[i] = 0x00;
		win->pixels[i + 1] = 0x00;
		win->pixels[i + 2] = 0x00;
	}
}
