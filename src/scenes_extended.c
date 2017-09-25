/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_extended.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:37:45 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 17:06:08 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"

void	create_scene_objects(t_base *base)
{
	new_plane_object(base->scene->objects[0], new_vector(0, 100, 0),
			new_vector(0, 99, 0));
	new_plane_object(base->scene->objects[1], new_vector(0, 0, -400),
			new_vector(0, 0, -399));
	new_plane_object(base->scene->objects[2], new_vector(0, -100, 0),
			new_vector(0, -99, 0));
	new_cyl_object(base->scene->objects[3], 25, new_vector(-200, 0, 25),
			new_vector(0, 1, 0));
	new_cyl_object(base->scene->objects[4], 25, new_vector(200, 0, 25),
			new_vector(0, 1, 0));
	new_cyl_object(base->scene->objects[5], 25, new_vector(-200, 0, -250),
			new_vector(0, 1, 0));
	new_cyl_object(base->scene->objects[6], 25, new_vector(200, 0, -250),
			new_vector(0, 1, 0));
	new_sphere_object(base->scene->objects[7], 40, new_vector(-200, 95, 25));
	new_sphere_object(base->scene->objects[8], 40, new_vector(-200, -95, 25));
	new_sphere_object(base->scene->objects[9], 40, new_vector(200, 95, 25));
	new_sphere_object(base->scene->objects[10], 40, new_vector(200, -95, 25));
	new_sphere_object(base->scene->objects[11], 40, new_vector(-200, 95, -250));
	new_sphere_object(base->scene->objects[12], 40,
			new_vector(-200, -95, -250));
	new_sphere_object(base->scene->objects[13], 40, new_vector(200, 95, -250));
	new_sphere_object(base->scene->objects[14], 40, new_vector(200, -95, -250));
	new_sphere_object(base->scene->objects[15], 30, new_vector(0, -30, 50));
}

void	scene_six(t_base *base)
{
	base->scene->obj_cnt = 16;
	base->scene->glow_val = 0.5;
	base->scene->light_cnt = 2;
	malloc_scene(base);
	create_scene_objects(base);
	create_color(base->scene->objects[0], 31, 31, 31);
	create_color(base->scene->objects[1], 37, 130, 230);
	create_color(base->scene->objects[2], 107, 107, 107);
	create_color(base->scene->objects[3], 141, 142, 143);
	create_color(base->scene->objects[4], 141, 142, 143);
	create_color(base->scene->objects[5], 141, 142, 143);
	create_color(base->scene->objects[6], 141, 142, 143);
	create_color(base->scene->objects[7], 141, 142, 143);
	create_color(base->scene->objects[8], 141, 142, 143);
	create_color(base->scene->objects[9], 141, 142, 143);
	create_color(base->scene->objects[10], 141, 142, 143);
	create_color(base->scene->objects[11], 141, 142, 143);
	create_color(base->scene->objects[12], 141, 142, 143);
	create_color(base->scene->objects[13], 141, 142, 143);
	create_color(base->scene->objects[14], 141, 142, 143);
	create_color(base->scene->objects[15], 250, 30, 30);
	*base->scene->lights[0] = new_vector(-400, 90, 175);
	*base->scene->lights[1] = new_vector(400, 90, 175);
	create_cam(base, new_vector(0, 0, 500), new_vector(0, 0, 0), 50);
}
