/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:20:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/28 22:43:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_ps(t_env env)
{

}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc == 1)
		print_and_exit("Error");
	env.a = parse(argc, argv);
	if (!(env.a))
	{
		free(env);
		print_and_exit("Error");
	}
	start_ps(env);
	return (0);
}
