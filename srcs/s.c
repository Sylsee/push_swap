/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:15:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/25 03:43:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *	Swap the first two elements of a
 */
int	s(t_stack **a, t_moves moves)
{
	int	tmp;

	if (!(*a) || !((*a)->next))
		return (0);
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
	return (1);
}

/**
 *	Swap the first two elements of the two stacks
 *	
 *	@param env The struct where the stacks are stored
 */
void	ss(t_env **env, t_moves moves)
{
	s(&((*env)->a), none);
	s(&((*env)->b), none);
	if (moves == print)
		ft_putstr_fd("ss\n", 1);
}
