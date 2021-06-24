/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:05:24 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/25 00:44:33 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_and_exit(char *s, t_stack *a)
{
	ps_lst_delone(a);
	ft_putstr_fd(s, 2);
	write(2, '\n', 1);
	exit(1);
}

void	print_and_exit(char *s)
{
	ft_putstr_fd(s, 2);
	write(2, '\n', 1);
	exit(1);
}
