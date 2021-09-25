/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:08:07 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/25 03:43:47 by marvin           ###   ########.fr       */
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
	last = stack_last(*a);
	last->next = tmp;
	tmp->next = NULL;
	if (moves == ra)
		ft_putstr_fd("ra\n", 1);
	else if (moves == rb)
		ft_putstr_fd("rb\n", 1);
	return (1);
}

void	rr(t_env **env, t_moves moves)
{
	r(&((*env)->a), none);
	r(&((*env)->b), none);
	if (moves == print)
		ft_putstr_fd("rr\n", 1);
}
