/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:22:08 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 18:22:24 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int		exit_bacon(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}
