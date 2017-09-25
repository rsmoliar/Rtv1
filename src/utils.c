/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:14:44 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:10:48 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include <stdlib.h>

void	error_exit(char *message)
{
	char	*err;

	err = ft_strnew(ft_strlen("\x1b[31mError: \x1b[0m"));
	err = "\x1b[31mError: \x1b[0m";
	ft_putendl(ft_strjoin(err, message));
	exit(1);
}

void	create_cam(t_base *base, t_vector o, t_vector rot, double zoom)
{
	base->cam.pos = o;
	base->cam.rot.x = rot.x * (PI / 180);
	base->cam.rot.y = rot.y * (PI / 180);
	base->cam.rot.z = rot.z * (PI / 180);
	base->cam.ratio = (double)WWIDTH / (double)WHEIGHT;
	base->cam.zoom = (zoom / 2.0f) * (PI / 180.0f);
}
