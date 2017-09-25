/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:06:48 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/28 14:38:16 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (len > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		len--;
	}
	return (NULL);
}
