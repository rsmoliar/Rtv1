/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 13:11:00 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:04:35 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include "mlx.h"

void	init_base(int scene_num)
{
	t_base	*base;

	if ((base = ft_memalloc(sizeof(t_base))) == NULL)
		error_exit("memmory can't be allocated");
	base->mlx = mlx_init();
	base->window = mlx_new_window(base->mlx, WWIDTH, WHEIGHT, "RTv1");
	base->image = mlx_new_image(base->mlx, WWIDTH, WHEIGHT);
	base->i_ptr = mlx_get_data_addr(base->image, &base->i_bpp, &base->i_lsize,
			&base->i_endian);
	if ((base->scene = (t_setup *)ft_memalloc(sizeof(t_setup))) == NULL)
		error_exit("memmory can't be allocated");
	init_scene(scene_num, base);
	draw_scene(base);
	mlx_key_hook(base->window, rtvone_kh, base);
	mlx_loop(base->mlx);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		init_base(ft_atoi(argv[1]));
	else
		ft_putendl("\e[32mUsage: ./RTv1 <1, 2, 3, 4, 5>\e[0m");
	return (0);
}
