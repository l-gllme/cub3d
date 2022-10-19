/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartPosition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:09:19 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:12:54 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	recustartpos_n(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;
	g->c.y = y + SIZE / 2;
	g->c.o = 0;
}

void	recustartpos_s(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;
	g->c.y = y + SIZE / 2;
	g->c.o = 180;
}

void	recustartpos_w(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;
	g->c.y = y + SIZE / 2;
	g->c.o = 270;
}

void	recustartpos_e(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;
	g->c.y = y + SIZE / 2;
	g->c.o = 90;
}

void	recustartpos(t_g *g)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = -1;
	y = 0;
	while (g->m.map[++i])
	{
		j = -1;
		x = 0;
		while (g->m.map[i][++j])
		{
			if (g->m.map[i][j] == 'N')
				recustartpos_n(g, x, y);
			if (g->m.map[i][j] == 'S')
				recustartpos_s(g, x, y);
			if (g->m.map[i][j] == 'W')
				recustartpos_w(g, x, y);
			if (g->m.map[i][j] == 'E')
				recustartpos_e(g, x, y);
			x += SIZE;
		}
		y += SIZE;
	}
}
