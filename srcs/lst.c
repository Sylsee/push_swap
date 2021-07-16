/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:27:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/16 16:43:10 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_new_node(t_stack *lst, char *n)
{
	int		err;
	t_stack	*new;

	err = 0;
	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->n = ps_atoi(n, &err);
	if (err == 1)
	{
		free(new);
		ps_free_lst(lst);
		return (NULL);
	}
	if (lst)
	{
		lst->prev = new;
		new->next = lst;
	}
	else
		new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ps_free_lst(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
