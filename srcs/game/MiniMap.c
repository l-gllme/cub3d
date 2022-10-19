/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:36:27 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 16:19:12 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawminisol(t_g *g, int x, int y, int width)
{
	int	to_go;
	int	to_g;
	int	i;
	int	j;

	i = x;
	to_go = x + width;
	to_g = y + width;
	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			pp(&g->img, i, j, 0x8ebbde);
			i++;
		}
		j++;
	}
}

void	drawminiwall(t_g *g, double x, double y, double width)
{
	double	to_go;
	double	to_g;
	double	i;
	double	j;

	i = x;
	to_go = x + width;
	to_g = y + width;
	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			pp(&g->img, i, j, 0x4c5057);
			i++;
		}
		j++;
	}
}

void	drawminibreak(t_g *g, double x, double y, double width)
{
	double	to_go;
	double	to_g;
	double	i;
	double	j;

	i = x;
	to_go = x + width;
	to_g = y + width;
	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			pp(&g->img, i, j, 0x61063);
			i++;
		}
		j++;
	}
}

void	drawminiporte(t_g *g, double x, double y, double width)
{
	double	to_go;
	double	to_g;
	double	i;
	double	j;

	i = x;
	to_go = x + width;
	to_g = y + width;
	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			pp(&g->img, i, j, 0x610000);
			i++;
		}
		j++;
	}
}

void	drawminibutton(t_g *g, double x, double y, double width)
{
	double	to_go;
	double	to_g;
	double	i;
	double	j;

	i = x;
	to_go = x + width;
	to_g = y + width;
	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			pp(&g->img, i, j, 0x045213);
			i++;
		}
		j++;
	}
}

void	drawminiplayer(t_g *g, double x, double y, double width)
{
	double	i;
	double	j;
	double	to_go;
	double	to_g;

	to_go = x + width;
	to_g = y + width;
	i = y;
	while (i < to_g)
	{
		j = x;
		while (j < to_go)
		{
			pp(&g->img, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

int	tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	draw_minimap_2(t_g *g, int i, int j, int len)
{
	if (g->m.map[i][j] == 'P' && !g->activateButton)
		drawminiporte(g, x, y, len, len);
	else if (g->m.map[i][j] == 'H')
		drawminibreak(g, x, y, len, len);
	else if (g->m.map[i][j] == 'B')
		drawminibutton(g, x, y, len, len);
	else if (g->m.map[i][j] == '0' || g->m.map[i][j] == 'N'
		|| g->m.map[i][j] == 'S'
		|| g->m.map[i][j] == 'E' || g->m.map[i][j] == 'W'
		|| (g->m.map[i][j] == 'P' && g->activateButton)
		|| g->m.map[i][j] == 'X')
		drawminisol(g, x, y, len, len);
}

void	draw_minimap(t_g *g, double y, double x)
{
	int	i;
	int	j;
	int	len;

	len = tablen(g->m.map) - 1;
	if (len > 15)
		return ;
	i = -1;
	while (g->m.map[++i + 1])
	{
		j = -1;
		x = 0;
		while (g->m.map[i][++j])
		{
			if (j == (int)g->c.x / SIZE && i == (int)g->c.y / SIZE)
				drawMiniPlayer(g, (int)y, (int)x, len, len);
			else if (g->m.map[i][j] == '1')
				drawMiniWall(g, x, y, len, len);
			draw_minimap_2(g, i, j, len);
			x += len;
		}
		y += len;
	}
}
