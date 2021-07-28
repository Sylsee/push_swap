/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:15:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:30:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *	Swap the first two elements of a
 */
void	s(t_stack **a, e_moves moves)
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
	if (moves == sa)
		ft_putstr_fd("sa\n", 1);
	else if (moves == sb)
		ft_putstr_fd("sb\n", 1);
}

/**
 *	Swap the first two elements of the two stacks
 *	
 *	@param env The struct where the stacks are stored
 */
void	ss(t_env **env)
{
	s(&((*env)->a), none);
	s(&((*env)->b), none);
}
