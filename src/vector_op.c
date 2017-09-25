/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:22:53 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 17:07:40 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include <math.h>

t_vector	new_vector(double x, double y, double z)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vector	mat_mult(double mat[4][4], t_vector pt)
{
	t_vector	out;

	out.x = (mat[0][0] * pt.x) + (mat[1][0] * pt.y) +
			(mat[2][0] * pt.z) + (mat[3][0] * 1);
	out.y = (mat[0][1] * pt.x) + (mat[1][1] * pt.y) +
			(mat[2][1] * pt.z) + (mat[3][1] * 1);
	out.z = (mat[0][2] * pt.x) + (mat[1][2] * pt.y) +
			(mat[2][2] * pt.z) + (mat[3][2] * 1);
	return (out);
}

t_vector	vector_norm(t_vector v)
{
	double	mag;

	mag = sqrt(SQR(v.x) + SQR(v.y) + SQR(v.z));
	v.x = v.x / mag;
	v.y = v.y / mag;
	v.z = v.z / mag;
	return (v);
}

t_vector	vector_proj(t_vector u, t_vector v)
{
	t_vector	proj;
	double		dot;

	dot = vector_dot(&u, &v) / vector_dot(&v, &v);
	proj = vector_mult(v, dot);
	return (proj);
}

double		vector_dist(t_vector u, t_vector v)
{
	return (sqrt(SQR((u.x - v.x)) + SQR((u.y - v.y)) + SQR((u.z - v.z))));
}
