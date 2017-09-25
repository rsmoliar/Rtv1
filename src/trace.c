/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:09:40 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:09:45 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include <math.h>

double	trace_object(t_ray *r, t_base_obj *s)
{
	if (s->type == TYPE_SPHERE)
		return (trace_sphere(r, s));
	else if (s->type == TYPE_PLANE)
		return (trace_plane(r, s));
	else if (s->type == TYPE_CYLINDER)
		return (trace_cylinder(r, s));
	else if (s->type == TYPE_CONE)
		return (trace_cone(r, s));
	else
	{
		error_exit("unknow object type.");
		return (-1);
	}
}

double	trace_sphere(t_ray *r, t_base_obj *s)
{
	t_vector	q;
	t_vector	d;
	double		disc;
	double		t;

	d = r->dir;
	q.x = (SQR(d.x)) + (SQR(d.y)) + (SQR(d.z));
	q.y = 2.0f * d.x * (r->org.x - s->coord.x) + 2.0f * d.y *
		(r->org.y - s->coord.y) + 2.0f * d.z * (r->org.z - s->coord.z);
	q.z = (SQR(s->coord.x)) + (SQR(s->coord.y)) + (SQR(s->coord.z))
		+ (SQR(r->org.x)) + (SQR(r->org.y)) + (SQR(r->org.z))
		+ (-2.0f * (s->coord.x * r->org.x + s->coord.y * r->org.y + s->coord.z
					* r->org.z)) - (SQR(s->rad));
	disc = (SQR(q.y)) - (4.0f * q.x * q.z);
	if (disc < 0)
		return (T_MAX);
	t = (-q.y - sqrt(disc)) / (2.0f * q.x);
	if (t > T_MAX || t < T_MIN)
		return (T_MAX);
	return (t);
}

double	trace_plane(t_ray *r, t_base_obj *s)
{
	double		t;
	double		ddotv;
	double		xdotv;
	t_vector	x;

	x = vector_sub(&r->org, &s->coord);
	ddotv = vector_dot(&r->dir, &s->dis);
	xdotv = vector_dot(&x, &s->dis);
	if (ddotv != 0)
	{
		t = -xdotv / ddotv;
		if (t > T_MIN && t < T_MAX)
			return (t);
	}
	return (T_MAX);
}

double	trace_cylinder(t_ray *r, t_base_obj *s)
{
	t_vector	q;
	double		disc;
	double		t;
	t_vector	x;

	x = vector_sub(&r->org, &s->coord);
	q.x = vector_dot(&r->dir, &r->dir) - (vector_dot(&r->dir, &s->dis)
			* vector_dot(&r->dir, &s->dis));
	q.y = vector_dot(&r->dir, &x) - (vector_dot(&r->dir, &s->dis)
			* vector_dot(&x, &s->dis));
	q.y *= 2;
	q.z = vector_dot(&x, &x) - (vector_dot(&x, &s->dis) *
			vector_dot(&x, &s->dis)) - (SQR(s->rad));
	disc = (SQR(q.y)) - (4.0f * q.x * q.z);
	t = (-q.y - sqrt(disc)) / (2.0f * q.x);
	if (t > T_MAX || t < T_MIN)
		return (T_MAX);
	return (t);
}

double	trace_cone(t_ray *r, t_base_obj *s)
{
	t_vector	q;
	t_vector	x;
	double		disc;
	double		t;
	double		k;

	x = vector_sub(&r->org, &s->coord);
	k = tan(s->cone_angle);
	q.x = vector_dot(&r->dir, &r->dir) - (1 + k * k) *
		(SQR(vector_dot(&r->dir, &s->dis)));
	q.y = vector_dot(&r->dir, &x) - (1 + (SQR(k)))
			* vector_dot(&r->dir, &s->dis) * vector_dot(&x, &s->dis);
	q.y *= 2;
	q.z = vector_dot(&x, &x) - (1 + (SQR(k))) * (SQR(vector_dot(&x, &s->dis)));
	disc = (SQR(q.y)) - (4.0f * q.x * q.z);
	if (disc < 0)
		return (T_MAX);
	t = (-q.y - sqrt(disc)) / (2.0f * q.x);
	if (t > T_MAX || t < T_MIN)
		return (T_MAX);
	return (t);
}
