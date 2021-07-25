/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:15:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 02:59:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_env **env)
{
	int	tmp;

	if ((*env)->size < 2)
		return ;
	if ((*env)->a && (*env)->a->next)
	{
		tmp = (*env)->a->n;
		(*env)->a->n = (*env)->a->next->n;
		(*env)->a->next->n = tmp;
	}
}

void	sb(t_env **env)
{
	int	tmp;

	if ((*env)->size < 2)
		return ;
	if ((*env)->b && (*env)->b->next)
	{
		tmp = (*env)->b->n;
		(*env)->b->n = (*env)->b->next->n;
		(*env)->b->next->n = tmp;
	}
}

void	ss(t_env **env)
{
	sa(env);
	sb(env);
}
