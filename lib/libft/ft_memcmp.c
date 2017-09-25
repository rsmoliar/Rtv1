/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:23:45 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/28 15:18:44 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char *s1cpy;
	unsigned char *s2cpy;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (len > 0)
	{
		if (*s1cpy != *s2cpy)
			return (*s1cpy - *s2cpy);
		s1cpy++;
		s2cpy++;
		len--;
	}
	return (0);
}
