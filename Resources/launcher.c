/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:45:03 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/10/29 17:43:45 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		toggle_glare(t_fdf *res)
{
	if (res->glare == 1)
	{
		res->glare = 0;
		ray_init(res);
		return (0);
	}
	if (res->glare == 0)
	{
		res->glare = 1;
		ray_init(res);
		return (0);
	}
	return (0);
}

void	shine_effect(t_fdf *res)
{
	t_vector	lgtdir;
	t_vector	vwdir;
	t_vector	result;

	lgtdir = vec_sub(res->lgt[res->i], res->hpoint);
	normalize(&lgtdir);
	vwdir = vec_sub(res->campos, res->hpoint);
	normalize(&vwdir);
	result = vec_add(lgtdir, vwdir);
	normalize(&result);
	res->spec = pow(dot(res->normal, result), res->sh_effect);
}

void	mlx_launcher(t_fdf *res)
{
	res->x = 0.0;
	res->y = 0.0;
	res->z = 0.0;
	res->sh_effect = 52;
	res->glare = 1;
	res->color[1].r = 1;
	res->color[1].g = 1;
	res->color[1].b = 1;
	res->color[4].r = 255;
	res->color[4].g = 255;
	res->color[4].b = 255;
	res->bright = 0.7;
	res->mlx = mlx_init();
	res->win = mlx_new_window(res->mlx, RESO_X, RESO_Y, "RTv1");
	res->t.img = mlx_new_image(res->mlx, RESO_X, RESO_Y);
	res->t.addr = mlx_get_data_addr(res->t.img,
			&res->t.bpp, &res->t.sl, &res->t.endl);
	mlx_hook(res->win, 2, 1L << 0, &hook_operators, res);
	mlx_hook(res->win, 17, 1L << 17, &click_x, res);
	ray_init(res);
}

int		main(int argc, char **argv)
{
	static	t_fdf res;

	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments.");
		exit(0);
	}
	res.scene = ft_atoi(argv[1]);
	if (res.scene > 5 || res.scene < 1)
	{
		ft_putstr("Wrong argument.");
		exit(0);
	}
	set_number(&res);
	mlx_launcher(&res);
	mlx_loop(res.mlx);
	return (0);
}
