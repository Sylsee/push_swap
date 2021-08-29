/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 02:46:33 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/29 08:11:46 by marvin           ###   ########.fr       */
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

t_stack	*get_stack(t_stack *a, int n, int *i)
{
	if (n != 1)
		*i = n;
	while (--n && a)
		a = a->next;
	return (a);
}

static int	index_of_pb(t_stack *a, int median, int half, int size)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	while (a && index == -1 && i < half)
	{
		if (a->n <= median)
			index = i + 1;
		i++;
		a = a->next;
	}
	if (index != -1)
		a = get_stack(a, size - index + i + !(size % 2), &i);
	else
		a = get_stack(a, 1, &i);
	while (a)
	{
		if (a->n <= median)
			index = i + 1;
		i++;
		a = a->next;
	}
	return (index);
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
		half = ((*env)->size - i) / 2 + ((*env)->size - i) % 2;
		index = index_of_pb((*env)->a, median, half, (*env)->size - i);
		if (index == -1)
			break ;
		if (index == 0)
			;
		else if (index <= half || (((*env)->size - i) % 2 && index - 1 == half))
			while (--index)
				r(&((*env)->a), ra);
		else if (index > 0)
			while (index++ <= (*env)->size - i)
				re(&((*env)->a), rra);
		p(&((*env)->a), &((*env)->b), pb);
		i++;
	}
	return ((high - low) / 2 + low - 1);
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
