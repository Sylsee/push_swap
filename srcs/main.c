/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/27 03:33:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	p(&(env->a), &(env->b));
	p(&(env->b), &(env->a));
	s(&(env->a));
	s(&(env->b));
	ss(&env);
	r(&(env->a));
	r(&(env->b));
	rr(&env);
	re(&(env->a));
	re(&(env->b));
	rre(&env);
	print_stacks(env->a, env->b);
 */

void	push_swap(t_env *env)
{
	env->size = stack_size(env->a);
	if (env->size == -1)
		return ;
//	sort(env);
//	print_stacks(env->a, env->b);
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
	push_swap(env);
	ps_free_lst(env->a);
	ps_free_lst(env->b);
	free(env);
	return (0);
}
