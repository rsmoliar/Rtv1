/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:29:04 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:03:43 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include <math.h>

double	lighting(t_vector hit, t_base_obj *obj, t_base *base, int l_num)
{
	double		l_angle;
	t_vector	norm;
	t_vector	n;

	n = get_obj_normal(hit, *obj);
	norm = vector_norm(vector_sub(base->scene->lights[l_num], &hit));
	l_angle = vector_dot(&n, &norm);
	if (l_angle == 0)
		return (0);
	if (shadow(hit, base, l_num))
		return (obj->lk.lgh * l_angle);
	else
		return (0);
}

double	reflection(t_vector hit, t_base_obj *obj, t_base *base, int l_num)
{
	t_vector	h;
	t_vector	l;
	t_vector	n;
	double		spec;

	if (obj->lk.ref <= 0)
		return (0);
	n = get_obj_normal(hit, *obj);
	l = vector_norm(vector_sub(base->scene->lights[l_num], &hit));
	hit = vector_norm(vector_sub(&base->cam.pos, &hit));
	h = vector_norm(vector_add(&hit, &l));
	spec = pow(vector_dot(&h, &n), obj->gloss);
	return (spec * obj->lk.ref);
}

double	glow(t_vector hit, t_base_obj *obj, t_base *base)
{
	double		hit_angle;
	t_vector	norm;
	t_vector	n;

	n = get_obj_normal(hit, *obj);
	norm = vector_norm(vector_sub(&base->cam.pos, &hit));
	hit_angle = vector_dot(&n, &norm);
	if (hit_angle >= 0)
		return (base->scene->glow_val * obj->lk.gl * hit_angle);
	else
		return (0);
}

int		light_color(t_vector hit, t_base_obj **obj, int obj_num, t_base *base)
{
	t_color		color;
	t_light_co	light;
	double		light_colorination;
	int			i;

	ft_memset(&light, 0, sizeof(light));
	light.gl = glow(hit, obj[obj_num], base);
	i = 0;
	while (i < base->scene->light_cnt)
	{
		light_colorination = lighting(hit, obj[obj_num], base, i);
		if (light_colorination > 0)
		{
			light.lgh += light_colorination;
			light.ref += reflection(hit, obj[obj_num], base, i);
		}
		i++;
	}
	color.r = obj[obj_num]->color->r * (light.gl + light.lgh) + light.ref * 1;
	color.g = obj[obj_num]->color->g * (light.gl + light.lgh) + light.ref * 1;
	color.b = obj[obj_num]->color->b * (light.gl + light.lgh) + light.ref * 1;
	color.r = 1.0f - exp(-color.r);
	color.g = 1.0f - exp(-color.g);
	color.b = 1.0f - exp(-color.b);
	return (color_to_int(color));
}

void	draw_pixel(int x, int y, t_ray ray, t_base *base)
{
	double		dst;
	int			color;
	int			obj_cnt;
	t_vector	hit;

	obj_cnt = -1;
	dst = get_neer_obj(ray, &obj_cnt, base);
	if (dst < T_MAX)
	{
		hit = get_point(ray, dst);
		color = light_color(hit, base->scene->objects, obj_cnt, base);
		put_pixel(base, x, y, color);
	}
	else
		put_pixel(base, x, y, 0);
}
