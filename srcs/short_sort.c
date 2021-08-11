/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:01:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/11 02:27:16 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	p(&((*env)->a), &((*env)->b));
	p(&((*env)->b), &((*env)->a));
	s(&((*env)->a));
	s(&((*env)->b));
	ss(&(*env));
	r(&((*env)->a));
	r(&((*env)->b));
	rr(&(*env));
	re(&((*env)->a));
	re(&((*env)->b));
	rre(&(*env));
	print_stacks((*env)->a, (*env)->b);
 */

static int	the_place_to_be(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (a && a->n < n)
	{
		a = a->next;
		i++;
	}
	return (i);
}

static void	choose_rotation(t_env **env)
{
	int	tmp;
	int	pos;
	int	size;

	pos = the_place_to_be((*env)->a, (*env)->b->n);
	size = stack_size((*env)->a);
	if (pos > size / 2)
		pos = pos - size;
	tmp = pos;
	if ((pos >> 31) & 1)
		while (pos++)
			re(&((*env)->a), rra);
	else
		while (pos--)
			r(&((*env)->a), ra);
	p(&((*env)->b), &((*env)->a), pa);
	pos = tmp;
	if ((pos >> 31) & 1)
		pos -= 1;
	if ((pos >> 31) & 1)
		while (pos++)
			r(&((*env)->a), ra);
	else
		while (pos--)
			re(&((*env)->a), rra);
}

static void	easy(t_env **env)
{
	if ((*env)->b->n < (*env)->a->n)
		p(&((*env)->b), &((*env)->a), pa);
	else
	{
		p(&((*env)->b), &((*env)->a), pa);
		r(&((*env)->a), ra);
	}
}

void	short_sort(t_env **env)
{
	int	i;

	i = (*env)->size;
	while (i-- > 3)
		p(&((*env)->a), &((*env)->b), pb);
	three_sort(&(*env)->a);
	while ((*env)->b)
	{
		if ((*env)->b->n > stack_last((*env)->a)->n)
			easy(env);
		else
			choose_rotation(env);
	}
}
