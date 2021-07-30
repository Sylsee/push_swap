/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 04:34:33 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/30 06:24:58 by spoliart         ###   ########.fr       */
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

static int	index_of_smaller(t_stack *a)
{
	int	i;
	int	index;
	int	min;

	i = 1;
	index = i;
	min = a->n;
	while (a)
	{
		if (min > a->n)
		{
			min = a->n;
			index = i;
		}
		i++;
		a = a->next;
	}
	return (index);
}

void	insertion_sort(t_env **env)
{
	int	i;
	int	half;
	int	index;

	i = 0;
	while ((*env)->a)
	{
		half = ((*env)->size - i) / 2;
		index = index_of_smaller((*env)->a);
		if (index <= half || (((*env)->size - i) % 2 && index - 1 == half))
			while (--index)
				r(&((*env)->a), ra);
		else
			while (index++ <= (*env)->size - i)
				re(&((*env)->a), rra);
		p(&((*env)->a), &((*env)->b), pb);
		i++;
	}
	while ((*env)->b)
		p(&((*env)->b), &((*env)->a), pa);
}
