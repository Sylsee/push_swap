/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 04:23:40 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/30 19:08:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	p(&((*env)->a), &((*env)->b));
	p(&((*env)->b), &((*env)->a));
	s(&((*env)->a));
	s(&((*env)->b));
	ss(&(*env));
	r(&((*env)->a));
	r(&((*env)->b));
	rr(&(*env));
	re(&((*env)->a));
	re(&((*env)->b));
	rre(&(*env));
	print_stacks((*env)->a, (*env)->b);
 */

static void	invert_negative(t_env **env)
{
	int	i;

	i = 0;
	while (i < (*env)->size)
	{
		if (!(((*env)->a->n >> 31) & 1))
			r(&((*env)->a), ra);
		else
			p(&((*env)->a), &((*env)->b), pb);
		i++;
	}
	while ((*env)->b)
		p(&((*env)->b), &((*env)->a), pa);
}

void	radix_sort(t_env **env)
{
	int	i;
	int	j;
	int	negative;

	i = 0;
	negative = 0;
	while (!(stack_is_sorted((*env)->a)))
	{
		j = 0;
		while (j < (*env)->size)
		{
			if (((*env)->a->n >> 31) & 1)
				negative = 1;
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
	if (negative)
		invert_negative(env);
}
