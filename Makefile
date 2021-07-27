# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 15:10:33 by spoliart          #+#    #+#              #
#    Updated: 2021/07/27 03:22:31 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m
_YELLOW		=	\e[33m

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

FLAGS = -g -O0 -Wall -Wextra -Werror
INC = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	gcc $(FLAGS) $(OBJS) -Llibft -lft -o $(NAME)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	gcc $(FLAGS) $(INC) -c $< -o $@

$(OBJS): | $(DIR_OBJS)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

clean:
	@make clean -C libft
	@rm -rf $(DIR_OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re:
	@make fclean
	@make

norme:
	@norminette includes srcs

# @ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $(ARG)
# @ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; time ./push_swap $(ARG)
# @ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $(ARG) | wc -l
