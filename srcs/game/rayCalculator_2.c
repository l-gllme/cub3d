/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCalculator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:15:38 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 15:08:50 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ray_calculator_while_3(t_g *g)
{
	if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'G')
	{
		g->w_2check = 1;
		return (0);
	}
	if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'X')
	{
		g->exitcheck = 1;
		return (0);
	}
	return (1);
}

int	ray_calculator_while_2(t_g *g)
{
	if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == '1')
		return (0);
	if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'M')
		return (0);
	if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'P'
		&& !g->activateButton)
	{
		g->door = 1;
		return (0);
	}
	if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'B')
	{
		g->button = 1;
		return (0);
	}
	if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'H')
	{
		g->w_1check = 1;
		return (0);
	}
	if (!ray_calculator_while_3(g))
		return (0);
	return (1);
}

double	ray_calculator_while(t_g *g, double angle, double d)
{
	while (1)
	{
		g->xOld = g->tmpX;
		g->yOld = g->tmpY;
		g->tmpY -= g->cosA;
		g->tmpX += g->sinA;
		d += 1;
		if ((int)g->tmpX / SIZE != (int)g->xOld / SIZE
			&& (int)g->tmpY / SIZE != (int)g->yOld / SIZE)
		{
			if (angle >= 45 * PI / 180 && angle < 135 * PI / 180)
				g->tmpX = g->xOld;
			else if (angle >= 135 * PI / 180 && angle < 225 * PI * 180)
				g->tmpY = g->yOld;
			else if (angle >= 225 * PI / 180 && angle < 315 * PI / 180)
				g->tmpX = g->xOld;
			else if (angle >= 315 * PI / 180 && angle < 360 * PI / 180)
				g->tmpY = g->yOld;
			else if (angle >= 0 * PI / 180 && angle < 45 * PI / 180)
				g->tmpY = g->yOld;
		}
		if (!ray_calculator_while_2(g))
			break ;
	}
	return (d);
}
