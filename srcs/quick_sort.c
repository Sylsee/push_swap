/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 02:46:33 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/30 04:16:57 by spoliart         ###   ########.fr       */
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

static int	get_index(t_stack *a, int median, int start, int stop)
{
	int	i;
	int	index;
	t_stack	*tmp;

	i = -1;
	tmp = a;
	while (tmp && ++i < start)
		tmp = tmp->next;
	index = -1;
	while (tmp && i <= stop)
	{
		if (tmp->n <= median)
		{
			index = i;
			if (start == 0)
				return (index);
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

static int	index_of_pb(t_env **env, int median, int half)
{
	int	size;
	int	first_index;
	int	second_index;

	size = stack_size((*env)->a);
	first_index = get_index((*env)->a, median, 0, half);
	second_index = get_index((*env)->a, median, half, size);
	if (second_index == -1 ||
			(first_index != -1 && first_index <= size - second_index))
		return (first_index);
	return (second_index);
}

static int	partition(t_env **env, int low, int high)
{
	int	i;
	int	half;
	int	index;
	int	median;

	i = 0;
	median = (*env)->arr[(high - low) / 2 + low - 1];
	while (1)
	{
		half = ((*env)->size - i) / 2;
		index = index_of_pb(env, median, half);
		if (index == -1)
			break ;
		if (index == 0)
			;
		else if (index <= half || (((*env)->size - i) % 2 && index - 1 == half))
			while (index--)
				r(&((*env)->a), ra);
		else if (index > 0)
			while (++index <= (*env)->size - i)
				re(&((*env)->a), rra);
		p(&((*env)->a), &((*env)->b), pb);
		i++;
	}
	return ((high - low) / 2 + low - 1);
}
void	quick_sort(t_env **env, int low, int high)
{
	int	size;
	int	pivot;

	size = high - low;
	if (size > 2)
	{
		pivot = partition(env, low, high);
		quick_sort(env, pivot + 1, high);
		quick_sort_b(env, low, low + size - stack_size((*env)->a));
	}
	else if (size <= 2 && low < high)
		if (size == 2 && (*env)->a->n > (*env)->a->next->n)
			s(&((*env)->a), sa);
}
/*
static int	partition(t_env **env, int size, int low, int high)
{
	int	i;
	int	median;

	i = -1;
	median = (*env)->arr[(high - low) / 2 + low];
	while (++i < size)
	{
		if ((*env)->a->n <= median)
			p(&((*env)->a), &((*env)->b), pb);
		else
			r(&((*env)->a), ra);
	}
	return ((high - low) / 2 + low);
}
*/
