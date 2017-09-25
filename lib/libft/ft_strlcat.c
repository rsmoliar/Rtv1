/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:21:13 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/05 11:06:46 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t last;

	i = 0;
	while (dst[i] && i < size)
		i++;
	last = i;
	while (src[i - last] && i < size - 1)
	{
		dst[i] = src[i - last];
		i++;
	}
	if (last < size)
		dst[i] = '\0';
	return (last + ft_strlen(src));
}
