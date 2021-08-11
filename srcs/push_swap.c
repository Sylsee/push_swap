/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/11 02:28:05 by spoliart         ###   ########.fr       */
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
	env->size = stack_size_and_sorted(env->a);
//	clock_t tac2 = clock();
//	clock_t tic3 = clock();
	if (env->size == -1)
		return (env);
	else if (env->size == 2)
		s(&(env->a), sa);
	else if (env->size == 3)
		three_sort(&(env->a));
	else if (env->size <= 5)
		short_sort(&env);
	else if (env->size <= 50)
		insertion_sort(&env);
//	else if (env->size <= 100)
//		sort(&env);
	else
		radix_sort(&env);
//	clock_t tac3 = clock();
//	printf("Size: [%f]seconds\n", (double)(tac2 - tic2) / CLOCKS_PER_SEC);
//	print_stacks(env->a, env->b);
//	printf("size: %d\n", env->size);
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