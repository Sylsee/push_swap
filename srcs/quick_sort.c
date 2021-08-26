/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 02:46:33 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/26 03:36:03 by spoliart         ###   ########.fr       */
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
	static int	last_size = 0;
	int	size;
	int	pivot;

	size = high - low;
	if (size > 2)
	{
		last_size = size;
		printf("before low: [%d]\nhigh: [%d]\n", low, high);
		fflush(stdout);
		pivot = partition(env, size, low, high);
		quick_sort(env, pivot + 1, high);
		printf("after low: [%d]\nhigh: [%d]\n", low, high);
		fflush(stdout);
		quick_sort(env, low, pivot - 1);
	}
	else if (size <= 2 && low < high)
	{
		(*env)->sorted = 1;
		if (size == 2 && (*env)->a->n > (*env)->a->next->n)
			s(&((*env)->a), sa);
		while (last_size-- && (*env)->b)
			p(&((*env)->b), &((*env)->a), pa);
		last_size = size;
	}
}
