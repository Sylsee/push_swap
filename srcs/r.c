/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:08:07 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:51:43 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r(t_stack **a, t_moves moves)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a) || !((*a)->next))
		return (0);
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
	return (1);
}

void	rr(t_env **env)
{
	if (r(&((*env)->a), none) || r(&((*env)->b), none))
		ft_putstr_fd("rr\n", 1);
}
