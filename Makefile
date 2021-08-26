# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 15:10:33 by spoliart          #+#    #+#              #
#    Updated: 2021/08/26 02:34:10 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m

_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m

PUSH_SWAP =	push_swap
CHECKER	=	checker

SRCS_P =	push_swap.c \
			error.c \
			lst.c \
			parse.c \
			ps_atoi.c \
			stack.c \
			s.c \
			p.c \
			r.c \
			rr.c \
			three_sort.c \
			short_sort.c \
			radix_sort.c \
			insertion_sort.c \
			quick_sort.c \
			prepare_quick_sort.c

SRCS_C =	checker.c \
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
OBJS_P = $(SRCS_P:%.c=$(DIR_OBJS)%.o)
OBJS_C = $(SRCS_C:%.c=$(DIR_OBJS)%.o)

FLAGS = -g -Wall -Wextra -Werror
INC = -I includes/
LIBFT = libft/libft.a

all: $(LIBFT) $(PUSH_SWAP) $(CHECKER)

$(LIBFT):
	@make -C libft

$(PUSH_SWAP): $(OBJS_P)
	@printf "\033[2K\r$(_GREEN) All push_swap files compiled into '$(DIR_OBJS)'. $(_END)✅\n"
ifeq (,$(wildcard ./libft/libft.a))
	@make -C libft
endif
	@gcc $(FLAGS) $(OBJS_P) $(INC) $(LIBFT) -o $(PUSH_SWAP)
	@printf "$(_GREEN) Binary '$(PUSH_SWAP)' created. $(_END)✅\n"

$(CHECKER): $(OBJS_C)
	@printf "\033[2K\r$(_GREEN) All checker files compiled into '$(DIR_OBJS)'. $(_END)✅\n"
ifeq (,$(wildcard ./libft/libft.a))
	@make -C libft
endif
	@gcc $(FLAGS) $(OBJS_C) $(INC) $(LIBFT) -o $(CHECKER)
	@printf "$(_GREEN) Binary '$(CHECKER)' created. $(_END)✅\n"

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"
	@gcc $(FLAGS) $(INC) -c $< -o $@

$(OBJS_P): | $(DIR_OBJS)

$(OBJS_C): | $(DIR_OBJS)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

clean:
	@make clean -C libft
	@rm -rf $(DIR_OBJS)
	@printf "$(_RED) '$(DIR_OBJS)' has been deleted. $(_END)🗑️\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(PUSH_SWAP) $(CHECKER)
	@printf "$(_RED) '$(PUSH_SWAP)' and '$(CHECKER)' has been deleted. $(_END)🗑️\n"

re:
	@make fclean
	@make

norme:
	@norminette includes srcs

# @ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $(ARG)
# @ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; time ./push_swap $(ARG)
# @ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $(ARG) | wc -l
