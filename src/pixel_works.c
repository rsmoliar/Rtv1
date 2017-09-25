/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_works.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 11:53:09 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:06:16 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include "mlx.h"

void	put_pixel(t_base *base, int x, int y, int color)
{
	int				i;
	unsigned char	c_byte;
	unsigned int	img_color;

	i = 0;
	if (x >= WWIDTH || y >= WHEIGHT || x < 0 || y < 0)
		return ;
	img_color = mlx_get_color_value(base->mlx, color);
	while (i < (base->i_bpp / 8))
	{
		if (base->i_endian)
			c_byte = (img_color & (0xFF000000 >> (i * 8)))
						>> (((base->i_bpp / 8) - i - 1) * 8);
		else
			c_byte = (img_color & (0xFF << (i * 8))) >> (i * 8);
		base->i_ptr[(x * (base->i_bpp / 8)) + (y * base->i_lsize) + i] =
			c_byte;
		i++;
	}
}
