/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 03:49:18 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_env *env)
{
	env->size = stack_size(env->a);
	print_stacks(env->a, env->b);
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
	push_swap(env);
	ps_free_lst(env->a);
	free(env);
	return (0);
}
