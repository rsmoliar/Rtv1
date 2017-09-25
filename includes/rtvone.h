/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtvone.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmoliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:55:14 by rsmoliar          #+#    #+#             */
/*   Updated: 2017/09/13 18:23:55 by rsmoliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTVONE_H
# define RTVONE_H
# define WWIDTH 1280
# define WHEIGHT 720
# define TYPE_SPHERE 1
# define TYPE_PLANE 2
# define TYPE_CYLINDER 3
# define TYPE_CONE 4
# define PI 3.14159265358979323846
# define THREAD_CNT 8
# define SQR(x) x * x
# define T_MIN 0.0001f
# define T_MAX 100000.0f

# include "libft.h"
# include <pthread.h>

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	org;
	t_vector	dir;
}				t_ray;

typedef struct	s_light_co
{
	double		gl;
	double		lgh;
	double		ref;
}				t_light_co;

typedef struct	s_cam
{
	t_vector	pos;
	t_vector	rot;
	double		ratio;
	double		zoom;
}				t_cam;

typedef struct	s_base_obj
{
	int			type;
	t_vector	coord;
	t_vector	dis;
	t_color		*color;
	t_light_co	lk;
	double		rad;
	double		gloss;
	double		cone_angle;
}				t_base_obj;

typedef struct	s_setup
{
	int			obj_cnt;
	int			light_cnt;
	int			cur_light;
	double		glow_val;
	t_base_obj	**objects;
	t_vector	**lights;
}				t_setup;

typedef struct	s_base
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*i_ptr;
	int			i_bpp;
	int			i_lsize;
	int			i_endian;
	int			part;
	t_setup		*scene;
	t_cam		cam;
}				t_base;

void			error_exit(char *message);
t_vector		new_vector(double x, double y, double z);
t_vector		vector_mult(t_vector pt, double n);
t_vector		vector_add(t_vector *v1, t_vector *v2);
t_vector		vector_sub(t_vector *v1, t_vector *v2);
t_vector		mat_mult(double mat[4][4], t_vector pt);
t_vector		vector_norm(t_vector v);
t_vector		vector_rot(double alpha, double beta, double gamma,
		t_vector pt);
t_vector		get_point(t_ray r, double dist);
t_vector		vector_proj(t_vector u, t_vector v);
double			vector_dist(t_vector u, t_vector v);
double			vector_dot(t_vector *v1, t_vector *v2);
t_vector		get_obj_normal(t_vector hit, t_base_obj obj);
void			create_cam(t_base *base, t_vector o, t_vector rot, double zoom);
void			draw_scene(t_base *base);
int				color_to_int(t_color c);
void			get_part(int *part, t_base *base, t_vector *start,
		t_vector *stop);
void			*ray_trace(void *data);
double			lighting(t_vector hit, t_base_obj *obj, t_base *base,
		int l_num);
double			reflection(t_vector hit, t_base_obj *obj, t_base *base,
		int l_num);
double			glow(t_vector hit, t_base_obj *obj, t_base *base);
int				light_color(t_vector hit, t_base_obj **obj, int obj_num,
		t_base *base);
void			draw_pixel(int x, int y, t_ray ray, t_base *base);
double			trace_object(t_ray *r, t_base_obj *s);
double			trace_sphere(t_ray *r, t_base_obj *s);
double			trace_plane(t_ray *r, t_base_obj *s);
double			trace_cylinder(t_ray *r, t_base_obj *s);
double			trace_cone(t_ray *r, t_base_obj *s);
int				shadow(t_vector hit, t_base *base, int l_num);
double			get_neer_obj(t_ray r, int *num, t_base *base);
void			put_pixel(t_base *base, int x, int y, int color);
void			new_sphere_object(t_base_obj *o, double rad, t_vector pos);
void			new_plane_object(t_base_obj *o, t_vector pos, t_vector dis);
void			new_cyl_object(t_base_obj *o, double rad, t_vector pos,
		t_vector dis);
void			new_cone_object(t_base_obj *o, t_vector pos, t_vector dis);
void			create_color(t_base_obj *obj, double r, double g, double b);
int				rtvone_kh(int kc, t_base *base);
void			init_scene(int scene_num, t_base *base);
void			malloc_scene(t_base *base);
void			scene_one(t_base *base);
void			scene_two(t_base *base);
void			scene_three(t_base *base);
void			scene_four(t_base *base);
void			scene_five(t_base *base);
void			scene_six(t_base *base);
void			cam_zoom(int kc, t_base *base);
void			cam_move(int kc, t_base *base);
void			cam_rotate(int kc, t_base *base);

#endif
