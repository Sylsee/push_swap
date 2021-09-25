/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:21:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/25 03:44:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	re(t_stack **a, t_moves moves)
{
	t_stack	*new_last;
	t_stack	*new_first;

	if (!(*a) || !((*a)->next))
		return (0);
	new_first = *a;
	while (new_first->next)
	{
		new_last = new_first;
		new_first = new_first->next;
	}
	new_last->next = NULL;
	new_first->next = *a;
	*a = new_first;
	if (moves == rra)
		ft_putstr_fd("rra\n", 1);
	else if (moves == rrb)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

void	rrr(t_env **env, t_moves moves)
{
	re(&((*env)->a), none);
	re(&((*env)->b), none);
	if (moves == print)
		ft_putstr_fd("rrr\n", 1);
}
