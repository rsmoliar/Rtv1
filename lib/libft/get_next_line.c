/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:39:12 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/02/03 14:59:39 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line		*get_current(t_line **head, int fd)
{
	t_line			*last;
	t_line			*start;

	last = *head;
	while (last != NULL)
	{
		if (last->temp == NULL)
			last->temp = ft_strnew(0);
		if (last->fd == fd)
			return (last);
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	start = (t_line*)malloc(sizeof(t_line));
	if (start == NULL)
		return (NULL);
	start->fd = fd;
	start->next = *head;
	start->temp = ft_strnew(0);
	*head = start;
	return (start);
}

static void			buff_to_str(char **str, const char *buff)
{
	char			*result;

	result = ft_strjoin(*str, buff);
	free(*str);
	*str = result;
}

static int			read_file(t_line *list, char **str)
{
	int				rd;
	char			*buffer;

	if (!(buffer = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	ft_strdel(&list->temp);
	while ((rd = read(list->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		buff_to_str(str, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buffer);
	if (rd == 0)
		return (0);
	else if (rd > 0)
		return (1);
	else
		return (-1);
}

int					get_next_line(int const fd, char **line)
{
	static t_line	*gnl;
	t_line			*current;
	int				rd;
	char			*str;
	char			*endl;

	if (line == NULL || BUFF_SIZE < 1)
		return (-1);
	current = get_current(&gnl, fd);
	str = ft_strdup(current->temp);
	if ((rd = read_file(current, &str)) == -1)
		return (-1);
	else if (rd == 0 && ft_strlen(str) == 0)
		return (0);
	endl = ft_strchr(str, '\n');
	if (endl == NULL)
	{
		endl = ft_strchr(str, '\0');
		current->temp = ft_strnew(0);
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(endl));
	if (current->temp == NULL)
		current->temp = ft_strdup(endl + 1);
	ft_strdel(&str);
	return (1);
}
