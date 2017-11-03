/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_part2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:43:24 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/23 15:43:26 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		col_add(t_color a, t_color b)
{
	t_color res;

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
	return (res);
}

t_color		col_clamp(t_color a)
{
	t_color res;

	res.r = a.r;
	res.g = a.g;
	res.b = a.b;
	if (a.r <= 0.0)
		res.r = 0.0;
	if (a.g <= 0.0)
		res.g = 0.0;
	if (a.b <= 0.0)
		res.b = 0.0;
	if (a.r >= 255.0)
		res.r = 255.0;
	if (a.g >= 255.0)
		res.g = 255.0;
	if (a.b >= 255.0)
		res.b = 255.0;
	return (res);
}

double		dot(t_vector a, t_vector b)
{
	double		res;
	t_vector	temp;

	temp.x = a.x * b.x;
	temp.y = a.y * b.y;
	temp.z = a.z * b.z;
	res = temp.x + temp.y + temp.z;
	return (res);
}

void		clear_screen(t_fdf *res)
{
	int x;
	int y;

	y = 0;
	while (y < RESO_Y)
	{
		x = 0;
		while (x < RESO_X)
		{
			ft_put_pix(y, x, res->color[0], res);
			x++;
		}
		y++;
	}
}

double		mag_calc(t_vector a)
{
	double mag;

	mag = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (mag);
}
