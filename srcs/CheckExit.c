/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckExit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:22:24 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/18 16:34:30 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pp(t_data *data, double x, double y, int color);

void	displayEnd(t_g *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_W)
	{
		j = 0;
		while (j < W_H)
		{
			pp(&g->img, i, j, 0x000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	i = 0;
	while (++i < 3000000)
		mlx_string_put(g->mlx, g->win, W_W / 2 - 80, W_H / 2, 0x444444, "Thank you for playing :) !");
}

void	CheckPosExit(t_g *g)
{
	if (g->m.map[(int)g->c.y / SIZE][(int)g->c.x / SIZE] == 'X')
	{
		displayEnd(g);
		exit(0);
	}
}
