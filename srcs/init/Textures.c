/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:14:37 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/20 13:48:54 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_img_64(t_g *g, t_data *img, char *path)
{
	int	i_h;
	int	i_w;

	img->img = mlx_xpm_file_to_image(g->mlx, path, &i_w, &i_h);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (i_h != 64 || i_w != 64)
		return (0);
	return (1);
}

int	open_img_200(t_g *g, t_data *img, char *path)
{
	int	i_h;
	int	i_w;

	img->img = mlx_xpm_file_to_image(g->mlx, path, &i_w, &i_h);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (i_h != 200 || i_w != 200)
		return (0);
	return (1);
}

void	init_bonus_textures(t_data hand_1, t_data hand_2, t_data hand_3, t_g *g)
{
	t_data	hand_4;
	t_data	hand_5;

	if (!open_img_200(g, &hand_1, "imgs/hand_1.xpm"))
		free_all(g, 5, 1);
	g->hand_1 = hand_1;
	if (!open_img_200(g, &hand_2, "imgs/hand_2.xpm"))
		free_all(g, 6, 1);
	g->hand_2 = hand_2;
	if (!open_img_200(g, &hand_3, "imgs/hand_3.xpm"))
		free_all(g, 7, 1);
	g->hand_3 = hand_3;
	if (!open_img_200(g, &hand_4, "imgs/hand_4.xpm"))
		free_all(g, 8, 1);
	g->hand_4 = hand_4;
	if (!open_img_200(g, &hand_5, "imgs/hand_5.xpm"))
		free_all(g, 9, 1);
	g->hand_5 = hand_5;
}

void	init_bonus_textures_2(t_data b, t_data bc, t_data d, t_g *g)
{
	t_data	w_1;
	t_data	w_2;
	t_data	exit1;

	if (!open_img_64(g, &d, "imgs/D.xpm"))
		free_all(g, 10, 1);
	g->d = d;
	if (!open_img_64(g, &b, "imgs/B.xpm"))
		free_all(g, 11, 1);
	g->b = b;
	if (!open_img_64(g, &bc, "imgs/BC.xpm"))
		free_all(g, 12, 1);
	g->bc = bc;
	if (!open_img_64(g, &w_1, "imgs/w_1.xpm"))
		free_all(g, 13, 1);
	g->w_1 = w_1;
	if (!open_img_64(g, &w_2, "imgs/w_2.xpm"))
		free_all(g, 14, 1);
	g->w_2 = w_2;
	if (!open_img_64(g, &exit1, "imgs/Exit.xpm"))
		free_all(g, 15, 1);
	g->exit = exit1;
}

void	init_bonus_textures_3(t_data cross, t_data img, t_g *g)
{
	if (!open_img_64(g, &cross, "imgs/crosshair.xpm"))
		free_all(g, 16, 1);
	g->cross = cross;
	img.img = mlx_new_image(g->mlx, W_W, W_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	g->img = img;
}
