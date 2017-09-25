/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:59:00 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/08 15:25:13 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	cnt(char const *str, char c)
{
	size_t		count;
	int			is_word;

	count = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (*str != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (*str == c && is_word == 1)
			is_word = 0;
		str++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		j;

	j = 0;
	if (!s || !(res = (char**)malloc(sizeof(char*) * ((cnt(s, c) + 1)))))
		return (NULL);
	res[cnt(s, c)] = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i)
		{
			res[j] = ft_strnew(i);
			if (res[j] == NULL)
				return (NULL);
			ft_strncpy(res[j++], s, i);
			s = s + i;
		}
	}
	return (res);
}
