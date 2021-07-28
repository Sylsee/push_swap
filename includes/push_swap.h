/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:22:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:41:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <strings.h>
# include <stdio.h>

typedef enum moves
{
	none,
	sa,
	sb,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb
}				t_moves;

typedef struct s_stack
{
	int				n;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct s_env
{
	int		size;
	char	**cmd;
	t_stack	*a;
	t_stack	*b;
}				t_env;

int				main(int ac, char **av);
void			print_and_exit(char *s);
t_stack			*ps_parse(int ac, char **av);
t_stack			*ps_new_node(t_stack **lst, char *n);
int				create_lst(char *av, t_stack **lst);
void			ps_free_lst(t_stack *lst);
int				ps_atoi(char *s, int *err);
t_stack			*stack_last(t_stack *stack);
void			print_stacks(t_stack *a, t_stack *b);
int				stack_size(t_stack *s);
int				stack_is_sorted(t_stack *a);
void			s(t_stack **a, e_moves moves);
void			ss(t_env **env);
void			p(t_stack **a, t_stack **b, e_moves moves);
void			r(t_stack **a, e_moves moves);
void			rr(t_env **env);
void			re(t_stack **a, e_moves moves);
void			rre(t_env **env);
void			radix_sort(t_env **env);
void			three_solution(t_env **env);

#endif
