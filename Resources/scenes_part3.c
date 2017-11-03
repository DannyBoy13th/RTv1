/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_part3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:44:01 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 15:44:02 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_scene_5(t_fdf *res)
{
	res->obj[1].type = 'C';
	res->obj[1].pos.x = 365;
	res->obj[1].pos.y = 60;
	res->obj[1].pos.z = -200;
	res->obj[1].rad = 45;
	res->obj[1].col.r = 255.0;
	res->obj[1].col.g = 0.0;
	res->obj[1].col.b = 0.0;
	res->obj[1].rot.x = 0.0;
	res->obj[1].rot.y = 1.0;
	res->obj[1].rot.z = 0.0;
	res->obj[2].type = 'S';
	res->obj[2].pos.x = 200;
	res->obj[2].pos.y = 60;
	res->obj[2].pos.z = -150;
	res->obj[2].rad = 45;
	res->obj[2].col.r = 255.0;
	res->obj[2].col.g = 255.0;
	res->obj[2].col.b = 0.0;
	set_scene_5_p2(res);
}

void	set_scene_5_p2(t_fdf *res)
{
	res->obj[3].type = 'C';
	res->obj[3].pos.x = 30;
	res->obj[3].pos.y = 60;
	res->obj[3].pos.z = -200;
	res->obj[3].rad = 45.0;
	res->obj[3].col.r = 0.0;
	res->obj[3].col.g = 255.0;
	res->obj[3].col.b = 0.0;
	res->obj[3].rot.x = 0.0;
	res->obj[3].rot.y = 1.0;
	res->obj[3].rot.z = 0.0;
	res->obj[4].type = 'K';
	res->obj[4].pos.x = 200;
	res->obj[4].pos.y = 60;
	res->obj[4].pos.z = -150;
	res->obj[4].rad = 10;
	res->obj[4].col.r = 0.0;
	res->obj[4].col.g = 0.0;
	res->obj[4].col.b = 255.0;
	res->obj[4].rot.x = 0.0;
	res->obj[4].rot.y = 1.0;
	res->obj[4].rot.z = 0.0;
	set_scene_5_p3(res);
}

void	set_scene_5_p3(t_fdf *res)
{
	res->obj[5].type = 'P';
	res->obj[5].pos.x = 0;
	res->obj[5].pos.y = 280;
	res->obj[5].pos.z = 0;
	res->obj[5].col.r = 100.0;
	res->obj[5].col.g = 100.0;
	res->obj[5].col.b = 100.0;
	res->obj[5].rot.x = 0.0;
	res->obj[5].rot.y = 1.0;
	res->obj[5].rot.z = 0.0;
	res->obj[6].type = 'P';
	res->obj[6].pos.x = 0;
	res->obj[6].pos.y = -150;
	res->obj[6].pos.z = 0;
	res->obj[6].col.r = 100.0;
	res->obj[6].col.g = 100.0;
	res->obj[6].col.b = 100.0;
	res->obj[6].rot.x = 0.0;
	res->obj[6].rot.y = 1.0;
	res->obj[6].rot.z = 0.0;
	set_scene_5_p4(res);
}

void	set_scene_5_p4(t_fdf *res)
{
	res->obj[7].type = 'P';
	res->obj[7].pos.x = 0;
	res->obj[7].pos.y = 0;
	res->obj[7].pos.z = 1000;
	res->obj[7].col.r = 75.0;
	res->obj[7].col.g = 75.0;
	res->obj[7].col.b = 75.0;
	res->obj[7].rot.x = 0.0;
	res->obj[7].rot.y = 0.0;
	res->obj[7].rot.z = 1.0;
	res->lgt[0].x = 600.0;
	res->lgt[0].y = 100.0;
	res->lgt[0].z = -900.0;
	res->lgt[1].x = -450.0;
	res->lgt[1].y = 100.0;
	res->lgt[1].z = -900.0;
	res->lgt[2].x = -100.0;
	res->lgt[2].y = 100.0;
	res->lgt[2].z = -500.0;
	res->lgt[3].x = -200.0;
	res->lgt[3].y = 100.0;
	res->lgt[3].z = -500.0;
}
