/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:37:39 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/08 15:55:30 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*result;

	if (!s)
		return (NULL);
	if ((sub = ft_strnew(len)) == NULL)
		return (NULL);
	result = sub;
	s += (start);
	while (len--)
		*sub++ = *s++;
	return (result);
}
