/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:41:58 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 15:42:00 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_put_pix(int y, int x, t_color color, t_fdf *res)
{
	if (y >= RESO_Y || x >= RESO_X || y <= 0 || x <= 0)
		return ;
	res->t.addr[y * res->t.sl + x * 4 + 2] = color.r;
	res->t.addr[y * res->t.sl + x * 4 + 1] = color.g;
	res->t.addr[y * res->t.sl + x * 4] = color.b;
}

void		set_number(t_fdf *res)
{
	if (res->scene == 1)
	{
		res->num_obj = 1;
		res->num_lights = 1;
	}
	if (res->scene == 2)
	{
		res->num_obj = 1;
		res->num_lights = 2;
	}
	if (res->scene == 3)
	{
		res->num_obj = 6;
		res->num_lights = 2;
	}
	if (res->scene == 4)
	{
		res->num_obj = 6;
		res->num_lights = 2;
	}
	if (res->scene == 5)
	{
		res->num_obj = 7;
		res->num_lights = 2;
	}
}

void		scene_selector(t_fdf *res)
{
	if (res->scene == 1)
		set_scene_1(res);
	if (res->scene == 2)
		set_scene_2(res);
	if (res->scene == 3)
		set_scene_3(res);
	if (res->scene == 4)
		set_scene_4(res);
	if (res->scene == 5)
		set_scene_5(res);
}

t_vector	create_vector(double x, double y, double z)
{
	t_vector res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

void		normalize(t_vector *a)
{
	double mag;

	mag = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
	a->x /= mag;
	a->y /= mag;
	a->z /= mag;
}
