/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:29:27 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/07 10:46:59 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *deststr, const char *srcstr, size_t len)
{
	char *str;

	str = deststr;
	while (len > 0 && *srcstr != '\0')
	{
		*str++ = *srcstr++;
		--len;
	}
	while (len > 0)
	{
		*str++ = '\0';
		--len;
	}
	return (deststr);
}
