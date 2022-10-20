/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:42:06 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/20 13:14:04 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_g *g)
{
	drawrow1(g, &g->img, 0, 0);
	draw_minimap(g);
	pistol_anim(g);
	create_crosshair(g->img, g->cross);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	afftime(g);
}

int	start(t_g *g)
{
	checkposexit(g);
	ft_move(g);
	if (MOUSE_ON)
		mousetracking(g);
	return (0);
}

void	firstinit(t_g *g, t_m *m, int ac, char **av)
{
	init_struct_g(g, ac, av);
	init_struct_m(m);
	g->w_1check = 0;
	g->button_left = 0;
	g->button_right = 0;
	g->s_m = SPEED;
}

void	secondinit(t_g *g)
{
	g->win = mlx_new_window(g->mlx, W_W, W_H, "cub3d");
	init_wall_textures(g);
	init_bonus_textures(g->hand_1, g->hand_2, g->hand_3, g);
	init_bonus_textures_2(g->b, g->bc, g->d, g);
	init_bonus_textures_3(g->cross, g->img, g);
	recustartpos(g);
	recuprgb(g);
	draw_map(g);
}

int	main(int ac, char **av)
{
	t_m	m;
	t_g	g;

	printf("test = %d\n", MOUSE_ON);
	if (ac != 2)
		return (ft_errors(2), -1);
	firstinit(&g, &m, ac, av);
	if (!ft_parsing(&g))
		return (-1);
	g.mlx = mlx_init();
	if (!g.mlx)
		return (free_m(&g), ft_errors(3), -1);
	secondinit(&g);
	mlx_mouse_move(g.mlx, g.win, W_W / 2, W_H / 2);
	mlx_loop_hook(g.mlx, start, &g);
	mlx_hook(g.win, 2, 1L << 0, ft_keypress, &g);
	mlx_hook(g.win, 3, 1L << 1, ft_keyrelease, &g);
	mlx_hook(g.win, 17, 1L << 0, ft_key_cross, &g);
	mlx_loop(g.mlx);
	return (0);
}
