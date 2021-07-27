/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:51:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/27 02:11:50 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *	Move the first element of a stack on top of b stack
 *	
 *	@param a Stack to get element
 *	@param b Stack to put element
 */
void	p(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	if (tmp)
		tmp->prev = NULL;
	if (*b)
	{
		(*a)->next = *b;
		(*b)->prev = *a;
		*b = *a;
	}
	else
	{
		(*a)->next = NULL;
		*b = *a;
	}
	*a = tmp;
}
