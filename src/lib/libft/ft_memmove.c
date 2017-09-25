/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:43:23 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/28 14:35:20 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *destcpy;
	char *srccpy;

	destcpy = (char *)dest;
	srccpy = (char *)src;
	if (srccpy < destcpy)
	{
		srccpy = (srccpy + len) - 1;
		destcpy = (destcpy + len) - 1;
		while (len-- > 0)
		{
			*destcpy-- = *srccpy--;
		}
	}
	else
	{
		while (len-- > 0)
		{
			*destcpy++ = *srccpy++;
		}
	}
	return (dest);
}
