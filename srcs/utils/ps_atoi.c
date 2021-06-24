/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:45:13 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/24 20:11:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_atoi(char *s, int *err)
{
	long	nbr;
	int		negative;

	nbr = 0;
	sign = 1;
	if (*s && *s == '-')
		sign = -1;
	while (*s && *s >= '0' && *s <= '9')
	{
		nbr = (nbr * 10) + (*s++ - '0');
		if ((!sign && nbr > INT_MAX) || (sign && nbr > (long)(INT_MAX) + 1))
		{
			*err = 1;
			break ;
		}
	}
	return (nbr * sign);
}
