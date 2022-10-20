/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyDetection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:30:45 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/20 13:47:48 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_keypress_2(int key, t_g *g)
{
	if (key == R)
		g->key_r = 1;
	if (key == L)
		g->key_l = 1;
	if (key == O)
		g->key_o = 1;
	if (key == RC)
		g->key_rc = 1;
	if (key == LC)
	{
		if (g->key_lc == 0)
			g->key_lc = 1;
		else
			g->key_lc = 0;
	}
	if (key == CTRL)
		g->key_ctrl = 1;
	if (key == SHIFT)
		g->key_shift = 1;
}

int	ft_keypress(int key, t_g *g)
{
	if (key == ESC)
	{
		free_all(g, 100, 0);
		printf("ESC PRESSED");
		exit(0);
	}
	if (key == W)
		g->key_w = 1;
	if (key == A)
		g->key_a = 1;
	if (key == S)
		g->key_s = 1;
	if (key == D)
		g->key_d = 1;
	if (key == E)
		g->key_e = 1;
	ft_keypress_2(key, g);
	return (0);
}

void	ft_keyrelease_2(int key, t_g *g)
{
	if (key == O)
		g->key_o = 0;
	if (key == RC)
		g->key_rc = 0;
	if (key == CTRL)
	{
		g->s_m = 6;
		g->key_ctrl = 0;
	}
	if (key == SHIFT)
	{
		g->s_m = 2;
		g->key_shift = 0;
	}
}

int	ft_keyrelease(int key, t_g *g)
{
	if (key == W)
		g->key_w = 0;
	if (key == A)
		g->key_a = 0;
	if (key == S)
		g->key_s = 0;
	if (key == D)
		g->key_d = 0;
	if (key == R)
		g->key_r = 0;
	if (key == L)
		g->key_l = 0;
	ft_keyrelease_2(key, g);
	return (0);
}
