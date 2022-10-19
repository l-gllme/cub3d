/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:30:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 16:32:43 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	recup_no(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.no_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.no_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.no_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.no_texture[c] = 0;
	return (1);
}

int	recup_ea(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.ea_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.ea_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.ea_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.ea_texture[c] = 0;
	return (1);
}

int	recup_we(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.we_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.we_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.we_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.we_texture[c] = 0;
	return (1);
}

int	recup_so(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.so_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.so_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.so_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.so_texture[c] = 0;
	return (1);
}
