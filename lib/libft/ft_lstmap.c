/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:03:42 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/07 12:04:41 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *result_buff;

	if (lst != NULL)
	{
		result_buff = NULL;
		result = (t_list *)malloc(ft_lstsize(lst) * sizeof(t_list));
		if (result != NULL)
		{
			result = f(ft_lstnew(lst->content, lst->content_size));
			result_buff = result;
			lst = lst->next;
			while (lst != NULL)
			{
				result_buff->next = f(ft_lstnew(lst->content,
							lst->content_size));
				result_buff = result_buff->next;
				lst = lst->next;
			}
		}
		return (result);
	}
	return (NULL);
}
