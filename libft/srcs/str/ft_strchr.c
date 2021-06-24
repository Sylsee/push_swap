/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:42:07 by spoliart          #+#    #+#             */
/*   Updated: 2020/10/24 00:14:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *pt;

	pt = (char *)s;
	while (*pt != '\0')
	{
		if (*pt == c)
			return (pt);
		pt++;
	}
	if (*pt == c)
		return (pt);
	return (0);
}
