/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckExit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:22:24 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/20 15:36:57 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_cross(t_g *g)
{
	(void)g;
	printf("Fermeture de la fenetre...");
	free_all(g, 100, 0);
	exit(0);
}

void	checkposexit(t_g *g)
{
	int		i_w;
	int		i_h;
	int		i;
	t_data	end;

	if (g->m.map[(int)g->c.y / SIZE][(int)g->c.x / SIZE] == 'X')
	{
		end.img = mlx_xpm_file_to_image(g->mlx, "imgs/END.xpm", &i_w, &i_h);
		if (!end.img || i_w != 1000 || i_h != 700)
		{
			mlx_destroy_image(g->mlx, end.img);
			free_all(g, 100, 1);
			exit (0);
		}
		end.addr = mlx_get_data_addr(end.img,
				&end.bits_per_pixel, &end.line_length, &end.endian);
		i = 0;
		while (++i < 1000)
			mlx_put_image_to_window(g->mlx, g->win, end.img, 0, 0);
		mlx_destroy_image(g->mlx, end.img);
		free_all(g, 100, 0);
		exit(0);
	}
}
