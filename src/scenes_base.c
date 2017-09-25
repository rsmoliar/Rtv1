/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 15:41:55 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:51:09 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"

void	scene_one(t_base *base)
{
	base->scene->obj_cnt = 1;
	base->scene->glow_val = 0.5;
	base->scene->light_cnt = 1;
	malloc_scene(base);
	new_sphere_object(base->scene->objects[0], 180, new_vector(0, 0, 0));
	create_color(base->scene->objects[0], 128, 5, 13);
	*base->scene->lights[0] = new_vector(-100, 125, 500);
	create_cam(base, new_vector(-500, 300, 500),
			new_vector(-22, -45, 0), 60);
}

void	scene_two(t_base *base)
{
	base->scene->obj_cnt = 1;
	base->scene->glow_val = 0.5;
	base->scene->light_cnt = 1;
	malloc_scene(base);
	new_cyl_object(base->scene->objects[0], 60, new_vector(0, 0, 0),
			new_vector(0, 1, 0));
	create_color(base->scene->objects[0], 0, 200, 0);
	*base->scene->lights[0] = new_vector(0, 0, 500);
	create_cam(base, new_vector(0, 0, 500), new_vector(0, 0, 0), 35);
}

void	scene_three(t_base *base)
{
	base->scene->obj_cnt = 2;
	base->scene->glow_val = 0.5;
	base->scene->light_cnt = 1;
	malloc_scene(base);
	new_plane_object(base->scene->objects[0], new_vector(0, -100, 0),
			new_vector(0, 99, 0));
	new_cone_object(base->scene->objects[1], new_vector(0, 0, 0),
			new_vector(0, 1, 0));
	create_color(base->scene->objects[0], 0, 0, 240);
	create_color(base->scene->objects[1], 255, 251, 28);
	*base->scene->lights[0] = new_vector(400, 0, 400);
	create_cam(base, new_vector(0, 0, 500), new_vector(0, 0, 0), 50);
}

void	scene_four(t_base *base)
{
	base->scene->obj_cnt = 5;
	base->scene->glow_val = 0.5;
	base->scene->light_cnt = 1;
	malloc_scene(base);
	new_plane_object(base->scene->objects[0], new_vector(0, 0, -400),
			new_vector(0, 0, -350));
	new_plane_object(base->scene->objects[1], new_vector(0, -100, -400),
			new_vector(0, 400, -350));
	new_cyl_object(base->scene->objects[2], 40, new_vector(-100, -50, -75),
			new_vector(0, 1, 0));
	new_cone_object(base->scene->objects[3], new_vector(250, -50, 0),
			new_vector(100, 1, 0));
	new_sphere_object(base->scene->objects[4], 100,
			new_vector(100, -50, -50));
	base->scene->objects[2]->dis = vector_rot(0, 0, -55 * (PI / 180),
			base->scene->objects[1]->dis);
	create_color(base->scene->objects[0], 5, 115, 232);
	create_color(base->scene->objects[1], 64, 64, 64);
	create_color(base->scene->objects[2], 47, 158, 47);
	create_color(base->scene->objects[3], 255, 238, 0);
	create_color(base->scene->objects[4], 232, 12, 12);
	*base->scene->lights[0] = new_vector(400, 0, 400);
	create_cam(base, new_vector(0, 0, 500), new_vector(0, 0, 0), 50);
}

void	scene_five(t_base *base)
{
	base->scene->obj_cnt = 3;
	base->scene->glow_val = 0.5;
	base->scene->light_cnt = 1;
	malloc_scene(base);
	new_sphere_object(base->scene->objects[0], 180, new_vector(0, 0, 0));
	new_plane_object(base->scene->objects[1], new_vector(0, -220, 0),
			new_vector(0, -100, 0));
	new_cyl_object(base->scene->objects[2], 40, new_vector(-240, 0, 0),
			new_vector(0, 1, 0));
	create_color(base->scene->objects[0], 128, 5, 13);
	create_color(base->scene->objects[1], 4, 133, 219);
	create_color(base->scene->objects[2], 240, 88, 25);
	*base->scene->lights[0] = new_vector(-100, 125, 500);
	create_cam(base, new_vector(-500, 200, 500),
			new_vector(-22, -45, 0), 60);
}
