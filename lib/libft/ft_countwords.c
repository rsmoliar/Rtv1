/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:36:15 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/03/16 12:45:17 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *str, char div)
{
	int ret;

	ret = 0;
	while (*str && *str == div)
		str++;
	while (*str)
	{
		while (*str && *str != div)
			str++;
		ret++;
		while (*str && *str == div)
			str++;
	}
	return (ret);
}
