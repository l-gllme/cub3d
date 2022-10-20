/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:25:58 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/20 12:40:27 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_g *g)
{
	exit(0);
	int	i;

	i = -1;
	mlx_destroy_image(g->mlx, g->ouest.img);
	mlx_destroy_image(g->mlx, g->nord.img);
	mlx_destroy_image(g->mlx, g->sud.img);
	mlx_destroy_image(g->mlx, g->est.img);
	mlx_destroy_image(g->mlx, g->bc.img);
	mlx_destroy_image(g->mlx, g->b.img);
	mlx_destroy_image(g->mlx, g->d.img);
	mlx_destroy_image(g->mlx, g->hand_1.img);
	mlx_destroy_image(g->mlx, g->hand_2.img);
	mlx_destroy_image(g->mlx, g->hand_3.img);
	mlx_destroy_image(g->mlx, g->cross.img);
	mlx_destroy_image(g->mlx, g->img.img);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	while (g->m.map[++i])
		free(g->m.map[i]);
	free(g->m.map);
	free(g->m.no_texture);
	free(g->m.so_texture);
	free(g->m.ea_texture);
	free(g->m.we_texture);
}
