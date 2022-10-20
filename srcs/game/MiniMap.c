/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:36:27 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:00:19 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	double	x;
	double	y;

	x = g->xmap;
	y = g->ymap;
	if (g->m.map[i][j] == 'P' && !g->activatebutton)
		drawminiporte(g, x, y, len);
	else if (g->m.map[i][j] == 'H')
		drawminibreak(g, x, y, len);
	else if (g->m.map[i][j] == 'B')
		drawminibutton(g, x, y, len);
	else if (g->m.map[i][j] == '0' || g->m.map[i][j] == 'N'
		|| g->m.map[i][j] == 'S'
		|| g->m.map[i][j] == 'E' || g->m.map[i][j] == 'W'
		|| (g->m.map[i][j] == 'P' && g->activatebutton)
		|| g->m.map[i][j] == 'X')
		drawminisol(g, x, y, len);
}

void	draw_minimap(t_g *g)
{
	int	i;
	int	j;
	int	len;

	g->ymap = 0;
	len = tablen(g->m.map) - 1;
	if (len > 15)
		return ;
	i = -1;
	while (g->m.map[++i + 1])
	{
		j = -1;
		g->xmap = 0;
		while (g->m.map[i][++j])
		{
			if (j == (int)g->c.x / SIZE && i == (int)g->c.y / SIZE)
				drawminiplayer(g, (int)g->ymap, (int)g->xmap, len);
			else if (g->m.map[i][j] == '1')
				drawminiwall(g, g->xmap, g->ymap, len);
			else
				draw_minimap_2(g, i, j, len);
			g->xmap += len;
		}
		g->ymap += len;
	}
}
