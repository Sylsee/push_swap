/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/03 04:16:10 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

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
//	clock_t tic2 = clock();
	env->size = stack_size(env->a);
//	clock_t tac2 = clock();
//	clock_t tic3 = clock();
	if (env->size == -1)
		return (env);
	else if (env->size == 2)
		s(&(env->a), sa);
	else if (env->size == 3)
		three_sort(&env);
	else if (env->size > 3 && env->size <= 10)
		insertion_sort(&env);
	else if (env->size > 10 && env->size < 100)
		insertion_sort(&env);
	else if (env->size >= 100)
		radix_sort(&env);
//	else
//		quick_sort(&env, 0, env->size - 1);
//	clock_t tac3 = clock();
//	printf("size: %d\n", env->size);
//	printf("Size: [%f]seconds\n", (double)(tac2 - tic2) / CLOCKS_PER_SEC);
//	print_stacks(env->a, env->b);
//	printf("Sort: [%f]seconds\n", (double)(tac3 - tic3) / CLOCKS_PER_SEC);
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
