/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:08:07 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:41:49 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_stack **a, e_moves moves)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a) || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last = stack_last(*a);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	if (moves == ra)
		ft_putstr_fd("ra\n", 1);
	else if (moves == rb)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_env **env)
{
	r(&((*env)->a), none);
	r(&((*env)->b), none);
}
