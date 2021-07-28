/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:21:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:51:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	re(t_stack **a, t_moves moves)
{
	t_stack	*tmp;

	if (!(*a) || !((*a)->next))
		return (0);
	tmp = stack_last(*a);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	if (moves == rra)
		ft_putstr_fd("rra\n", 1);
	else if (moves == rrb)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

void	rrr(t_env **env)
{
	if (re(&((*env)->a), none) || re(&((*env)->b), none))
		ft_putstr_fd("rrr\n", 1);
}
