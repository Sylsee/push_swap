/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:08 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/24 20:17:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		str_is_digit(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] < '0' || s[i]> '9')
			print_and_exit("Error");
}

t_stack		*parse(int ac, char **av)
{
	t_stack	*lst;
	int i;

	while (--ac)
		str_is_digit(av[ac]);
	while (--argc)
		lst = new_node(lst, ps_atoi(argv[argc]));
	return (lst);
}
