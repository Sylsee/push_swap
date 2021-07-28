/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/28 06:42:05 by spoliart         ###   ########.fr       */
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

t_env	*push_swap(t_env *env)
{
	env->size = stack_size(env->a);
	if (env->size == -1)
		return (env);
	if (env->size == 3)
		three_solution(&env);
	else if (env->size > 3 && env->size <= 10)
		;
	else if (env->size > 10 && env->size <= 100)
		;
	else if (env->size > 100)
		radix_sort(&env);
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
	free(env);
	return (0);
}
