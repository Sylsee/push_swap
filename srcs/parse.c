/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:08 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/22 23:44:00 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->n == tmp->n)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	create_lst(int ac, char **av, t_stack **lst)
{
	t_stack	*tmp;

	tmp = ps_new_node(lst, av[ac]);
	if (!tmp)
	{
		ps_free_lst(*lst);
		return (0);
	}
	*lst = tmp;
	return (1);
}

t_stack	*ps_parse(int ac, char **av)
{
	t_stack	*lst;

	lst = NULL;
	while (--ac)
		if (!(create_lst(ac, av, &lst)))
			return (NULL);
	if (is_duplicate(lst))
	{
		ps_free_lst(lst);
		return (NULL);
	}
	return (lst);
}
