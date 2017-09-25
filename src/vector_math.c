/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:35:23 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 16:13:09 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtvone.h"
#include <stdlib.h>
#include <math.h>

t_vector	vector_add(t_vector *v1, t_vector *v2)
{
	t_vector	ret;

	ret.x = v1->x + v2->x;
	ret.y = v1->y + v2->y;
	ret.z = v1->z + v2->z;
	return (ret);
}

t_vector	vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector	ret;

	ret.x = v1->x - v2->x;
	ret.y = v1->y - v2->y;
	ret.z = v1->z - v2->z;
	return (ret);
}

t_vector	vector_mult(t_vector pt, double n)
{
	pt.x *= n;
	pt.y *= n;
	pt.z *= n;
	return (pt);
}

t_vector	vector_rot(double alpha, double beta, double gamma, t_vector pt)
{
	double mat[4][4];

	mat[0][0] = cos(beta) * cos(gamma);
	mat[1][0] = cos(gamma) * sin(alpha) * sin(beta) - cos(alpha) * sin(gamma);
	mat[2][0] = cos(alpha) * cos(gamma) * sin(beta) + sin(alpha) * sin(gamma);
	mat[3][0] = 0;
	mat[0][1] = cos(beta) * sin(gamma);
	mat[1][1] = cos(alpha) * cos(gamma) + sin(alpha) * sin(beta) * sin(gamma);
	mat[2][1] = -cos(gamma) * sin(alpha) + cos(alpha) * sin(beta) * sin(gamma);
	mat[3][1] = 0;
	mat[0][2] = -sin(beta);
	mat[1][2] = cos(beta) * sin(alpha);
	mat[2][2] = cos(alpha) * cos(beta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (mat_mult(mat, pt));
}

double		vector_dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
