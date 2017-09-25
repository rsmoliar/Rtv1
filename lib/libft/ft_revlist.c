/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:19:34 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/04/08 12:27:55 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revlist(t_list **lst)
{
	t_list	*prev;
	t_list	*next;
	t_list	*buff;

	buff = *lst;
	prev = NULL;
	next = NULL;
	while (buff)
	{
		next = buff->next;
		buff->next = prev;
		prev = buff;
		buff = next;
	}
	*lst = prev;
}
