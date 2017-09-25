/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:37:38 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/08 16:54:06 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strrev(char *str)
{
	char	*buffer;
	char	tmp;

	if (!str)
		return ;
	buffer = str;
	while (*buffer)
		buffer++;
	buffer--;
	while (str < buffer)
	{
		tmp = *str;
		*str++ = *buffer;
		*buffer-- = tmp;
	}
}
