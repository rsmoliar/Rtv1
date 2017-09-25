/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:46:01 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/30 18:15:25 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_symbols(int numb)
{
	size_t			i;
	unsigned int	n;

	i = 1;
	n = numb;
	if (numb < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*stri;
	unsigned int	numb;
	size_t			len;
	size_t			pos;

	len = count_symbols(n);
	pos = 0;
	stri = ft_strnew(len);
	if (stri == NULL)
		return (NULL);
	stri[len] = '\0';
	if (n < 0)
	{
		stri[0] = '-';
		numb = -n;
		pos = 1;
	}
	else
		numb = n;
	while (len-- > pos)
	{
		stri[len] = (numb % 10) + '0';
		numb /= 10;
	}
	return (stri);
}
