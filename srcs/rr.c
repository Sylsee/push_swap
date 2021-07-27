/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:21:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/27 03:17:03 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re(t_stack **a)
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
}

void	rre(t_env **env)
{
	re(&((*env)->a));
	re(&((*env)->b));
}
