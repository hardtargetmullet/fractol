/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anieto <anieto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:57:10 by anieto            #+#    #+#             */
/*   Updated: 2017/05/25 19:40:26 by anieto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "./mlibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "./libft/libft.h"
# include "./fractol.h"

# define WIDTH 640
# define HEIGHT 480
# define WHITE 0xFFFFFF
# define KEY_H 4
# define KEY_R 15
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_L 37
# define KEY_ESC 53
# define KEY_NUM_PAD_PLUS 69
# define KEY_NUM_PAD_MINUS 78
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_UP 126

struct t_window;

typedef struct	s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixels;
	int				frac_num;
	int				lsize;
	int				c;
	unsigned int	lock;
	unsigned int	max_iter;
	unsigned int	hud;
	unsigned int	x_mouse;
	unsigned int	y_mouse;
	long double		c_im;
	long double		c_re;
	long double		zoom;
	long double		move_x;
	long double		move_y;
	long double		factor_x;
	long double		factor_y;
	void			(*p_to_i)(int, int, struct s_window *, unsigned int);
	void			(*fun)(int, int, struct s_window *);
}				t_window;

void			draw(t_window *win);

void			mandelbrot(int x, int y, t_window *win);
void			julia(int x, int y, t_window *win);
void			burning(int x, int y, t_window *win);
void			eye_gasm(int x, int y, t_window *win);
void			butter_fly(int x, int y, t_window *win);
void			negative(int x, int y, t_window *win);
void			bikini(int x, int y, t_window *win);
void			tri_force(int x, int y, t_window *win);
void			burning_julia(int x, int y, t_window *win);

void			ptoi(int x, int y, t_window *win, unsigned int iter);
void			ptoi_2(int x, int y, t_window *win, unsigned int iter);
void			ptoi_3(int x, int y, t_window *win, unsigned int iter);
void			ptoi_4(int x, int y, t_window *win, unsigned int iter);

void			display_hud(t_window *w);
void			display_hud_2(t_window *w);

void			change_color(t_window *win, int key);

int				key_event(int key, t_window *win);

int				mouse_wheel(int button, int x, int y, t_window *win);
int				mouse_move_event(int x, int y, t_window *win);

int				exit_bacon(t_window *win);

#endif
