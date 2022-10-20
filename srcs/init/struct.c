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
	g->key_o = 0;
	g->key_r = 0;
	g->key_l = 0;
	g->key_e = 0;
	g->key_lc = 0;
	g->key_rc = 0;
	g->distbutton = 999;
	g->starttime = 0;
	g->oldtime = 0;
	g->mouser = 0;
	g->mousel = 0;
	g->fovp = FOV * PI / 180;
	g->fovd2 = (FOV / 2) * PI / 180;
	g->angle = 0;
	g->tmpx = 0;
	g->tmpy = 0;
	g->xold = 0;
	g->yold = 0;
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
	g->activatebutton = 0;
	g->affcheck = 0;
	g->key_w = 0;
	g->key_a = 0;
	g->key_s = 0;
	g->key_d = 0;
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
