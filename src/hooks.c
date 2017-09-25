/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:59:18 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:04:16 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtvone.h"
#include "mlx.h"

int		rtvone_kh(int kc, t_base *base)
{
	if (kc == 53)
		exit(0);
	else if (kc == 78 || kc == 69)
		cam_zoom(kc, base);
	else if (kc >= 123 && kc <= 126)
		cam_move(kc, base);
	else if (kc == 13 || kc == 12 || kc == 14 || kc == 0 || kc == 1 || kc == 2)
		cam_rotate(kc, base);
	return (0);
}

void	cam_zoom(int kc, t_base *base)
{
	if (kc == 69)
	{
		if (base->cam.zoom >= 2 * (PI / 180))
		{
			base->cam.zoom -= 2 * (PI / 180);
			draw_scene(base);
		}
	}
	else if (kc == 78)
	{
		base->cam.zoom += 2 * (PI / 180);
		draw_scene(base);
	}
}

void	cam_move(int kc, t_base *base)
{
	if (kc == 126)
		base->cam.pos.y += 10;
	else if (kc == 125)
		base->cam.pos.y -= 10;
	else if (kc == 124)
		base->cam.pos.x += 10;
	else if (kc == 123)
		base->cam.pos.x -= 10;
	draw_scene(base);
}

void	cam_rotate(int kc, t_base *base)
{
	if (kc == 13)
		base->cam.rot.x += 10 * (PI / 180);
	else if (kc == 1)
		base->cam.rot.x -= 10 * (PI / 180);
	else if (kc == 0)
		base->cam.rot.y += 10 * (PI / 180);
	else if (kc == 2)
		base->cam.rot.y -= 10 * (PI / 180);
	else if (kc == 12)
		base->cam.rot.z += 10 * (PI / 180);
	else if (kc == 14)
		base->cam.rot.z -= 10 * (PI / 180);
	draw_scene(base);
}
