/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:57:25 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/03 14:49:41 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	char	*jstrp;

	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	jstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (jstr == NULL)
		return (NULL);
	jstrp = jstr;
	while (*s1 != '\0')
		*jstrp++ = *s1++;
	while (*s2 != '\0')
		*jstrp++ = *s2++;
	*jstrp = '\0';
	return (jstr);
}
