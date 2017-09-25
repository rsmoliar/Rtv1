/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:02:50 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/21 14:48:37 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *deststr, const char *srcstr)
{
	int i;

	i = 0;
	while (srcstr[i] != '\0')
	{
		deststr[i] = srcstr[i];
		i++;
	}
	deststr[i] = '\0';
	return (deststr);
}
