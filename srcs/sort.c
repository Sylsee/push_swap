/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 03:25:25 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 05:02:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	p(&(env->a), &(env->b));
	p(&(env->b), &(env->a));
	s(&(env->a));
	s(&(env->b));
	ss(&env);
	r(&(env->a));
	r(&(env->b));
	rr(&env);
	re(&(env->a));
	re(&(env->b));
	rre(&env);
	print_stacks(env->a, env->b);
 */

void	radix_sort(t_env **env)
{
	int	i;
	int	j;

	i = 0;
	while (!(stack_is_sorted((*env)->a)))
	{
		j = 0;
		while (j < (*env)->size)
		{
			if (((*env)->a->n >> i) & 1)
			{
				r(&((*env)->a));
				printf("ra\n");
			}
			else
			{
				p(&((*env)->a), &((*env)->b));
				printf("pb\n");
			}
			j++;
		}
		while ((*env)->b)
			p(&((*env)->b), &((*env)->a));
		i++;
	}
}
