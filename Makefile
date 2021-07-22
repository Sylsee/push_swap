# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 15:10:33 by spoliart          #+#    #+#              #
#    Updated: 2021/07/22 22:19:49 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	main.c \
		error.c \
		lst.c \
		parse.c \
		ps_atoi.c \
		stack.c \
		s.c \
		p.c \
		r.c \
		rr.c

DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/
OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(OBJS) -Llibft -lft -o $(NAME)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	gcc $(FLAG) $(INC) -c $< -o $@

$(OBJS): | $(DIR_OBJS)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	make clean -C libft
	rm -rf $(DIR_OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re:
	make fclean
	make

norme:
	norminette includes srcs
