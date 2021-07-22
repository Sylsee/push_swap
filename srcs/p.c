/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:51:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/22 22:16:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_env *env)
{
	t_stack	*tmp;

	if (!(env->b))
		return ;
	tmp = env->b->next;
	tmp->prev = NULL;
	env->b->next = env->a;
	env->a->prev = env->b;
	env->a = env->b;
	env->b = tmp;
}

void	pb(t_env *env)
{
	t_stack	*tmp;

	if (!(env->a))
		return ;
	tmp = env->a->next;
	tmp->prev = NULL;
	env->a->next = env->b;
	env->b->prev = env->a;
	env->b = env->a;
	env->a = tmp;
}
