/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniMap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:29:44 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 16:30:28 by jtaravel         ###   ########.fr       */
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
