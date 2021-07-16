/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:08:07 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/16 15:38:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_env *env)
{
	t_stack *tmp;
	t_stack *last;

	if (!(env->a) || !(env->a->next))
		return ;
	tmp = env->a;
	env->a = env->a->next;
	env->a->prev = NULL;
	last = stack_last(env->a);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

void	rb(t_env *env)
{
	t_stack *tmp;
	t_stack *last;

	if (!(env->b) || !(env->b->next))
		return ;
	tmp = env->b;
	env->b = env->b->next;
	env->b->prev = NULL;
	last = stack_last(env->b);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

void	rr(t_env *env)
{
	ra(env);
	rb(env);
}
