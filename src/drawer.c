/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:47:30 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:03:20 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include "mlx.h"
#include <pthread.h>
#include <math.h>

void		get_part(int *part, t_base *base, t_vector *start, t_vector *stop)
{
	start->z = -1;
	if (THREAD_CNT != 8)
		error_exit("wrong threads number.");
	start->x = (*part % 4) * (WWIDTH / 4);
	start->y = (*part < 4) ? 0 : (WHEIGHT / 2);
	stop->x = ((*part % 4) + 1) * (WWIDTH / 4);
	stop->y = (*part < 4) ? (WHEIGHT / 2) : WHEIGHT;
	base->part++;
}

t_vector	get_point(t_ray r, double dist)
{
	t_vector	p;

	p.x = r.org.x + (dist * r.dir.x);
	p.y = r.org.y + (dist * r.dir.y);
	p.z = r.org.z + (dist * r.dir.z);
	return (p);
}

void		*ray_trace(void *data)
{
	t_vector	start;
	t_vector	stop;
	t_ray		ray;

	get_part(&((t_base *)data)->part, (t_base *)data, &start, &stop);
	while (start.y < stop.y)
	{
		start.x = 0;
		while (start.x < stop.x)
		{
			ray.dir.x = (2.0 * ((start.x + 0.5) / WWIDTH) - 1.0)
				* tan(((t_base *)data)->cam.zoom) * ((t_base *)data)->cam.ratio;
			ray.dir.y = (1.0 - 2.0 * ((start.y + 0.5) / WHEIGHT))
				* tan(((t_base *)data)->cam.zoom);
			ray.dir.z = -1;
			ray.org = ((t_base *)data)->cam.pos;
			ray.dir = vector_rot(((t_base *)data)->cam.rot.x,
					((t_base *)data)->cam.rot.y, ((t_base *)data)->cam.rot.z,
					vector_norm(ray.dir));
			draw_pixel(start.x, start.y, ray, (t_base *)data);
			start.x++;
		}
		start.y++;
	}
	return (NULL);
}

void		draw_scene(t_base *base)
{
	int			i;
	pthread_t	threads[THREAD_CNT];

	i = 0;
	base->part = 0;
	while (i < THREAD_CNT)
	{
		if (pthread_create(&threads[i], NULL, ray_trace, base))
			error_exit("thread error.");
		i++;
	}
	i = 0;
	while (i < THREAD_CNT)
	{
		if (pthread_join(threads[i], NULL))
			error_exit("thread error.");
		i++;
	}
	mlx_put_image_to_window(base->mlx, base->window, base->image, 0, 0);
}
