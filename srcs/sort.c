/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 03:25:25 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:35:28 by spoliart         ###   ########.fr       */
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

void	push_b_on_a(t_env **env)
{
	while ((*env)->b)
		p(&((*env)->b), &((*env)->a), pa);
}

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
				r(&((*env)->a), ra);
			else
				p(&((*env)->a), &((*env)->b), pb);
			j++;
		}
		while ((*env)->b)
			p(&((*env)->b), &((*env)->a), pa);
		i++;
	}
}

void	three_solution(t_env **env)
{
	int	first;
	int	second;
	int	third;

	first = (*env)->a->n;
	second = (*env)->a->next->n;
	third = (*env)->a->next->next->n;
	if (first > second && first < third && second < third)
		s(&((*env)->a), sa);
	else if (first > second && first > third && second < third)
		r(&((*env)->a), ra);
	else if (first < second && first > third && second > third)
		re(&((*env)->a), rra);
	else if (first > second && first > third && second > third)
	{
		s(&((*env)->a), sa);
		re(&((*env)->a), rra);
	}
	else if (first < second && first < third && second > third)
	{
		s(&((*env)->a), sa);
		r(&((*env)->a), ra);
	}
}
