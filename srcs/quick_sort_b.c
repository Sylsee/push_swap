/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <spoliart@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 06:59:20 by marvin            #+#    #+#             */
/*   Updated: 2021/08/29 07:00:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rewind(t_env **env, int rewind_small, int rewind_big)
{
	while (rewind_small--)
		re(&((*env)->b), rrb);
	while (rewind_big--)
		p(&((*env)->a), &((*env)->b), pb);
}

static int	more_pa(t_stack *b, int median)
{
	while (b)
	{
		if (b->n >= median)
			return (1);
		b = b->next;
	}
	return (0);
}

static int	partition_b(t_env **env, int size, int low, int high)
{
	int	i;
	int	median;
	int	rewind_big;
	int	rewind_small;

	i = -1;
	rewind_big = 0;
	rewind_small = 0;
	median = (*env)->arr[(high - low) / 2 + low];
	while (++i < size && more_pa((*env)->b, median))
	{
		if ((*env)->b->n >= median)
		{
			p(&((*env)->b), &((*env)->a), pa);
			rewind_big++;
		}
		else
		{
			r(&((*env)->b), rb);
			rewind_small++;
		}
	}
	ps_rewind(env, rewind_small, rewind_big);
	return ((high - low) / 2 + low);
}

void	quick_sort_b(t_env **env, int low, int high)
{
	int	size;
	int	pivot;

	size = high - low;
	if (size > 2)
	{
		pivot = partition_b(env, size, low, high);
		quick_sort_b(env, pivot, high);
		quick_sort_b(env, low, pivot);
	}
	else if (size <= 2 && low < high)
	{
		if (size == 2 && (*env)->b->n < (*env)->b->next->n)
			s(&((*env)->b), sb);
		while (size--)
			p(&((*env)->b), &((*env)->a), pa);
	}
}
