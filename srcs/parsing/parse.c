/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:08 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/28 22:00:06 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_digit(char *s)
{
	int	i;

	i = 0;
	if (av[argc][i] == '-' || av[argc][i] == '+')
		i++;
	while (ft_isdigit(av[argc][i]))
		i++;
	if (av[argc][i])
		return (NULL);
	return (1);
}

t_stack	*ps_parse(int ac, char **av)
{
	int		argc;
	t_stack	*lst;
	t_stack	*tmp;

	argc = ac;
	while (--argc)
		if (!(ps_check_digit(av[argc])))
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
	return (lst);
}
