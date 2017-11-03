/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:43:53 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 15:43:54 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_scene_3(t_fdf *res)
{
	res->obj[1].type = 'K';
	res->obj[1].pos.x = 170;
	res->obj[1].pos.y = 60;
	res->obj[1].pos.z = -250;
	res->obj[1].col.r = 0.0;
	res->obj[1].col.g = 0.0;
	res->obj[1].col.b = 255.0;
	res->obj[1].rot.x = 0.0;
	res->obj[1].rot.y = 1.0;
	res->obj[1].rot.z = 0.0;
	res->obj[1].rad = 10;
	res->lgt[0].x = 600.0;
	res->lgt[0].y = 200.0;
	res->lgt[0].z = -900.0;
	res->lgt[1].x = -300.0;
	res->lgt[1].y = 200.0;
	res->lgt[1].z = -900.0;
	res->lgt[2].x = -100.0;
	res->lgt[2].y = 280.0;
	res->lgt[2].z = -800.0;
	set_scene_3_p2(res);
}

void	set_scene_3_p2(t_fdf *res)
{
	res->obj[2].type = 'P';
	res->obj[2].pos.x = 0;
	res->obj[2].pos.y = 280;
	res->obj[2].pos.z = 0;
	res->obj[2].col.r = 120.0;
	res->obj[2].col.g = 120.0;
	res->obj[2].col.b = 120.0;
	res->obj[2].rot.x = 0.0;
	res->obj[2].rot.y = 1.0;
	res->obj[2].rot.z = 0.0;
	res->obj[3].type = 'P';
	res->obj[3].pos.x = 0;
	res->obj[3].pos.y = -150;
	res->obj[3].pos.z = 0;
	res->obj[3].col.r = 120.0;
	res->obj[3].col.g = 120.0;
	res->obj[3].col.b = 120.0;
	res->obj[3].rot.y = 1.0;
	set_scene_3_p3(res);
}

void	set_scene_3_p3(t_fdf *res)
{
	res->obj[4].type = 'P';
	res->obj[4].pos.x = 0;
	res->obj[4].pos.y = 0;
	res->obj[4].pos.z = 300;
	res->obj[4].col.r = 60.0;
	res->obj[4].col.g = 0.0;
	res->obj[4].col.b = 120.0;
	res->obj[4].rot.x = 0.0;
	res->obj[4].rot.z = 1.0;
	res->obj[4].rot.y = 0.0;
	set_scene_3_p4(res);
}

void	set_scene_3_p4(t_fdf *res)
{
	res->obj[5].type = 'S';
	res->obj[5].pos.x = -110;
	res->obj[5].pos.y = -30;
	res->obj[5].pos.z = 180;
	res->obj[5].col.r = 0.0;
	res->obj[5].col.g = 180.0;
	res->obj[5].col.b = 0.0;
	res->obj[5].rad = 70;
	res->obj[6].type = 'S';
	res->obj[6].pos.x = 465;
	res->obj[6].pos.y = -30;
	res->obj[6].pos.z = 180;
	res->obj[6].col.r = 120.0;
	res->obj[6].col.g = 0.0;
	res->obj[6].col.b = 120.0;
	res->obj[6].rad = 70;
}
