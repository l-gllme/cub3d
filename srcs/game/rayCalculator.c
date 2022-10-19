/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCalculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:58:29 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 15:09:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	restore_struct(t_g *g, double angle, double x, double y)
{
	g->door = 0;
	g->button = 0;
	g->w_1check = 0;
	g->w_2check = 0;
	g->exitcheck = 0;
	g->key_E = 0;
	g->cosA = cos(angle);
	g->sinA = sin(angle);
	g->tmpX = g->c.x;
	g->tmpY = g->c.y;
	(void)x;
	(void)y;
}

void	ray_dichotomie(t_g *g, int i)
{
	double	newx;
	double	newy;

	while (i < 10)
	{
		newx = (g->tmpX + g->xOld) / 2;
		newy = (g->tmpY + g->yOld) / 2;
		if (g->m.map[(int)newy / SIZE][(int)newx / SIZE] == '1'
			|| (g->m.map[(int)newy / SIZE][(int)newx / SIZE] == 'P'
			&& !g->activateButton)
			|| g->m.map[(int)newy / SIZE][(int)newx / SIZE] == 'B'
			|| g->m.map[(int)newy / SIZE][(int)newx / SIZE] == 'M')
		{
			g->tmpX = newx;
			g->tmpY = newy;
		}
		else
		{
			g->yOld = newy;
			g->xOld = newx;
		}
		i++;
	}
}

void	found_wall(t_g *g, double xtest, double ytest)
{
	if (ytest <= SIZE / 2)
	{
		if (xtest < ytest)
			g->dir = 1;
		else
			g->dir = 3;
	}
	else
	{
		if (xtest < SIZE - ytest)
			g->dir = 1;
		else
			g->dir = 4;
	}
}

void	found_wall_2(t_g *g, double xtest, double ytest)
{
	if (ytest <= SIZE / 2)
	{
		if (SIZE - xtest < ytest)
			g->dir = 2;
		else
			g->dir = 3;
	}
	else
	{
		if (xtest > ytest)
			g->dir = 2;
		else
			g->dir = 4;
	}
}

double	ray_calculator(t_g *g, double angle, double x, double y)
{
	double	d;
	double	xtest;
	double	ytest;

	restore_struct(g, angle, x, y);
	d = 0;
	d = ray_calculator_while(g, angle, d);
	ray_dichotomie(g, 0);
	d = sqrt(pow((g->tmpX - g->c.x), 2) + pow((g->tmpY - g->c.y), 2));
	if (g->button)
		g->DistButton = d;
	g->dirX = g->tmpX;
	g->dirY = g->tmpY;
	xtest = fmod(g->tmpX, SIZEF);
	ytest = fmod(g->tmpY, SIZEF);
	if (xtest <= SIZE / 2)
		found_wall(g, xtest, ytest);
	else
		found_wall_2(g, xtest, ytest);
	return (d);
}
