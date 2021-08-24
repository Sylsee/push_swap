/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 02:46:33 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/24 03:47:12 by marvin           ###   ########.fr       */
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

int	get_median(int *arr, int low, int high)
{
	return (arr[(high - low) / 2 + low]);
}

void	simple_sort(t_stack *a)
{
	int	size;

	size = stack_size(a);
	if (size == 2 && a->n > a->next->n)
		s(&a, sa);
	else if (size == 3)
		three_sort(&a);
}

void	quick_sort(t_env **env, int size, int low, int high)
{
	int	i;
	int	median;

	//print_stacks((*env)->a, (*env)->b);
	if (size <= 3)
	{
		simple_sort((*env)->a);
		return ;
	}
	i = -1;
	median = get_median((*env)->arr, low, high);
	while (++i < size)
	{
		if ((*env)->a->n < median)
			p(&((*env)->a), &((*env)->b), pb);
		else
			r(&((*env)->a), ra);
	}
	//print_stacks((*env)->a, (*env)->b);
	quick_sort(env, size / 2, median, high);
	quick_sort(env, size, low, median);
}
