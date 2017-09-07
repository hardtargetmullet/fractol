# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anieto <anieto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 21:46:29 by anieto            #+#    #+#              #
#    Updated: 2017/05/25 19:33:47 by anieto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast

NAME   = fractol
SRCS   = fractol.c draw_fractol.c pixel_colors.c fracs_set_1.c fracs_set_2.c \
         key.c key_2.c mouse.c button.c hud.c
OBJS   = $(SRCS:.c=.o)
FWORK  = -framework OpenGL -framework AppKit
LIBS   = -L mlibx -lmlx
INCL   = -I ./mlibx

all: $(NAME)

libft/libft.a:
	make -C libft

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCL) $(LIBS) $(FWORK) libft/libft.a -o $(NAME)

$(OBJS): libft/libft.a
	$(CC) $(CFLAGS) $(SRCS) -c $(INCL)

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
