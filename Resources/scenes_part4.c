/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_part4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:52:35 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/29 17:52:40 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_scene_4(t_fdf *res)
{
	res->obj[1].type = 'S';
	res->obj[1].pos.x = 290;
	res->obj[1].pos.y = 160;
	res->obj[1].pos.z = 200;
	res->obj[1].rad = 125;
	res->obj[1].col.r = 0.0;
	res->obj[1].col.g = 0.0;
	res->obj[1].col.b = 255.0;
	res->obj[2].type = 'S';
	res->obj[2].pos.x = -100;
	res->obj[2].pos.y = 165;
	res->obj[2].pos.z = 200;
	res->obj[2].col.r = 0.0;
	res->obj[2].col.g = 255.0;
	res->obj[2].col.b = 0.0;
	res->obj[2].rad = 175;
	set_scene_4_p2(res);
}

void	set_scene_4_p2(t_fdf *res)
{
	res->obj[3].type = 'S';
	res->obj[3].pos.x = 290;
	res->obj[3].pos.y = -50;
	res->obj[3].pos.z = -200;
	res->obj[3].col.r = 120.0;
	res->obj[3].col.g = 0.0;
	res->obj[3].col.b = 120.0;
	res->obj[3].rad = 95;
	res->obj[4].type = 'P';
	res->obj[4].pos.x = 0;
	res->obj[4].pos.y = -250;
	res->obj[4].pos.z = 0;
	res->obj[4].col.r = 180.0;
	res->obj[4].col.g = 140.0;
	res->obj[4].col.b = 160.0;
	res->obj[4].rot.y = 1.0;
	res->obj[4].rot.x = 0.0;
	res->obj[4].rot.z = 0.0;
	set_scene_4_p3(res);
}

void	set_scene_4_p3(t_fdf *res)
{
	res->obj[5].type = 'P';
	res->obj[5].pos.x = 0;
	res->obj[5].pos.y = 0;
	res->obj[5].pos.z = 1000;
	res->obj[5].col.r = 100.0;
	res->obj[5].col.g = 100.0;
	res->obj[5].col.b = 150.0;
	res->obj[5].rot.z = 1.0;
	res->lgt[1].x = 200.0;
	res->lgt[1].y = -180.0;
	res->lgt[1].z = -700.0;
	set_scene_4_p4(res);
}

void	set_scene_4_p4(t_fdf *res)
{
	res->obj[6].type = 'C';
	res->obj[6].pos.x = 160;
	res->obj[6].pos.y = 160;
	res->obj[6].pos.z = 200;
	res->obj[6].rad = 70;
	res->obj[6].col.r = 255.0;
	res->obj[6].col.g = 110.0;
	res->obj[6].col.b = 75.0;
	res->obj[6].rot.x = 1.0;
	res->obj[6].rot.y = 0.0;
	res->obj[6].rot.z = 0.0;
	res->lgt[0].x = -100.0;
	res->lgt[0].y = 600.0;
	res->lgt[0].z = -700.0;
}
