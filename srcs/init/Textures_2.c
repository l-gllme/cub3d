/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:56:37 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 18:57:11 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wall_textures(t_g *g)
{
	t_data	n;
	t_data	s;
	t_data	e;
	t_data	o;

	if (!open_img_64(g, &n, g->m.no_texture + 1))
		exit(0);
	if (!open_img_64(g, &s, g->m.so_texture + 1))
		exit(0);
	if (!open_img_64(g, &e, g->m.ea_texture + 1))
		exit(0);
	if (!open_img_64(g, &o, g->m.we_texture + 1))
		exit(0);
	g->nord = n;
	g->sud = s;
	g->est = e;
	g->ouest = o;
}
