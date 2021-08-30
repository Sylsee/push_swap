/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 04:30:13 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/30 05:29:06 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_sort(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->n;
	second = (*a)->next->n;
	third = (*a)->next->next->n;
	if (first > second && first < third && second < third)
		s(a, sa);
	else if (first > second && first > third && second < third)
		r(a, ra);
	else if (first < second && first > third && second > third)
		re(a, rra);
	else if (first > second && first > third && second > third)
	{
		s(a, sa);
		re(a, rra);
	}
	else if (first < second && first < third && second > third)
	{
		s(a, sa);
		r(a, ra);
	}
	return (0);
}
