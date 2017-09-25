/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:44:24 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:03:06 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"

int		color_to_int(t_color c)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	c.r = (c.r > 1.0f) ? 1.0f : c.r;
	c.g = (c.g > 1.0f) ? 1.0f : c.g;
	c.b = (c.b > 1.0f) ? 1.0f : c.b;
	c.r = (c.r < 0.0f) ? 0.0f : c.r;
	c.g = (c.g < 0.0f) ? 0.0f : c.g;
	c.b = (c.b < 0.0f) ? 0.0f : c.b;
	r = (c.r / 1.0f) * 255;
	g = (c.g / 1.0f) * 255;
	b = (c.b / 1.0f) * 255;
	return ((r << 16) + (g << 8) + b);
}

void	create_color(t_base_obj *obj, double r, double g, double b)
{
	if ((obj->color = (t_color *)ft_memalloc(sizeof(t_color))) == NULL)
		error_exit("memmory can't be allocated");
	obj->color->r = r / 255;
	obj->color->g = g / 255;
	obj->color->b = b / 255;
}
