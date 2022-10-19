/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayPix_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:39:24 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:35:19 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	displaypix_3(t_g *g, double y, double j, double ciel)
{
	double	height;
	double	t;

	height = g->ActuHeight;
	t = (j - ciel) * (SIZEF / height);
	if (g->button == 1 && g->dir == 1 && g->activateButton)
		pp(&g->img, y, j, gp((int)fmod(g->dirY, SIZEF), t, g->bc));
	else if (g->button == 1 && g->dir == 2 && g->activateButton)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirY, SIZEF), t, g->bc));
	else if (g->w_2check == 1 && g->dir == 4)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirX, SIZEF), t, g->w_2));
	else if (g->dir == 2 && g->exitcheck)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirY, SIZEF), t, g->exit));
	else if (g->dir == 3 && g->exitcheck)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirX, SIZEF), t, g->exit));
	else if (g->dir == 4 && g->exitcheck)
		pp(&g->img, y, j, gp((int)fmod(g->dirX, SIZEF), t, g->exit));
	else if (g->dir == 2)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirY, SIZEF), t, g->ouest));
	else if (g->dir == 3)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirX, SIZEF), t, g->sud));
	else if (g->dir == 1)
		pp(&g->img, y, j, gp((int)fmod(g->dirY, SIZEF), t, g->est));
	else if (g->dir == 4)
		pp(&g->img, y, j, gp((int)fmod(g->dirX, SIZEF), t, g->nord));
}

void	displaypix_2(t_g *g, double y, double j, double ciel)
{
	double	height;
	double	t;

	height = g->ActuHeight;
	t = (j - ciel) * (SIZEF / height);
	if (g->button == 1 && g->dir == 3 && g->activateButton)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirX, SIZEF), t, g->bc));
	else if (g->button == 1 && g->dir == 4 && g->activateButton)
		pp(&g->img, y, j, gp((int)fmod(g->dirX, SIZEF), t, g->bc));
	else if (g->w_1check == 1 && g->dir == 1)
		pp(&g->img, y, j, gp((int)fmod(g->dirY, SIZEF), t, g->w_1));
	else if (g->w_1check == 1 && g->dir == 2)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirY, SIZEF), t, g->w_1));
	else if (g->w_1check == 1 && g->dir == 3)
		pp(&g->img, y, j, gp((int)fmod(g->dirX, SIZEF), t, g->w_1));
	else if (g->w_1check == 1 && g->dir == 4)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirX, SIZEF), t, g->w_1));
	else if (g->w_2check == 1 && g->dir == 1)
		pp(&g->img, y, j, gp((int)fmod(g->dirY, SIZEF), t, g->w_2));
	else if (g->w_2check == 1 && g->dir == 2)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirY, SIZEF), t, g->w_2));
	else if (g->w_2check == 1 && g->dir == 3)
		pp(&g->img, y, j, gp((int)fmod(g->dirX, SIZEF), t, g->w_2));
	else
		displaypix_3(g, y, j, ciel);
}

void	displaypix(t_g *g, double y, double j, double ciel)
{
	double	height;
	double	t;

	height = g->ActuHeight;
	t = (j - ciel) * (SIZEF / height);
	if (g->door == 1 && !g->activateButton && g->dir == 3)
		pp(&g->img, y, j, gp((int)fmod(g->dirX, SIZEF), t, g->d));
	else if (g->door == 1 && !g->activateButton && g->dir == 4)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirX, SIZEF), t, g->d));
	else if (g->door == 1 && !g->activateButton && g->dir == 1)
		pp(&g->img, y, j, gp((int)fmod(g->dirY, SIZEF), t, g->d));
	else if (g->door == 1 && !g->activateButton && g->dir == 2)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirY, SIZEF), t, g->d));
	else if (g->button == 1 && g->dir == 1 && !g->activateButton)
		pp(&g->img, y, j, gp((int)fmod(g->dirY, SIZEF), t, g->b));
	else if (g->button == 1 && g->dir == 2 && !g->activateButton)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirY, SIZEF), t, g->b));
	else if (g->button == 1 && g->dir == 3 && !g->activateButton)
		pp(&g->img, y, j, gp(SIZE - (int)fmod(g->dirX, SIZEF), t, g->b));
	else if (g->button == 1 && g->dir == 4 && !g->activateButton)
		pp(&g->img, y, j, gp((int)fmod(g->dirX, SIZEF), t, g->b));
	else if (g->dir == 1 && g->exitcheck)
		pp(&g->img, y, j, gp((int)fmod(g->dirY, SIZEF), t, g->exit));
	else
		displaypix_2(g, y, j, ciel);
}
