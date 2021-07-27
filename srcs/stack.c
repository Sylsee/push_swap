/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 00:53:22 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/27 02:47:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	A_is_sorted(t_stack *a)
{
	int	tmp;

	tmp = a->n;
	while (a)
	{
		if (tmp > a->n)
			return (0);
		tmp = a->n;
		a = a->next;
	}
	return (1);
}

int	stack_size(t_stack *s)
{
	int	i;
	int	tmp;
	int	sorted;

	i = 0;
	sorted = -1;
	tmp = s->n;
	while (s)
	{
		if (tmp > s->n)
			sorted = 1;
		tmp = s->n;
		s = s->next;
		i++;
	}
	if (sorted == -1)
		return (sorted);
	return (i);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack)
		while (stack->next)
			stack = stack->next;
	return (stack);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_putendl_fd("     PILE A\t\t\t      PILE B", 1);
	ft_putendl_fd("", 1);
	while (a || b)
	{
		ft_putstr_fd("\t", 1);
		if (a)
			ft_putnbr_fd(a->n, 1);
		ft_putstr_fd("\t", 1);
		ft_putstr_fd("\t\t\t ", 1);
		if (b)
			ft_putnbr_fd(b->n, 1);
		ft_putstr_fd("\t", 1);
		ft_putendl_fd("", 1);
		ft_putendl_fd("", 1);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}
