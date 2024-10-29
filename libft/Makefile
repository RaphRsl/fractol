# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:41:09 by rroussel          #+#    #+#              #
#    Updated: 2023/04/06 11:16:57 by rroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atof.c ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c\
ft_atol.c ft_isdouble.c ft_isint.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstdelnode_addr.c\
ft_lstdelnode_value.c ft_lstsort.c get_next_line.c get_next_line_utils.c

OBJS = $(SRC:.c=.o)

OBJSBONUS = $(BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)

.c.o:
		gcc $(CFLAGS) -g -c $< -o $(<:.c=.o)

bonus:	$(OBJS) $(OBJSBONUS)
		ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

clean:
		rm -f $(OBJS) $(OBJSBONUS)
so:
	gcc -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJSBONUS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean bonus fclean re
