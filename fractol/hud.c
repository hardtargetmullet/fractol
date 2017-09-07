/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:13:03 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 19:28:27 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	display_hud(t_window *w)
{
	char	*msg;
	char	*msg2;
	char	*msg3;
	char	*msg4;
	char	msg5[2][10];

	msg = ft_ltoa_base(floor(w->zoom), 10);
	msg2 = ft_itoa(w->max_iter);
	msg3 = ft_itoa(w->x_mouse);
	msg4 = ft_itoa(w->y_mouse);
	snprintf(msg5[0], 10, "%Lf", w->c_im);
	snprintf(msg5[1], 10, "%Lf", w->c_re);
	mlx_string_put(w->mlx, w->win, 10, 10, WHITE, ft_strjoin("zoom = ", msg));
	mlx_string_put(w->mlx, w->win, 10, 30, WHITE, ft_strjoin("iter = ", msg2));
	mlx_string_put(w->mlx, w->win, 10, 50, WHITE, ft_strjoin("FPS  = ",
	ft_itoa(rand() % (60 + 1) + 1)));
	mlx_string_put(w->mlx, w->win, 10, 70, WHITE, ft_strjoin("ping = ", "5ms"));
	mlx_string_put(w->mlx, w->win, 10, 90, WHITE, ft_strjoin("X: ", msg3));
	mlx_string_put(w->mlx, w->win, 10, 110, WHITE, ft_strjoin("Y: ", msg4));
	mlx_string_put(w->mlx, w->win, 10, 130, WHITE, ft_strjoin("re: ", msg5[0]));
	mlx_string_put(w->mlx, w->win, 10, 150, WHITE, ft_strjoin("i:  ", msg5[1]));
	free(msg);
	free(msg2);
	free(msg3);
	free(msg4);
}

void	display_hud_2(t_window *w)
{
	char	*msg;

	msg = "ARROWS: move up/down/left/right";
	mlx_string_put(w->mlx, w->win, 10, 10, WHITE, msg);
	msg = "R: reset fractol";
	mlx_string_put(w->mlx, w->win, 10, 30, WHITE, msg);
	msg = "L: lock parameter";
	mlx_string_put(w->mlx, w->win, 10, 50, WHITE, msg);
	msg = "H: toggle hud";
	mlx_string_put(w->mlx, w->win, 10, 70, WHITE, msg);
	msg = "ESC: quit";
	mlx_string_put(w->mlx, w->win, 10, 90, WHITE, msg);
	msg = "1 - 9: change fractol";
	mlx_string_put(w->mlx, w->win, 10, 110, WHITE, msg);
	msg = "KEYPAD: +/- zoom in/out";
	mlx_string_put(w->mlx, w->win, 10, HEIGHT - 90, WHITE, msg);
	msg = "MOUSEWHEEL: [UP] zoom in/ [DOWN] zoom out";
	mlx_string_put(w->mlx, w->win, 10, HEIGHT - 70, WHITE, msg);
	msg = "NUMPAD: +/- increase/decrease iterations";
	mlx_string_put(w->mlx, w->win, 10, HEIGHT - 50, WHITE, msg);
	msg = "LEFTCLICK: zoom in, RIGHTCLICK: zoom out";
	mlx_string_put(w->mlx, w->win, 10, HEIGHT - 30, WHITE, msg);
}
