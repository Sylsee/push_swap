/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:28:56 by spoliart          #+#    #+#             */
/*   Updated: 2020/10/27 18:07:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char *pt;

	pt = (unsigned char *)s;
	while (len--)
		*(unsigned char *)pt++ = (unsigned char)c;
	return (s);
}
