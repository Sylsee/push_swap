/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:39:27 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/01 00:35:07 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	p(&((*env)->a), &((*env)->b), pb);
	p(&((*env)->b), &((*env)->a), pa);
	s(&((*env)->a), sa);
	s(&((*env)->b), sb);
	ss(&(*env));
	r(&((*env)->a), ra);
	r(&((*env)->b), rb);
	rr(&(*env));
	re(&((*env)->a), rra);
	re(&((*env)->b), rrb);
	rre(&(*env));
	print_stacks((*env)->a, (*env)->b);
 */

static int	stack_get_n(t_stack	*a, int n)
{
	while (a && n--)
		a = a->next;
	return (a->n);
}

static int	partition(t_env **env, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	j = low;
	i = low - 1;
	pivot = stack_get_n((*env)->a, high);
	printf("pivot: [%d]\n", pivot);
	while (j < high)
	{
		if ((*env)->a->n < pivot)
		{
			p(&((*env)->a), &((*env)->b), pb);
			i++;
		}
		else
			r(&((*env)->a), ra);
		j++;
	}	
	while ((*env)->b)
		p(&((*env)->b), &((*env)->a), pa);
	return (i + 1);
}

void	quick_sort(t_env **env, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		print_stacks((*env)->a, (*env)->b);
		pivot = partition(env, low, high);
		quick_sort(env, low, pivot - 1);
		quick_sort(env, pivot + 1, high);
	}
}
