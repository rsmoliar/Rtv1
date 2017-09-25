/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:07:38 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:05:08 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"

void	new_sphere_object(t_base_obj *o, double rad, t_vector pos)
{
	o->type = TYPE_SPHERE;
	o->lk.gl = 1;
	o->lk.lgh = 0.9;
	o->lk.ref = 0.9;
	o->gloss = 100;
	o->rad = rad;
	o->coord = pos;
}

void	new_plane_object(t_base_obj *o, t_vector pos, t_vector dis)
{
	o->type = TYPE_PLANE;
	o->lk.gl = 0.4;
	o->lk.lgh = 0.6;
	o->lk.ref = 0.2;
	o->gloss = 10;
	o->coord = pos;
	o->dis = vector_norm(vector_sub(&dis, &o->coord));
}

void	new_cyl_object(t_base_obj *o, double rad, t_vector pos, t_vector dis)
{
	o->type = TYPE_CYLINDER;
	o->lk.gl = 0.7;
	o->lk.lgh = 0.6;
	o->lk.ref = 0.7;
	o->gloss = 50;
	o->rad = rad;
	o->coord = pos;
	o->dis = dis;
}

void	new_cone_object(t_base_obj *o, t_vector pos, t_vector dis)
{
	o->type = TYPE_CONE;
	o->lk.gl = 1;
	o->lk.lgh = 0.6;
	o->lk.ref = 0.8;
	o->gloss = 50;
	o->coord = pos;
	o->dis = new_vector(0, 1, 0);
	o->dis = vector_rot(dis.x, dis.y, dis.z, o->dis);
	o->cone_angle = 35.0f * (PI / 180);
}
