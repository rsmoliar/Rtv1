/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:23:35 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/22 14:35:17 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *bigcpy;
	const char *littlecpy;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		bigcpy = big;
		littlecpy = little;
		while (*littlecpy != '\0' && (*bigcpy == *littlecpy))
		{
			bigcpy++;
			littlecpy++;
		}
		if (*littlecpy == '\0')
			return ((char *)big);
		big++;
	}
	return (NULL);
}
