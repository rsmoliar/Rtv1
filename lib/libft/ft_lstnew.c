/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:58:19 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/02 15:23:34 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;

	result = (t_list*)malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	if (content == NULL)
	{
		result->content = NULL;
		result->content_size = 0;
	}
	else
	{
		result->content = malloc(content_size);
		if (result->content == NULL)
			return (NULL);
		ft_memcpy((result->content), content, content_size);
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
