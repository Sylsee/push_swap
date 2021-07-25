/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:22:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 03:00:59 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <strings.h>
# include <stdio.h>

typedef struct s_stack
{
	int				n;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct s_env
{
	int		size;
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
void			sa(t_env **env);
void			sb(t_env **env);
void			ss(t_env **env);
void			pa(t_env **env);
void			pb(t_env **env);
void			ra(t_env **env);
void			rb(t_env **env);
void			rr(t_env **env);
void			rra(t_env **env);
void			rrb(t_env **env);
void			rrr(t_env **env);

#endif
