/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 04:30:13 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/30 04:34:28 by spoliart         ###   ########.fr       */
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

void	three_sort(t_env **env)
{
	int	first;
	int	second;
	int	third;

	first = (*env)->a->n;
	second = (*env)->a->next->n;
	third = (*env)->a->next->next->n;
	if (first > second && first < third && second < third)
		s(&((*env)->a), sa);
	else if (first > second && first > third && second < third)
		r(&((*env)->a), ra);
	else if (first < second && first > third && second > third)
		re(&((*env)->a), rra);
	else if (first > second && first > third && second > third)
	{
		s(&((*env)->a), sa);
		re(&((*env)->a), rra);
	}
	else if (first < second && first < third && second > third)
	{
		s(&((*env)->a), sa);
		r(&((*env)->a), ra);
	}
}
