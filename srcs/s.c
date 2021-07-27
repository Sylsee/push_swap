/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:15:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/27 02:25:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *	Swap the first two elements of a
 */
void	s(t_stack **a)
{
	int	tmp;

	if (!(*a) || !((*a)->next))
		return ;
	if ((*a) && (*a)->next)
	{
		tmp = (*a)->n;
		(*a)->n = (*a)->next->n;
		(*a)->next->n = tmp;
	}
}

/**
 *	Swap the first two elements of the two stacks
 *	
 *	@param env The struct where the stacks are stored
 */
void	ss(t_env **env)
{
	s(&((*env)->a));
	s(&((*env)->b));
}
