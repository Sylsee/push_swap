/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 02:46:33 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/25 04:21:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	p(&((*env)->a), &((*env)->b), pb);
	p(&((*env)->b), &((*env)->a), pa);
	s(&((*env)->a), sa);
	s(&((*env)->b), sb);
	ss(&(*env), ss);
	r(&((*env)->a), ra);
	r(&((*env)->b), rb);
	rr(&(*env), rr);
	re(&((*env)->a), rra);
	re(&((*env)->b), rrb);
	rre(&(*env), rrr);
	print_stacks((*env)->a, (*env)->b);
 */

static void	simple_sort(t_stack **a, int size)
{
	if (size == 2 && (*a)->n > (*a)->next->n)
		s(a, none);
	else if (size == 3)
		three_sort(a);
}

static int	partition(t_env **env, int size, int low, int high)
{
	int	i;
	int	median;

	i = -1;
	median = (*env)->arr[(high - low) / 2 + low];
	printf("\nmedian: [%d]\n\n", median);
	//fflush(stdout);
	while (++i < size)
	{
		if ((*env)->a->n <= median)
			p(&((*env)->a), &((*env)->b), pb);
		else
			r(&((*env)->a), ra);
	}
	return ((high - low) / 2 + low);
}

void	quick_sort(t_env **env, int low, int high)
{
	int	size;
	int	pivot;

	size = high - low;
	if (size > 4 && low < high)
	{
		pivot = partition(env, size, low, high);
		printf("low: [%d]\nhigh: [%d]\nsize: [%d]\npivot: [%d]\n", low, high, size, pivot);
		quick_sort(env, pivot + 1, high);
		quick_sort(env, low, pivot - 1);
	}
	else if (size <= 3 && low < high)
	{
		simple_sort(&((*env)->a), size);
		size = 3;
		while (size-- && (*env)->b)
			p(&((*env)->b), &((*env)->a), none);
	}
}
