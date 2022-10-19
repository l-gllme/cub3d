/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:16:30 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:36:09 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	creatergb(t_g *g)
{
	return ((g->m.c_r << 16) + (g->m.c_g << 8) + g->m.c_b);
}

int	creatergbsol(t_g *g)
{
	return ((g->m.f_r << 16) + (g->m.f_g << 8) + g->m.f_b);
}

void	recuprgb(t_g *g)
{
	g->cielcolor = creatergb(g);
	g->solcolor = creatergbsol(g);
}
