/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:42:45 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 15:42:48 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		click_x(void *click)
{
	click = NULL;
	exit(1);
	return (0);
}

void	cam_move(int key, t_fdf *res)
{
	if (key == 123)
	{
		res->y += 0.15;
		ray_init(res);
	}
	if (key == 124)
	{
		res->y -= 0.15;
		ray_init(res);
	}
	if (key == 125)
	{
		res->x += 0.15;
		ray_init(res);
	}
	if (key == 126)
	{
		res->x -= 0.15;
		ray_init(res);
	}
}

void	scene_changer(int key, t_fdf *res)
{
	if (key == 18)
	{
		res->scene = 1;
		ray_init(res);
	}
	if (key == 19)
	{
		res->scene = 2;
		ray_init(res);
	}
	if (key == 20)
	{
		res->scene = 3;
		ray_init(res);
	}
	if (key == 21)
	{
		res->scene = 4;
		ray_init(res);
	}
	if (key == 23)
	{
		res->scene = 5;
		ray_init(res);
	}
}

void	brightness(int key, t_fdf *res)
{
	if (key == 12)
	{
		res->bright -= 0.1;
		ray_init(res);
	}
	if (key == 14)
	{
		res->bright += 0.1;
		ray_init(res);
	}
	if (key == 13)
	{
		res->sh_effect += 2;
		ray_init(res);
	}
	if (key == 1)
	{
		res->sh_effect -= 2;
		ray_init(res);
	}
}

int		hook_operators(int key, t_fdf *res)
{
	if (key == 53)
		exit(0);
	if (key == 24)
	{
		res->z += 20;
		ray_init(res);
	}
	if (key == 27)
	{
		res->z -= 20;
		ray_init(res);
	}
	if (key >= 123 && key <= 126)
		cam_move(key, res);
	if (key == 12 || key == 14 || key == 13 || key == 1)
		brightness(key, res);
	if (key == 48)
		toggle_glare(res);
	if ((key >= 18 && key <= 21) || key == 23)
		scene_changer(key, res);
	return (0);
}
