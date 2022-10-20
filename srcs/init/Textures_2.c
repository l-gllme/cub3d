/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:56:37 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/20 13:49:07 by lguillau         ###   ########.fr       */
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
		free_all(g, 1, 1);
	g->nord = n;
	if (!open_img_64(g, &s, g->m.so_texture + 1))
		free_all(g, 2, 1);
	g->sud = s;
	if (!open_img_64(g, &e, g->m.ea_texture + 1))
		free_all(g, 3, 1);
	g->est = e;
	if (!open_img_64(g, &o, g->m.we_texture + 1))
		free_all(g, 4, 1);
	g->ouest = o;
}
