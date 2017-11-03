/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:42:09 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 15:42:11 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ray_init(t_fdf *res)
{
	set_number(res);
	set_cam(res);
	scene_selector(res);
	res->n = res->num_obj;
	res->temp = res->n;
	res->y2 = 0;
	res->len = 100000.0;
	while (res->y2 < RESO_Y)
	{
		res->x2 = 0;
		while (res->x2 < RESO_X)
		{
			res->len = 1000000.0;
			hit_index(res);
			res->x2++;
		}
		res->y2++;
	}
	mlx_put_image_to_window(res->mlx, res->win, res->t.img, 0, 0);
}

void		object_intersect(t_fdf *res)
{
	if (res->obj[res->n].type == 'S')
		res->pix = intersect_sphere(res);
	if (res->obj[res->n].type == 'C')
		res->pix = intersect_cylinder(res);
	if (res->obj[res->n].type == 'K')
		res->pix = intersect_cone(res);
	if (res->obj[res->n].type == 'P')
		res->pix = intersect_plane(res);
}

void		hit_index(t_fdf *res)
{
	while (res->n > 0)
	{
		res->x3 = ((float)(res->x2)) / RESO_X;
		res->y3 = ((float)(res->y2)) / RESO_Y;
		res->pos = vec_add(vec_add(res->p0,
			vec_mult(vec_sub(res->p1, res->p0), res->x3)),
			vec_mult(vec_sub(res->p2, res->p0), res->y3));
		res->raydir = vec_sub(res->pos, res->campos);
		normalize(&res->raydir);
		res->hitindex = -1;
		object_intersect(res);
		if (res->pix == 1)
			res->hitindex = res->n;
		if (res->hitindex != -1)
			hit_index_positive(res);
		res->n--;
	}
	if (res->y2 < RESO_Y)
		res->n = res->num_obj;
}

void		hit_index_positive(t_fdf *res)
{
	res->i = 0;
	res->color[2].r = 0.0;
	res->color[2].g = 0.0;
	res->color[2].b = 0.0;
	while (res->i <= res->num_lights - 1)
	{
		res->hpoint = vec_add(res->pos, vec_mult(res->raydir, res->len));
		res->lgtdir[res->i] = vec_sub(res->lgt[res->i], res->hpoint);
		res->shlen = sqrtf(dot(res->lgtdir[res->i], res->lgtdir[res->i]));
		normalize(&res->lgtdir[res->i]);
		shadow_cast(res);
		res->i++;
	}
	res->color[2] = col_clamp(res->color[2]);
	ft_put_pix(res->y2, res->x2, res->color[2], res);
}

void		shadow_cast(t_fdf *res)
{
	int i;

	i = 0;
	res->occl = 0;
	vec_normal(res);
	shine_effect(res);
	while (i <= res->num_obj)
	{
		shadow_object(res, i);
		if (res->occl == 1)
			break ;
		i++;
	}
	if (res->occl != 1)
	{
		res->dot = dot(res->normal, res->lgtdir[res->i]);
		if (res->dot < 0.0)
			res->dot = 0.0;
		res->color[2] = col_add(res->color[2], col_mult_d(col_add(col_mult(
			res->obj[res->hitindex].col, res->color[1]),
				col_add(res->color[2], col_mult_d(res->color[4],
					res->spec * res->glare))), res->dot * res->bright));
	}
}
