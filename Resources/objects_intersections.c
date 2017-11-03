/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_intersections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:42:20 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 17:41:25 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	vec_normal(t_fdf *res)
{
	if (res->obj[res->hitindex].type == 'P')
		res->normal = vec_sub(res->obj[res->hitindex].rot,
			res->obj[res->hitindex].pos);
	if (res->obj[res->hitindex].type == 'S')
		res->normal = vec_sub(res->hpoint, res->obj[res->hitindex].pos);
	if (res->obj[res->hitindex].type == 'C' ||
		res->obj[res->hitindex].type == 'K')
		res->normal = create_vector(((res->obj[res->hitindex].pos.x -
			res->hpoint.x) * -1) * res->obj[res->hitindex].rot.y,
			((res->obj[res->hitindex].pos.y - res->hpoint.y) * -1) *
			res->obj[res->hitindex].rot.x, (res->obj[res->hitindex].pos.z -
			res->hpoint.z) * -1);
	normalize(&res->normal);
}

int		intersect_sphere(t_fdf *res)
{
	double d;

	res->dist = vec_sub(res->obj[res->n].pos, res->campos);
	res->a = dot(res->raydir, res->raydir);
	res->b = dot(res->raydir, res->dist);
	res->c = dot(res->dist, res->dist) -
		(res->obj[res->n].rad * res->obj[res->n].rad);
	d = res->b * res->b - res->a * res->c;
	if (d < 0)
		return (0);
	res->newlen = (res->b - sqrtf(d)) / (res->a);
	if (res->len >= res->newlen && res->newlen >= 0.0001)
	{
		res->len = res->newlen;
		return (1);
	}
	return (0);
}

int		intersect_cylinder(t_fdf *res)
{
	double d;

	res->dist = vec_sub(res->obj[res->n].pos, res->campos);
	normalize(&res->obj[res->n].rot);
	res->a = dot(res->raydir, res->raydir) -
		pow(dot(res->raydir, res->obj[res->n].rot), 2);
	res->b = (dot(res->raydir, res->dist) -
		(dot(res->raydir, res->obj[res->n].rot) *
			dot(res->dist, res->obj[res->n].rot)));
	res->c = dot(res->dist, res->dist) -
		pow(dot(res->dist, res->obj[res->n].rot), 2) -
			pow(res->obj[res->n].rad, 2);
	d = res->b * res->b - res->a * res->c;
	if (d < 0)
		return (0);
	res->newlen = (res->b - sqrtf(d)) / (res->a);
	if (res->len >= res->newlen && res->newlen >= 0.0001)
	{
		res->len = res->newlen;
		return (1);
	}
	return (0);
}

int		intersect_cone(t_fdf *res)
{
	double d;

	normalize(&res->obj[res->n].rot);
	res->dist = vec_sub(res->obj[res->n].pos, res->campos);
	res->a = res->raydir.x * res->raydir.x - res->raydir.y
		* res->raydir.y + res->raydir.z * res->raydir.z;
	res->b = res->raydir.x * res->dist.x - res->raydir.y
		* res->dist.y + res->raydir.z * res->dist.z;
	res->c = res->dist.x * res->dist.x + res->dist.z
		* res->dist.z - res->dist.y * res->dist.y;
	d = res->b * res->b - res->a * res->c;
	if (d < 0)
		return (0);
	res->newlen = (res->b - sqrtf(d)) / res->a;
	if (res->len >= res->newlen && res->newlen >= 0.0001)
	{
		res->len = res->newlen;
		return (1);
	}
	return (0);
}

int		intersect_plane(t_fdf *res)
{
	res->newlen = -((dot(res->obj[res->n].rot, res->campos) -
		dot(res->obj[res->n].rot, res->obj[res->n].pos))
	/ dot(res->obj[res->n].rot, res->raydir));
	if (res->newlen < 0.0001)
		return (0);
	if (res->len >= res->newlen)
	{
		res->len = res->newlen;
		return (1);
	}
	return (0);
}
