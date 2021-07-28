/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:21:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:25:59 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re(t_stack **a, e_moves moves)
{
	t_stack	*tmp;

	if (!(*a) || !((*a)->next))
		return ;
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
}

void	rre(t_env **env)
{
	re(&((*env)->a), none);
	re(&((*env)->b), none);
}
