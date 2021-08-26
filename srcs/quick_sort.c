/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 02:46:33 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/26 20:55:12 by spoliart         ###   ########.fr       */
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

static int	partition(t_env **env, int size, int low, int high)
{
	int	i;
	int	j;
	int	median;

	j = 0;
	i = -1;
	median = (*env)->arr[(high - low) / 2 + low];
	while (++i < size)
	{
		if ((*env)->a->n <= median)
			p(&((*env)->a), &((*env)->b), pb);
		else
		{
			r(&((*env)->a), ra);
			j++;
		}
	}
	if ((*env)->sorted)
		while (j--)
			re(&((*env)->a), rra);
	return ((high - low) / 2 + low);
}

void	quick_sort(t_env **env, int low, int high)
{
	static int	sorted;
	int	size;
	int	pivot;

	size = high - low;
	if (size > 2)
	{
		last_size = size;
		pivot = partition(env, size, low, high);
		printf("before\nlow: [%d]\nhigh: [%d]\npivot: [%d]\n", low, high, pivot);
		fflush(stdout);
		quick_sort(env, pivot + 1, high);
		printf("after\nlow: [%d]\nhigh: [%d]\npivot: [%d]\n", low, high, pivot);
		fflush(stdout);
		quick_sort(env, low, pivot - 1);
	}
	else if (size <= 2 && low < high)
	{
		(*env)->sorted = 1;
		if (size == 2 && (*env)->a->n > (*env)->a->next->n)
			s(&((*env)->a), sa);
		sorted = (*env)->a->n;
		printf("size: [%d]\nlast_size: [%d]\n", last_size, size);
		fflush(stdout);
		while ( size-- + 1 && (*env)->b)
			p(&((*env)->b), &((*env)->a), pa);
	}
}
