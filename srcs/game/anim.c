/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:10:47 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 14:42:33 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Pistol animation */

static void	create_hand_img_r(t_data img, t_data h, int i, int j)
{
	int	i_w;
	int	pos;

	i_w = (h.line_length / 4) * 2;
	pos = 0;
	while (++j < i_w)
	{
		i = -1;
		while (++i < 400)
		{
			pos = h.line_length - ((i / 2) * 4) + h.line_length * (j / 2);
			if (h.addr[pos + 3] == 0)
			{
				pp(&img, i + (W_W / 2 - i_w), j + (W_H - 400),
					get_pixel_2(h.line_length - i / 2, j / 2, &h));
			}
		}
	}
}

static void	create_hand_img(t_data img, t_data h, int i, int j)
{
	int	i_w;
	int	pos;

	i_w = (h.line_length / 4) * 2;
	pos = 0;
	while (++j < i_w)
	{
		i = -1;
		while (++i < 400)
		{
			pos = (i / 2) * 4 + h.line_length * (j / 2);
			if (h.addr[pos + 3] == 0)
			{
				pp(&img, i + (W_W / 2), j + (W_H - 400),
					get_pixel_2(i / 2, j / 2, &h));
			}
		}
	}
}

static void	single_pistol(t_g *g)
{
	if (g->anim < 16 && g->anim != 0 && g->key_LC == 1)
	{
		create_hand_img(g->img, g->hand_5, -1, -1);
		create_hand_img_r(g->img, g->hand_5, -1, -1);
	}
	else if (g->anim < 4 && g->anim != 0 && g->key_LC == 0)
		create_hand_img(g->img, g->hand_2, -1, -1);
	else if (g->anim < 8 && g->anim != 0 && g->key_LC == 0)
		create_hand_img(g->img, g->hand_3, -1, -1);
	else if (g->anim < 12 && g->anim != 0 && g->key_LC == 0)
		create_hand_img(g->img, g->hand_4, -1, -1);
	else if (g->anim < 16 && g->anim != 0 && g->key_LC == 0)
		create_hand_img(g->img, g->hand_5, -1, -1);
	g->anim++;
}

static void	akimbo(t_g *g)
{
	if (g->anim < 4 && g->anim != 0 && g->key_LC == 1)
	{
		create_hand_img(g->img, g->hand_2, -1, -1);
		create_hand_img_r(g->img, g->hand_2, -1, -1);
		g->anim++;
	}
	else if (g->anim < 8 && g->anim != 0 && g->key_LC == 1)
	{
		create_hand_img(g->img, g->hand_3, -1, -1);
		create_hand_img_r(g->img, g->hand_3, -1, -1);
		g->anim++;
	}
	else if (g->anim < 12 && g->anim != 0 && g->key_LC == 1)
	{
		create_hand_img(g->img, g->hand_4, -1, -1);
		create_hand_img_r(g->img, g->hand_4, -1, -1);
		g->anim++;
	}
	else
		single_pistol(g);
}

void	pistol_anim(t_g *g)
{
	if (g->key_RC == 0 && g->anim == 0 && g->key_LC == 0)
		create_hand_img(g->img, g->hand_1, -1, -1);
	else if (g->key_RC == 0 && g->anim == 0 && g->key_LC == 1)
	{
		create_hand_img(g->img, g->hand_1, -1, -1);
		create_hand_img_r(g->img, g->hand_1, -1, -1);
	}
	else if ((g->key_RC == 1 || g->button_left == 1)
		&& (g->anim == 0 || g->anim == 16))
	{
		if (ray_calculator(g, g->angle, g->c.x, g->c.y))
		{
			if (g->w_1check)
				g->m.map[(int)g->dirY / SIZE][(int)g->dirX / SIZE] = 'G';
			if (g->w_2check)
				g->m.map[(int)g->dirY / SIZE][(int)g->dirX / SIZE] = '0';
		}
		g->anim += 1;
	}
	else
		akimbo(g);
	if (g->anim == 16)
		g->anim = 0;
}
