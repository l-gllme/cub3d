/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:14:37 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:15:03 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initWallTextures_2(t_data ouest, t_g *g)
{
	int	i_h;
	int	i_w;

	ouest.img = mlx_xpm_file_to_image(g->mlx, g->m.we_texture + 1, &i_w, &i_h);
	ouest.addr = mlx_get_data_addr(ouest.img, &ouest.bits_per_pixel, &ouest.line_length, &ouest.endian);
	g->ouest = ouest;
}

void	initWallTextures(t_data nord, t_data sud, t_data est, t_g *g)
{
	int	i_h;
	int	i_w;

	nord.img = mlx_xpm_file_to_image(g->mlx, g->m.no_texture + 1, &i_w, &i_h);
	nord.addr = mlx_get_data_addr(nord.img, &nord.bits_per_pixel, &nord.line_length, &nord.endian);
	sud.img = mlx_xpm_file_to_image(g->mlx, g->m.so_texture + 1, &i_w, &i_h);
	sud.addr = mlx_get_data_addr(sud.img, &sud.bits_per_pixel, &sud.line_length, &sud.endian);
	est.img = mlx_xpm_file_to_image(g->mlx, g->m.ea_texture + 1, &i_w, &i_h);
	est.addr = mlx_get_data_addr(est.img, &est.bits_per_pixel, &est.line_length, &est.endian);
	g->nord = nord;
	g->sud = sud;
	g->est = est;
}

void	initBonusTextures(t_data hand_1, t_data hand_2, t_data hand_3, t_g *g)
{
	int	i_h;
	int	i_w;
	t_data	hand_4;
	t_data	hand_5;

	hand_1.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_1.xpm", &i_w, &i_h);
	hand_1.addr = mlx_get_data_addr(hand_1.img, &hand_1.bits_per_pixel, &hand_1.line_length, &hand_1.endian);
	hand_2.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_2.xpm", &i_w, &i_h);
	hand_2.addr = mlx_get_data_addr(hand_2.img, &hand_2.bits_per_pixel, &hand_2.line_length, &hand_2.endian);
	hand_3.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_3.xpm", &i_w, &i_h);
	hand_3.addr = mlx_get_data_addr(hand_3.img, &hand_3.bits_per_pixel, &hand_3.line_length, &hand_3.endian);
	hand_4.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_4.xpm", &i_w, &i_h);
	hand_4.addr = mlx_get_data_addr(hand_4.img, &hand_4.bits_per_pixel, &hand_4.line_length, &hand_4.endian);
	hand_5.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_5.xpm", &i_w, &i_h);
	hand_5.addr = mlx_get_data_addr(hand_5.img, &hand_5.bits_per_pixel, &hand_5.line_length, &hand_5.endian);
	g->hand_1 = hand_1;
	g->hand_2 = hand_2;
	g->hand_3 = hand_3;
	g->hand_4 = hand_4;
	g->hand_5 = hand_5;
}

void	initBonusTextures_2(t_data b, t_data bc, t_data d, t_g *g)
{
	int	i_h;
	int	i_w;

	if (!(d.img = mlx_xpm_file_to_image(g->mlx, "imgs/D.xpm", &i_w, &i_h)))
		exit(0);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, &d.endian);
	b.img = mlx_xpm_file_to_image(g->mlx, "imgs/B.xpm", &i_w, &i_h);
	b.addr = mlx_get_data_addr(b.img, &b.bits_per_pixel, &b.line_length, &b.endian);
	bc.img = mlx_xpm_file_to_image(g->mlx, "imgs/BC.xpm", &i_w, &i_h);
	bc.addr = mlx_get_data_addr(bc.img, &bc.bits_per_pixel, &bc.line_length, &bc.endian);
	g->b = b;
	g->bc = bc;
	g->d = d;
}

void	initBonusTextures_3(t_data cross, t_data img, t_g *g)
{
	int	i_h;
	int	i_w;

	cross.img = mlx_xpm_file_to_image(g->mlx, "imgs/crosshair.xpm", &i_w, &i_h);
	cross.addr = mlx_get_data_addr(cross.img, &cross.bits_per_pixel, &cross.line_length, &cross.endian);
	img.img = mlx_new_image(g->mlx, W_W, W_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	g->img = img;
	g->cross = cross;
}

void	initBonusTextures_4(t_data w_1, t_data w_2, t_data exit, t_g *g)
{
	int	i_h;
	int	i_w;

	w_1.img = mlx_xpm_file_to_image(g->mlx, "imgs/w_1.xpm", &i_w, &i_h);
	w_1.addr = mlx_get_data_addr(w_1.img, &w_1.bits_per_pixel, &w_1.line_length, &w_1.endian);
	w_2.img = mlx_xpm_file_to_image(g->mlx, "imgs/w_2.xpm", &i_w, &i_h);
	w_2.addr = mlx_get_data_addr(w_2.img, &w_2.bits_per_pixel, &w_2.line_length, &w_2.endian);
	exit.img = mlx_xpm_file_to_image(g->mlx, "imgs/Exit.xpm", &i_w, &i_h);
	exit.addr = mlx_get_data_addr(exit.img, &exit.bits_per_pixel, &exit.line_length, &exit.endian);
	g->w_1 = w_1;
	g->w_2 = w_2;
	g->exit = exit;
}
