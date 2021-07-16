# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 15:10:33 by spoliart          #+#    #+#              #
#    Updated: 2021/07/16 16:50:18 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

_SRCS_P = main.c \
		error.c \
		lst.c \
		parse.c \
		ps_atoi.c \
		stack.c \
		s.c \
		p.c \
		r.c \
		rr.c

SRCS_P_DIR = srcs
SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCO_P = $(SRCS_P:.c=.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all: $(NAME_P)

$(NAME_P): $(SRCO_P)
	make -C libft
	gcc $(SRCO_P) -Llibft -lft -o $(NAME_P)

%.o: %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean:
	make clean -C libft
	rm -f $(SRCO_P)

fclean: clean
	make fclean -C libft
	rm -f $(NAME_P)

re:
	make fclean
	make
