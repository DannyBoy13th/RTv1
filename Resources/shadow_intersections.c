/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_intersections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:42:35 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 17:46:28 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		shadow_object(t_fdf *res, int i)
{
	if (res->obj[i].type == 'S')
		res->occl = intersect_shadow_sphere(res, i);
	if (res->obj[i].type == 'C')
		res->occl = intersect_shadow_cylinder(res, i);
	if (res->obj[i].type == 'K')
		res->occl = intersect_shadow_cone(res, i);
	if (res->obj[i].type == 'P')
		res->occl = intersect_shadow_plane(res, i);
}

int			intersect_shadow_sphere(t_fdf *res, int i)
{
	double d;

	res->dist = vec_sub(res->obj[i].pos, res->hpoint);
	res->a = dot(res->lgtdir[res->i], res->lgtdir[res->i]);
	res->b = dot(res->lgtdir[res->i], res->dist);
	res->c = dot(res->dist, res->dist) - (res->obj[i].rad * res->obj[i].rad);
	d = res->b * res->b - res->a * res->c;
	res->nshlen = (res->b - sqrtf(d)) / res->a;
	if (res->shlen >= res->nshlen && res->nshlen >= 0.0001)
	{
		res->shlen = res->nshlen;
		return (1);
	}
	return (0);
}

int			intersect_shadow_cylinder(t_fdf *res, int i)
{
	double d;

	res->dist = vec_sub(res->obj[i].pos, res->hpoint);
	normalize(&res->obj[i].rot);
	res->a = dot(res->lgtdir[res->i], res->lgtdir[res->i]) -
		pow(dot(res->lgtdir[res->i], res->obj[i].rot), 2);
	res->b = (dot(res->lgtdir[res->i], res->dist) -
		(dot(res->lgtdir[res->i], res->obj[i].rot) *
			dot(res->dist, res->obj[i].rot)));
	res->c = dot(res->dist, res->dist) -
		pow(dot(res->dist, res->obj[i].rot), 2) -
			pow(res->obj[i].rad, 2);
	d = res->b * res->b - res->a * res->c;
	res->nshlen = (res->b - sqrtf(d)) / res->a;
	if (res->shlen >= res->nshlen && res->nshlen >= 0.0001)
	{
		res->shlen = res->nshlen;
		return (1);
	}
	return (0);
}

int			intersect_shadow_cone(t_fdf *res, int i)
{
	double d;

	normalize(&res->obj[i].rot);
	res->dist = vec_sub(res->obj[i].pos, res->hpoint);
	res->a = res->lgtdir[res->i].x * res->lgtdir[res->i].x -
		res->lgtdir[res->i].y * res->lgtdir[res->i].y +
			res->lgtdir[res->i].z * res->lgtdir[res->i].z;
	res->b = res->lgtdir[res->i].x * res->dist.x -
		res->lgtdir[res->i].y * res->dist.y +
			res->lgtdir[res->i].z * res->dist.z;
	res->c = res->dist.x * res->dist.x +
		res->dist.z * res->dist.z - res->dist.y * res->dist.y;
	d = res->b * res->b - res->a * res->c;
	res->nshlen = (res->b - sqrtf(d)) / res->a;
	if (res->shlen >= res->nshlen && res->nshlen >= 0.0001)
	{
		res->shlen = res->nshlen;
		return (1);
	}
	return (0);
}

int			intersect_shadow_plane(t_fdf *res, int i)
{
	res->nshlen = ((dot(res->obj[i].pos, res->hpoint) -
		dot(res->obj[i].pos, res->obj[i].pos)) /
			dot(res->obj[i].rot, res->lgtdir[res->i]));
	if (res->nshlen < 0.0001)
		return (0);
	if (res->shlen >= res->nshlen && res->nshlen < 0.0)
	{
		res->shlen = res->nshlen;
		return (1);
	}
	return (0);
}
