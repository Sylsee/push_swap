/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/16 16:59:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_ps(t_env *env)
{
	env->size = stack_size(env->a);
	print_stacks(env->a, env->b);
	pa(&env);
	print_stacks(env->a, env->b);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 1)
		print_and_exit("Error");
	env = malloc(sizeof(env));
	if (!env)
		print_and_exit("Malloc error");
	env->a = ps_parse(argc, argv);
	if (!(env->a))
	{
		free(env);
		print_and_exit("blError");
	}
	start_ps(env);
	return (0);
}
