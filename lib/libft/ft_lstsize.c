/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:53:25 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/07 11:59:39 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		size;
	t_list	*listcpy;

	size = 0;
	listcpy = list;
	while (listcpy != NULL)
	{
		listcpy = listcpy->next;
		size++;
	}
	return (size);
}
