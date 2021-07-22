/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:21:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/22 22:16:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_env *env)
{
	t_stack	*tmp;

	if (!(env->a) || !(env->a->next))
		return ;
	tmp = stack_last(env->a);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = env->a;
	env->a->prev = tmp;
	env->a = tmp;
}

void	rrb(t_env *env)
{
	t_stack	*tmp;

	if (!(env->b) || !(env->b->next))
		return ;
	tmp = stack_last(env->b);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = env->b;
	env->b->prev = tmp;
	env->b = tmp;
}

void	rrr(t_env *env)
{
	rra(env);
	rrb(env);
}
