/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:20:24 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:07:19 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"

void	init_scene(int scene_num, t_base *base)
{
	if (scene_num == 1)
		scene_one(base);
	else if (scene_num == 2)
		scene_two(base);
	else if (scene_num == 3)
		scene_three(base);
	else if (scene_num == 4)
		scene_four(base);
	else if (scene_num == 5)
		scene_five(base);
	else if (scene_num == 6)
		scene_six(base);
	else
		error_exit("Bad scene number");
}

void	malloc_scene(t_base *base)
{
	int i;

	i = 0;
	if ((base->scene->objects = (t_base_obj **)ft_memalloc(
					sizeof(t_base_obj) * base->scene->obj_cnt)) == NULL)
		error_exit("memmory can't be allocated");
	if ((base->scene->lights = (t_vector **)ft_memalloc(
					sizeof(t_vector) * base->scene->light_cnt)) == NULL)
		error_exit("memmory can't be allocated");
	while (base->scene->obj_cnt > i)
	{
		if ((base->scene->objects[i] = (t_base_obj *)ft_memalloc(
						sizeof(t_base_obj))) == NULL)
			error_exit("memmory can't be allocated");
		i++;
	}
	i = 0;
	while (base->scene->light_cnt > i)
	{
		if ((base->scene->lights[i] = (t_vector *)ft_memalloc(
						sizeof(t_vector))) == NULL)
			error_exit("memmory can't be allocated");
		i++;
	}
}
