/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/30 05:20:42 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_env	*push_swap(t_env *env)
{
	env->size = stack_size_and_sorted(env->a);
	if (env->size == -1)
		return (env);
	else if (env->size == 2)
		s(&(env->a), sa);
	else if (env->size == 3)
		three_sort(&(env->a));
	else if (env->size <= 5)
		short_sort(&env);
	else
		prepare_quick_sort(&env);
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
