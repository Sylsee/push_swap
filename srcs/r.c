/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:08:07 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/27 03:07:40 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_stack **a)
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
}

void	rr(t_env **env)
{
	r(&((*env)->a));
	r(&((*env)->b));
}
