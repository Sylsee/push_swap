/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/25 03:45:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move(char *move, t_env *env)
{
	if (ft_strcmp(move, "sa") == 0)
		s(&(env->a), none);
	else if (ft_strcmp(move, "sb") == 0)
		s(&(env->b), none);
	else if (ft_strcmp(move, "ss") == 0)
		ss(&env, none);
	else if (ft_strcmp(move, "pb") == 0)
		p(&(env->a), &(env->b), none);
	else if (ft_strcmp(move, "pa") == 0)
		p(&(env->b), &(env->a), none);
	else if (ft_strcmp(move, "ra") == 0)
		r(&(env->a), none);
	else if (ft_strcmp(move, "rb") == 0)
		r(&(env->b), none);
	else if (ft_strcmp(move, "rr") == 0)
		rr(&env, none);
	else if (ft_strcmp(move, "rra") == 0)
		re(&(env->a), none);
	else if (ft_strcmp(move, "rrb") == 0)
		re(&(env->b), none);
	else if (ft_strcmp(move, "rrr") == 0)
		rrr(&env, none);
	else
		return (0);
	return (1);
}

static t_env	*checker(t_env *env)
{
	char	*line;

	env->size = stack_size(env->a);
	while (get_next_line(0, &line) == 1)
	{
		if (!(move(line, env)))
		{
			ft_putendl_fd("Error", 2);
			free(line);
			ps_free_lst(env->a);
			ps_free_lst(env->b);
			free(env);
			exit(1);
		}
		print_stacks(env->a, env->b);
		free(line);
	}
	free(line);
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
	env = checker(env);
	if (stack_is_sorted(env->a) && !(env->b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ps_free_lst(env->a);
	ps_free_lst(env->b);
	free(env);
	return (0);
}
