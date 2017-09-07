/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 01:36:58 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 19:31:59 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void		usage(void)
{
	write(1, "./fracol [name_of_fractol / number]\n"
	"          mandelbrot      / 1\n"
	"          julia           / 2\n"
	"          burning         / 3\n"
	"          eye             / 4\n"
	"          butterfly       / 5\n"
	"          negative        / 6\n"
	"          bikini          / 7\n"
	"          tri_force       / 8\n"
	"          burning_julia   / 9\n", 306);
	exit(0);
}

static int		make_america(char *name)
{
	int ret;

	ret = 0;
	if (ft_strcmp(name, "1") == 0 || ft_strcmp(name, "mandelbrot") == 0)
		ret = 1;
	else if (ft_strcmp(name, "2") == 0 || ft_strcmp(name, "julia") == 0)
		ret = 2;
	else if (ft_strcmp(name, "3") == 0 || ft_strcmp(name, "burning") == 0)
		ret = 3;
	else if (ft_strcmp(name, "4") == 0 || ft_strcmp(name, "eye") == 0)
		ret = 4;
	else if (ft_strcmp(name, "5") == 0 || ft_strcmp(name, "butterfly") == 0)
		ret = 5;
	else if (ft_strcmp(name, "6") == 0 || ft_strcmp(name, "negative") == 0)
		ret = 6;
	else if (ft_strcmp(name, "7") == 0 || ft_strcmp(name, "bikini") == 0)
		ret = 7;
	else if (ft_strcmp(name, "8") == 0 || ft_strcmp(name, "tri_force") == 0)
		ret = 8;
	else if (ft_strcmp(name, "9") == 0 || ft_strcmp(name, "burning_julia") == 0)
		ret = 9;
	return (ret);
}

static void		great_again(t_window *win)
{
	if (win->frac_num == 1)
		win->fun = &mandelbrot;
	else if (win->frac_num == 2)
		win->fun = &julia;
	else if (win->frac_num == 3)
		win->fun = &burning;
	else if (win->frac_num == 4)
		win->fun = &eye_gasm;
	else if (win->frac_num == 5)
		win->fun = &butter_fly;
	else if (win->frac_num == 6)
		win->fun = &negative;
	else if (win->frac_num == 7)
		win->fun = &bikini;
	else if (win->frac_num == 8)
		win->fun = &tri_force;
	else if (win->frac_num == 9)
		win->fun = &burning_julia;
	else
		usage();
}

static void		init_me(t_window *win)
{
	win->max_iter = 256;
	win->zoom = .5;
	win->c = 0;
	win->move_x = -0.5;
	win->move_y = 0.0;
	win->factor_x = 0;
	win->factor_y = 0;
	win->lock = 1;
	win->hud = 0;
	win->p_to_i = &ptoi;
	win->x_mouse = WIDTH / 2;
	win->y_mouse = HEIGHT / 2;
}

int				main(int argc, char **argv)
{
	t_window *win;

	if (argc != 2)
		usage();
	win = (t_window *)ft_memalloc(sizeof(t_window));
	win->frac_num = make_america(argv[1]);
	great_again(win);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "FRACTOL");
	init_me(win);
	mlx_hook(win->win, 2, 3, key_event, win);
	mlx_hook(win->win, 6, 0, mouse_move_event, win);
	mlx_hook(win->win, 4, 2, mouse_wheel, win);
	mlx_hook(win->win, 17, 0, exit_bacon, win);
	draw(win);
	return (0);
}
