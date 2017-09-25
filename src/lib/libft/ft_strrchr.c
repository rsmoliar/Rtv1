/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:42:24 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/22 13:00:21 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *res;

	res = NULL;
	while (*str != '\0')
	{
		if (*str == (char)ch)
			res = (char *)str;
		str++;
	}
	if (*str == (char)ch)
		return ((char *)str);
	else
		return ((char *)res);
}
