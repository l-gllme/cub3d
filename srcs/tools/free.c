/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:25:58 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/20 15:32:46 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2(t_g *g, int n)
{
	if (n > 6)
		mlx_destroy_image(g->mlx, g->hand_2.img);
	if (n > 7)
		mlx_destroy_image(g->mlx, g->hand_3.img);
	if (n > 8)
		mlx_destroy_image(g->mlx, g->hand_4.img);
	if (n > 9)
		mlx_destroy_image(g->mlx, g->hand_5.img);
	if (n > 10)
		mlx_destroy_image(g->mlx, g->d.img);
	if (n > 11)
		mlx_destroy_image(g->mlx, g->b.img);
	if (n > 12)
		mlx_destroy_image(g->mlx, g->bc.img);
	if (n > 13)
		mlx_destroy_image(g->mlx, g->w_1.img);
	if (n > 14)
		mlx_destroy_image(g->mlx, g->w_2.img);
	if (n > 15)
		mlx_destroy_image(g->mlx, g->exit.img);
	if (n > 16)
		mlx_destroy_image(g->mlx, g->cross.img);
	if (n > 17)
		mlx_destroy_image(g->mlx, g->img.img);
}

static void	cut(t_g *g)
{
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free(g->m.no_texture);
	free(g->m.so_texture);
	free(g->m.ea_texture);
	free(g->m.we_texture);
}

void	free_all(t_g *g, int n, int e)
{
	int	i;

	i = -1;
	if (n > 1)
		mlx_destroy_image(g->mlx, g->nord.img);
	if (n > 2)
		mlx_destroy_image(g->mlx, g->sud.img);
	if (n > 3)
		mlx_destroy_image(g->mlx, g->est.img);
	if (n > 4)
		mlx_destroy_image(g->mlx, g->ouest.img);
	if (n > 5)
		mlx_destroy_image(g->mlx, g->hand_1.img);
	free_2(g, n);
	while (g->m.map[++i])
		free(g->m.map[i]);
	free(g->m.map);
	cut(g);
	if (e)
		ft_putstr_fd("\nError\ncub3d: Invalid Texture\n", 2);
	exit(0);
}
