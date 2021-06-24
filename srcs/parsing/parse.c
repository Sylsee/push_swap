/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:08 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/25 00:16:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ps_parse(int ac, char **av)
{
	int		argc;
	t_stack	*lst;

	argc = ac;
	while (--ac)
		if (!(ft_str_is_digit(av[ac])))
			print_and_exit("Error");
	while (--argc)
		lst = ps_new_node(lst, ps_atoi(av[argc]));
	return (lst);
}
