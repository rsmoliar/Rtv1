/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:09:44 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/11/26 17:01:37 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *deststr, const char *srcstr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (deststr[i] != '\0')
		i++;
	while (srcstr[j] != '\0')
	{
		deststr[i + j] = srcstr[j];
		j++;
	}
	deststr[i + j] = '\0';
	return (deststr);
}
