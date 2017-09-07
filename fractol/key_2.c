/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:34:17 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 18:43:23 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void		change_color(t_window *win, int key)
{
	if (key == 82)
		++win->c;
	else if (key == 83)
		win->p_to_i = &ptoi;
	else if (key == 84)
		win->p_to_i = &ptoi_2;
	else if (key == 85)
		win->p_to_i = &ptoi_3;
	else if (key == 86)
		win->p_to_i = &ptoi_4;
	mlx_destroy_image(win->mlx, win->img);
	draw(win);
}
