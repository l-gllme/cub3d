/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:03:01 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:03:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_g_2(t_g *g)
{
	g->key_O = 0;
	g->key_R = 0;
	g->key_L = 0;
	g->key_E = 0;
	g->key_LC = 0;
	g->key_RC = 0;
	g->DistButton = 999;
	g->startTime = 0;
	g->oldTime = 0;
	g->mouseR = 0;
	g->mouseL = 0;
	g->FOVP = FOV * PI / 180;
	g->FOVD2 = (FOV / 2) * PI / 180;
	g->angle = 0;
	g->tmpX = 0;
	g->tmpY = 0;
	g->xOld = 0;
	g->yOld = 0;
	g->xmap = 0;
	g->ymap = 0;
}

void	init_struct_g(t_g *g, int ac, char **av)
{
	g->ac = ac;
	g->av = av;
	g->count = 0;
	g->i = 0;
	g->anim = 0;
	g->activateButton = 0;
	g->affCheck = 0;
	g->mouseHide = 1;
	g->key_W = 0;
	g->key_A = 0;
	g->key_S = 0;
	g->key_D = 0;
	init_struct_g_2(g);
}

void	init_struct_m(t_m *m)
{
	m->map = NULL;
	m->no_texture = NULL;
	m->so_texture = NULL;
	m->ea_texture = NULL;
	m->we_texture = NULL;
}
