/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyDetection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:30:45 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 15:35:35 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_keypress_2(int key, t_g *g)
{
	if (key == R)
		g->key_R = 1;
	if (key == L)
		g->key_L = 1;
	if (key == O)
		g->key_O = 1;
	if (key == RC)
		g->key_RC = 1;
	if (key == LC)
	{
		if (g->key_LC == 0)
			g->key_LC = 1;
		else
			g->key_LC = 0;
	}
	if (key == CTRL)
		g->key_CTRL = 1;
	if (key == SHIFT)
		g->key_SHIFT = 1;
}

int	ft_keypress(int key, t_g *g)
{
	if (key == ESC)
	{
		free_all(g);
		printf("ESC PRESSED");
		exit(0);
	}
	if (key == W)
		g->key_W = 1;
	if (key == A)
		g->key_A = 1;
	if (key == S)
		g->key_S = 1;
	if (key == D)
		g->key_D = 1;
	if (key == E)
		g->key_E = 1;
	ft_keypress_2(key, g);
	return (0);
}

void	ft_keyrelease_2(int key, t_g *g)
{
	if (key == O)
		g->key_O = 0;
	if (key == RC)
		g->key_RC = 0;
	if (key == CTRL)
	{
		g->S_M = 6;
		g->key_CTRL = 0;
	}
	if (key == SHIFT)
	{
		g->S_M = 2;
		g->key_SHIFT = 0;
	}
}

int	ft_keyrelease(int key, t_g *g)
{
	if (key == W)
		g->key_W = 0;
	if (key == A)
		g->key_A = 0;
	if (key == S)
		g->key_S = 0;
	if (key == D)
		g->key_D = 0;
	if (key == R)
		g->key_R = 0;
	if (key == L)
		g->key_L = 0;
	ft_keyrelease_2(key, g);
	return (0);
}
