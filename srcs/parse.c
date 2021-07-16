/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:08 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/16 16:45:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_digit(int ac, char **av)
{
	int	i;

	while (--ac)
	{
		i = 0;
		if (av[ac][i] == '-' || av[ac][i] == '+')
			i++;
		while (ft_isdigit(av[ac][i]))
			i++;
		if (av[ac][i])
			return (0);
	}
	return (1);
}

int	is_duplicate(t_stack *lst)
{
	t_stack *tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->n == tmp->n)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}

t_stack	*ps_parse(int ac, char **av)
{
	t_stack	*tmp;
	t_stack	*lst;

	lst = NULL;
	if (!(ps_check_digit(ac, av)))
		return (NULL);
	while (--ac)
	{
		tmp = ps_new_node(lst, av[ac]);
		if (!tmp)
		{
			ps_free_lst(lst);
			return (NULL);
		}
		lst = tmp;
	}
	if (!(is_duplicate(lst)))
	{
		ps_free_lst(lst);
		return (NULL);
	}
	return (lst);
}
