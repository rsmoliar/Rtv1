/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_works.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 12:25:40 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:05:46 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include <stdlib.h>
#include <math.h>

int			shadow(t_vector hit, t_base *base, int l_num)
{
	int		obj_num;
	t_ray	ray;
	double	dist;
	double	l_dist;

	obj_num = -1;
	ray.org = hit;
	ray.dir = vector_norm(vector_sub(base->scene->lights[l_num], &hit));
	dist = get_neer_obj(ray, &obj_num, base);
	if (dist < T_MAX && dist > T_MIN)
	{
		l_dist = vector_dist(*base->scene->lights[l_num], hit);
		if (dist < l_dist)
			return (0);
	}
	return (1);
}

double		get_neer_obj(t_ray r, int *num, t_base *base)
{
	int		i;
	int		closest;
	double	*distances;
	double	out;

	i = 0;
	closest = 0;
	distances = ft_memalloc(sizeof(double) * base->scene->obj_cnt);
	while (i < base->scene->obj_cnt)
	{
		distances[i] = trace_object(&r, base->scene->objects[i]);
		i++;
	}
	i = 0;
	while (i < base->scene->obj_cnt)
	{
		if (distances[i] < distances[closest] && distances[i] > T_MIN)
			closest = i;
		i++;
	}
	*num = closest;
	out = distances[closest];
	free(distances);
	distances = NULL;
	return (out);
}

t_vector	get_obj_normal(t_vector hit, t_base_obj obj)
{
	t_vector	n;
	t_vector	proj;
	double		k;

	n = new_vector(0, 0, 0);
	k = 0;
	if (obj.type == TYPE_SPHERE)
		n = vector_norm(vector_sub(&hit, &obj.coord));
	else if (obj.type == TYPE_PLANE)
		n = obj.dis;
	else if (obj.type == TYPE_CYLINDER)
	{
		n = vector_sub(&hit, &obj.coord);
		proj = vector_proj(n, obj.dis);
		n = vector_norm(vector_sub(&n, &proj));
	}
	else if (obj.type == TYPE_CONE)
	{
		n = vector_sub(&hit, &obj.coord);
		proj = vector_proj(n, obj.dis);
		k = 1 + tan(obj.cone_angle) * tan(obj.cone_angle);
		proj = vector_mult(proj, k);
		n = vector_norm(vector_sub(&n, &proj));
	}
	return (n);
}
