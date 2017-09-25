/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:43:17 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/22 10:07:51 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char *result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, str);
	return (result);
}
