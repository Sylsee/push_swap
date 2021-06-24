/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:27:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/24 20:09:41 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*new_node(t_stack lst, char *n)
{
	int		err;
	t_stack	*new;

	err = 0;
	if (!(new = malloc(sizeof(new))))
		print_and_exit("Malloc error");
	new->n = ps_atoi(n, &err);
	if (err)
	{
		free(new);
		ps_lst_delone(lst);
	}
	new->prev = NULL;
	if (lst)
	{
		lst->prev = new;
		new->next = lst;
	}
	else
		new->next = NULL;
	return (new);
}

void		ps_lst_delone(t_stack lst)
{
	t_stack	tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
