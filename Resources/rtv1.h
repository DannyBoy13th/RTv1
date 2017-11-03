/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:17:00 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/29 18:02:40 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../Libs/libft/libft.h"
# include "../Libs/minilibx/mlx.h"
# include "math.h"
# include "fcntl.h"
# define RESO_X 1024
# define RESO_Y 1024

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef	struct	s_color
{
	double r;
	double g;
	double b;
}				t_color;

typedef struct	s_object
{
	char		type;
	double		rad;
	t_vector	pos;
	t_vector	rot;
	t_color		col;
}				t_object;

typedef struct	s_images
{
	unsigned int	*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				endl;
}				t_images;

typedef struct	s_fdf
{
	t_color			color[5];
	t_vector		campos;
	t_vector		camdir;
	t_vector		center;
	t_vector		p0;
	t_vector		p1;
	t_vector		p2;
	t_vector		pos;
	t_vector		raydir;
	t_images		t;
	t_vector		lgt[4];
	t_vector		hpoint;
	t_vector		normal;
	double			sh_effect;
	double			spec;
	t_vector		lgtdir[4];
	t_object		obj[20];
	double			bright;
	double			len;
	double			newlen;
	char			**line;
	void			*mlx;
	void			*win;
	double			x;
	double			y;
	double			z;
	double			length;
	int				n;
	double			shlen;
	double			nshlen;
	double			x3;
	double			y3;
	int				x2;
	int				y2;
	int				pix;
	int				occl;
	double			dot;
	int				hitindex;
	int				temp;
	int				i;
	double			t0;
	double			t1;
	t_vector		dist;
	double			a;
	double			b;
	double			c;
	int				num_lights;
	int				num_obj;
	int				scene;
	int				glare;
	t_vector		rot;
}				t_fdf;

void			mlx_launcher(t_fdf *res);
void			ft_put_pix(int y, int x, t_color color, t_fdf *res);
int				click_x(void *click);
void			cam_move(int key, t_fdf *res);
void			scene_changer(int key, t_fdf *res);
int				hook_operators(int key, t_fdf *res);
void			brightness(int key, t_fdf *res);
void			set_number(t_fdf *res);
void			scene_selector(t_fdf *res);
t_vector		create_vector(double x, double y, double z);
t_vector		vec_add(t_vector a, t_vector b);
t_vector		vec_sub(t_vector a, t_vector b);
t_vector		vec_mult(t_vector a, double b);
t_color			col_mult_d(t_color a, double b);
t_color			col_mult(t_color a, t_color b);
t_color			col_add(t_color a, t_color b);
t_color			col_clamp(t_color a);
void			set_scene_4_p3(t_fdf *res);
void			vec_normal(t_fdf *res);
void			normalize(t_vector *a);
double			dot(t_vector a, t_vector b);
void			clear_screen(t_fdf *res);
double			mag_calc(t_vector a);
void			ray_init(t_fdf *res);
void			hit_index(t_fdf *res);
void			hit_index_positive(t_fdf *res);
void			shadow_cast(t_fdf *res);
void			object_intersect(t_fdf *res);
void			shadow_object(t_fdf *res, int i);
int				toggle_glare(t_fdf *res);
int				intersect_sphere(t_fdf *res);
int				intersect_cylinder(t_fdf *res);
int				intersect_cone(t_fdf *res);
int				intersect_plane(t_fdf *res);
int				intersect_shadow_sphere(t_fdf *res, int i);
int				intersect_shadow_cylinder(t_fdf *res, int i);
int				intersect_shadow_cone(t_fdf *res, int i);
int				intersect_shadow_plane(t_fdf *res, int i);
void			shine_effect(t_fdf *res);
void			set_number(t_fdf *res);
void			set_cam(t_fdf *res);
void			set_scene_1(t_fdf *res);
void			set_scene_2(t_fdf *res);
void			set_scene_3(t_fdf *res);
void			set_scene_3_p2(t_fdf *res);
void			set_scene_3_p3(t_fdf *res);
void			set_scene_3_p4(t_fdf *res);
void			set_scene_4(t_fdf *res);
void			set_scene_4_p2(t_fdf *res);
void			set_scene_4_p3(t_fdf *res);
void			set_scene_4_p4(t_fdf *res);
void			set_scene_4_p5(t_fdf *res);
void			set_scene_5(t_fdf *res);
void			set_scene_5_p2(t_fdf *res);
void			set_scene_5_p3(t_fdf *res);
void			set_scene_5_p4(t_fdf *res);

#endif
