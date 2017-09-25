/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:02:43 by rsmoliar          #+#    #+#             */
/*   Updated: 2016/12/02 16:17:28 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *buff;
	t_list *alst_cpy;

	alst_cpy = *alst;
	if (alst != NULL)
	{
		while (alst_cpy != NULL)
		{
			buff = alst_cpy->next;
			ft_lstdelone(&alst_cpy, del);
			alst_cpy = buff;
		}
		*alst = NULL;
	}
}
