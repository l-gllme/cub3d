/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:14:37 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 18:57:19 by jtaravel         ###   ########.fr       */
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
		exit(0);
	if (!open_img_200(g, &hand_2, "imgs/hand_2.xpm"))
		exit(0);
	if (!open_img_200(g, &hand_3, "imgs/hand_3.xpm"))
		exit(0);
	if (!open_img_200(g, &hand_4, "imgs/hand_4.xpm"))
		exit(0);
	if (!open_img_200(g, &hand_5, "imgs/hand_5.xpm"))
		exit(0);
	g->hand_1 = hand_1;
	g->hand_2 = hand_2;
	g->hand_3 = hand_3;
	g->hand_4 = hand_4;
	g->hand_5 = hand_5;
}

void	init_bonus_textures_2(t_data b, t_data bc, t_data d, t_g *g)
{
	t_data	w_1;
	t_data	w_2;
	t_data	exit1;

	if (!open_img_64(g, &d, "imgs/D.xpm"))
		exit(0);
	if (!open_img_64(g, &b, "imgs/B.xpm"))
		exit(0);
	if (!open_img_64(g, &bc, "imgs/BC.xpm"))
		exit(0);
	if (!open_img_64(g, &w_1, "imgs/w_1.xpm"))
		exit(0);
	if (!open_img_64(g, &w_2, "imgs/w_2.xpm"))
		exit(0);
	if (!open_img_64(g, &exit1, "imgs/Exit.xpm"))
		exit(0);
	g->b = b;
	g->bc = bc;
	g->d = d;
	g->w_1 = w_1;
	g->w_2 = w_2;
	g->exit = exit1;
}

void	init_bonus_textures_3(t_data cross, t_data img, t_g *g)
{
	if (!open_img_64(g, &cross, "imgs/crosshair.xpm"))
		exit(0);
	img.img = mlx_new_image(g->mlx, W_W, W_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	g->img = img;
	g->cross = cross;
}
