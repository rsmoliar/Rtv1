/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:39:33 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/03/15 16:17:27 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 8

int					get_next_line(int const fd, char **line);

typedef struct		s_line
{
	char			*temp;
	int				fd;
	struct s_line	*next;
}					t_line;

#endif
