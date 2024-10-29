# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 10:19:07 by rroussel          #+#    #+#              #
#    Updated: 2023/05/04 12:45:33 by rroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS :=	fractol.c\
		srcs/draw.c\
		srcs/draw_julia.c\
		srcs/draw_mandelbrot.c\
		srcs/event.c\
		srcs/hooks_handler.c\
		srcs/parsing.c

B_SRCS :=	bonus/fractol_bonus.c\
			srcs/draw.c\
			srcs/draw_julia.c\
			srcs/draw_mandelbrot.c\
			bonus/draw_tricorn.c\
			bonus/event_bonus.c\
			bonus/hooks_handler_bonus.c\
			bonus/parsing_bonus.c

LIBFT := ./libft/libft.a
MLX := ./mlx/libmlx.a
NAME := fract-ol
CC := cc
HEADERS := ./includes/fractol.h
B_HEADERS := ./bonus/fractol_bonus.h
CFLAGS := -Wall -Wextra -Werror
UFLAGS := -lX11 -lXext -lm -lz
OBJS := $(SRCS:.c=.o)
B_OBJS := $(B_SRCS:.c=.o)
RM := /bin/rm -f

.ONESHELL:

$(NAME):	  $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(UFLAGS) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "Fract-ol compiled"

$(LIBFT):
	@echo "Compiling libft"
	$(MAKE) -C libft bonus -s

$(MLX):
	@echo "Compiling mlx"
	$(MAKE) -C mlx -s

%.o : %.c $(HEADERS)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@
	# @sleep .3
	# @printf "\033[1A"
	# @printf "\033[K"

all:	$(NAME)

bonus:	$(MLX) $(LIBFT) $(B_OBJS) $(B_HEADERS)
	@$(CC) $(UFLAGS) $(CFLAGS) $(B_OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "Fract-ol bonuses compiled"

clean:
	@echo "Cleaning files..."
	@$(RM) $(OBJS) $(B_OBJS)
	@$(MAKE) -C libft clean -s
	@$(MAKE) -C mlx clean -s

fclean:	clean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME) $(B_NAME)
	@$(MAKE) -C libft fclean -s

re:	fclean all
	@echo "re-make finish"

.PHONY: bonus clean fclean re all
.SILENT: