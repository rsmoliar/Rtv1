/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:36:08 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/08 15:26:43 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	llen;

	llen = ft_strlen(little);
	i = 0;
	if (!*little)
		return ((char *)big);
	while (*big && llen <= len - i)
	{
		if (*big == *little && (ft_strncmp(big, little, llen) == 0))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
