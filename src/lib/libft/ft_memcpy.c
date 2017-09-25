/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:43:55 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/28 14:28:48 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dstcpy;
	char *srccpy;

	dstcpy = (char *)dst;
	srccpy = (char *)src;
	while (n > 0)
	{
		*dstcpy = *srccpy;
		dstcpy++;
		srccpy++;
		n--;
	}
	return (dst);
}
