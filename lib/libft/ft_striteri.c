/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:17:48 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/03 12:55:46 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (*s)
		{
			f(i, s);
			s++;
			i++;
		}
	}
}
