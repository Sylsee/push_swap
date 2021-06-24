/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:22:18 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/26 18:24:10 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putxchar_fd(char c, int fd, int x)
{
	int ret;

	ret = 0;
	while (x-- > 0)
		ret += write(fd, &c, 1);
	return (ret);
}
