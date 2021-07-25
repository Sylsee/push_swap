/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:51:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 03:24:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_env **env)
{
	t_stack	*tmp;

	if (!((*env)->b))
		return ;
	tmp = (*env)->b->next;
	if (tmp)
		tmp->prev = NULL;
	if ((*env)->a)
	{
		(*env)->b->next = (*env)->a;
		(*env)->a->prev = (*env)->b;
		(*env)->a = (*env)->b;
	}
	else
	{
		(*env)->b->next = NULL;
		(*env)->a = (*env)->b;
	}
	(*env)->b = tmp;
}

void	pb(t_env **env)
{
	t_stack	*tmp;

	if (!((*env)->a))
		return ;
	tmp = (*env)->a->next;
	if (tmp)
		tmp->prev = NULL;
	if ((*env)->b)
	{
		(*env)->a->next = (*env)->b;
		(*env)->b->prev = (*env)->a;
		(*env)->b = (*env)->a;
	}
	else
	{
		(*env)->a->next = NULL;
		(*env)->b = (*env)->a;
	}
	(*env)->a = tmp;
}
