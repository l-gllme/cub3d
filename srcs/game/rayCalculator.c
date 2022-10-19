/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCalculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:58:29 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 13:18:32 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	restoreStruct(t_g *g, double angle, double x, double y)
{
	g->door = 0;
	g->button = 0;
	g->w_1check = 0;
	g->w_2check = 0;
	g->exitcheck = 0;
	g->cosA = cos(angle);
	g->sinA = sin(angle);
	g->tmpX = x;
	g->tmpY = y;

}



double	RayCalculator(t_g *g, double angle, double x, double y)
{
	double	d;

	restoreStruct(g, angle, x, y);
	g->xOld = g->tmpX;
	g->yOld = g->tmpY;
	d = 0;
	while (1)
	{
		g->xOld = g->tmpX;
		g->yOld = g->tmpY;
		g->tmpY -= g->cosA;
		g->tmpX += g->sinA;
		d += 1;
		if ((int)g->tmpX / SIZE != (int)g->xOld / SIZE && (int)g->tmpY / SIZE != (int)g->yOld / SIZE)
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
		if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == '1')
			break;
		if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'M')
			break;
		if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'P' && !g->activateButton)
		{
			g->door = 1;
			break;
		}
		if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'B')
		{
			g->button = 1;
			break;
		}
		if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'H')
		{
			g->w_1check = 1;
			break;
		}
		if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'G')
		{
			g->w_2check = 1;
			break;
		}
		if (g->m.map[(int)g->tmpY / SIZE][(int)g->tmpX / SIZE] == 'X')
		{
			g->exitcheck = 1;
			break;
		}
	}
	int i = 0;
	double	newX;
	double	newY;
	while (i < 10)
	{
		newX = (g->tmpX + g->xOld) / 2;
		newY = (g->tmpY + g->yOld) / 2;
		if (g->m.map[(int)newY / SIZE][(int)newX / SIZE] == '1' || (g->m.map[(int)newY / SIZE][(int)newX / SIZE] == 'P' && !g->activateButton) || g->m.map[(int)newY / SIZE][(int)newX / SIZE] == 'B' || g->m.map[(int)newY / SIZE][(int)newX / SIZE] == 'M')
		{
			g->tmpX = newX;
			g->tmpY = newY;
		}
		else
		{
			g->yOld = newY;
			g->xOld = newX;
		}
		i++;
	}
	d = sqrt(pow((g->tmpX - g->c.x), 2) + pow((g->tmpY - g->c.y), 2));
	if (g->button)
		g->DistButton = d;
	g->dirX = g->tmpX;
	g->dirY = g->tmpY;
	double Xtest = fmod(g->tmpX, SIZEF);
	double Ytest = fmod(g->tmpY, SIZEF);
	if (Xtest <= SIZE / 2)
	{
		if (Ytest <= SIZE / 2)
		{
			if (Xtest < Ytest)
				g->dir = 1;
			else
				g->dir = 3;
		}
		else
		{
			if (Xtest < SIZE - Ytest)
				g->dir = 1;
			else
				g->dir = 4;
		}
	}
	else
	{
		if (Ytest <= SIZE / 2)
		{
			if (SIZE - Xtest < Ytest)
				g->dir = 2;
			else
				g->dir = 3;
		}
		else
		{
			if (Xtest > Ytest)
				g->dir = 2;
			else
				g->dir = 4;
		}
	}
	return (d);
}
