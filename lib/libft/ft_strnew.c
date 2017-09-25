/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:49:40 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/03 17:34:22 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = malloc(size + 1)) != NULL)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	else
		return (NULL);
}
