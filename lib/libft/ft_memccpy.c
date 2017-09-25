/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:16:39 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/28 14:29:34 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *dstcpy;
	char *srccpy;

	dstcpy = (char *)dst;
	srccpy = (char *)src;
	while (n > 0 && *srccpy != c)
	{
		*dstcpy = *srccpy;
		dstcpy++;
		srccpy++;
		n--;
	}
	if (n > 0)
	{
		*dstcpy++ = *srccpy++;
		return ((void*)dstcpy);
	}
	else
		return (NULL);
}
