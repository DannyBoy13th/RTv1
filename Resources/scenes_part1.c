/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:43:43 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 15:43:46 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_cam(t_fdf *res)
{
	clear_screen(res);
	res->campos.x = 75.0;
	res->campos.y = 0.0;
	res->campos.z = -1000.0 + res->z;
	res->camdir.x = 0.5 + res->y;
	res->camdir.y = 0.3 + res->x;
	res->camdir.z = 2.0;
	res->center = vec_add(res->campos, res->camdir);
	res->p0.x = res->center.x + (-2);
	res->p0.y = res->center.y + (2);
	res->p0.z = res->center.z + (1);
	res->p1.x = res->center.x + (2);
	res->p1.y = res->center.y + (2);
	res->p1.z = res->center.z + (1);
	res->p2.x = res->center.x + (-2);
	res->p2.y = res->center.y + (-2);
	res->p2.z = res->center.z + (1);
}

void	set_scene_1(t_fdf *res)
{
	res->obj[1].type = 'S';
	res->obj[1].pos.x = 160;
	res->obj[1].pos.y = 60;
	res->obj[1].pos.z = -400;
	res->obj[1].rad = 120;
	res->obj[1].col.r = 255.0;
	res->obj[1].col.g = 0.0;
	res->obj[1].col.b = 0.0;
	res->lgt[0].x = 300.0;
	res->lgt[0].y = 100.0;
	res->lgt[0].z = -800.0;
}

void	set_scene_2(t_fdf *res)
{
	res->obj[1].type = 'C';
	res->obj[1].pos.x = 180;
	res->obj[1].pos.y = 60;
	res->obj[1].pos.z = -400;
	res->obj[1].rad = 70;
	res->obj[1].col.r = 255.0;
	res->obj[1].col.g = 85.0;
	res->obj[1].col.b = 100.0;
	res->obj[1].rot.x = 0;
	res->obj[1].rot.y = 1;
	res->obj[1].rot.z = 0.0;
	res->lgt[0].x = 400.0;
	res->lgt[0].y = 400.0;
	res->lgt[0].z = -900.0;
	res->lgt[1].x = -200.0;
	res->lgt[1].y = -200.0;
	res->lgt[1].z = -900.0;
}
