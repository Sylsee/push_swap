/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/29 01:40:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	p(&(env->a), &(env->b), pb);
	p(&(env->b), &(env->a), pa);
	s(&(env->a), sa);
	s(&(env->b), sb);
	ss(&env, ss);
	r(&(env->a), ra);
	r(&(env->b), rb);
	rr(&env, rr);
	re(&(env->a), rra);
	re(&(env->b), rrb);
	rre(&env, rrr);
	print_stacks(env->a, env->b);
 */

static t_env	*push_swap(t_env *env)
{
	env->size = stack_size_and_sorted(env->a);
	//print_stacks(env->a, env->b);
	if (env->size == -1)
		return (env);
	else if (env->size == 2)
		s(&(env->a), sa);
	else if (env->size == 3)
		three_sort(&(env->a));
	else if (env->size <= 5)
		short_sort(&env);
	else if (env->size <= 50)
		prepare_quick_sort(&env);
		//insertion_sort(&env);
	else if (env->size <= 100)
		prepare_quick_sort(&env);
		//radix_sort(&env);
	else
		prepare_quick_sort(&env);
	//print_stacks(env->a, env->b);
	return (env);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 1)
		return (0);
	env = malloc(sizeof(t_env));
	if (!env)
		print_and_exit("Malloc error");
	env->a = ps_parse(argc, argv);
	if (!(env->a))
	{
		free(env);
		print_and_exit("Error");
	}
	env->b = NULL;
	env = push_swap(env);
	ps_free_lst(env->a);
	ps_free_lst(env->b);
	free(env->arr);
	free(env);
	return (0);
}
