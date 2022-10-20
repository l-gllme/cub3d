/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayPix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:34:53 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 16:49:51 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_row(t_g *g, t_data *img, double y, double height)
{
	double	j;
	double	ciel;
	double	floor1;

	g->actuheight = height;
	ciel = (W_H / 2) - (height / 2);
	floor1 = (W_H / 2) + (height / 2);
	j = -1;
	while (++j < W_H)
	{
		if (j < ciel)
			pp(img, y, j, g->cielcolor);
		else if (j > floor1)
			pp(img, y, j, g->solcolor);
		else
			displaypix(g, y, j, ciel);
	}
}

void	drawrow1(t_g *g, t_data *img, double i, double d)
{
	double	walldist;
	double	height;
	double	fix;
	double	pi;

	pi = 2 * PI;
	height = 0.0;
	while (i < W_W)
	{
		d = (double)((g->fovp / (W_W - 1) * i)
				+ (double)((double)g->angle - (double)g->fovd2));
		if (d < 0)
			d += 360 * PI / 180;
		fix = g->angle - d;
		if (fix < 0)
			fix += pi;
		else if (fix > pi)
			fix -= pi;
		g->rayangle = d;
		walldist = ray_calculator(g, d, g->c.x, g->c.y) * cos(fix);
		height = 55000 / walldist;
		draw_row(g, img, i, height);
		i++;
	}
}
