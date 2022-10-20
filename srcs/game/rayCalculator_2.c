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
	if (g->m.map[(int)g->tmpy / SIZE][(int)g->tmpx / SIZE] == 'G')
	{
		g->w_2check = 1;
		return (0);
	}
	if (g->m.map[(int)g->tmpy / SIZE][(int)g->tmpx / SIZE] == 'X')
	{
		g->exitcheck = 1;
		return (0);
	}
	return (1);
}

int	ray_calculator_while_2(t_g *g)
{
	if (g->m.map[(int)g->tmpy / SIZE][(int)g->tmpx / SIZE] == '1')
		return (0);
	if (g->m.map[(int)g->tmpy / SIZE][(int)g->tmpx / SIZE] == 'M')
		return (0);
	if (g->m.map[(int)g->tmpy / SIZE][(int)g->tmpx / SIZE] == 'P'
		&& !g->activatebutton)
	{
		g->door = 1;
		return (0);
	}
	if (g->m.map[(int)g->tmpy / SIZE][(int)g->tmpx / SIZE] == 'B')
	{
		g->button = 1;
		return (0);
	}
	if (g->m.map[(int)g->tmpy / SIZE][(int)g->tmpx / SIZE] == 'H')
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
		g->xold = g->tmpx;
		g->yold = g->tmpy;
		g->tmpy -= g->cosa;
		g->tmpx += g->sina;
		d += 1;
		if ((int)g->tmpx / SIZE != (int)g->xold / SIZE
			&& (int)g->tmpy / SIZE != (int)g->yold / SIZE)
		{
			if (angle >= 45 * PI / 180 && angle < 135 * PI / 180)
				g->tmpx = g->xold;
			else if (angle >= 135 * PI / 180 && angle < 225 * PI * 180)
				g->tmpy = g->yold;
			else if (angle >= 225 * PI / 180 && angle < 315 * PI / 180)
				g->tmpx = g->xold;
			else if (angle >= 315 * PI / 180 && angle < 360 * PI / 180)
				g->tmpy = g->yold;
			else if (angle >= 0 * PI / 180 && angle < 45 * PI / 180)
				g->tmpy = g->yold;
		}
		if (!ray_calculator_while_2(g))
			break ;
	}
	return (d);
}
