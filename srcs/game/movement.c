/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:20:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 23:04:21 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rotate(t_g *g, char dir)
{
	double	angle;

	if (dir == 'l')
	{
		if (g->c.o - R_SPEED < 0)
			g->c.o = 360 - R_SPEED;
		else
			g->c.o -= R_SPEED;
	}
	else if (dir == 'r')
	{
		if (g->c.o + R_SPEED == 360)
			g->c.o = 0;
		else if (g->c.o + R_SPEED > 360)
			g->c.o = 0 + R_SPEED;
		else
			g->c.o += R_SPEED;
	}
	angle = g->c.o;
	if (angle < 0)
		angle = angle + 2 * PI;
	angle = (PI * angle) / 180;
	return (angle);
}

void	ft_move_3(t_g *g)
{
	if (g->key_r)
		g->angle = rotate(g, 'r');
	if (g->key_l)
		g->angle = rotate(g, 'l');
	if (g->mouser)
	{
		ft_keyrelease(R, g);
		g->mouser = 0;
	}
	if (g->mousel)
	{
		ft_keyrelease(L, g);
		g->mousel = 0;
	}
}

void	ft_move_2(t_g *g)
{
	if (g->key_w && check_next_pos_w(g, g->angle))
	{
		g->c.x = g->c.x + sin(g->angle) * g->s_m;
		g->c.y = g->c.y - cos(g->angle) * g->s_m;
	}
	else if (g->key_a && check_next_pos_a(g, g->angle))
	{
		g->c.x = g->c.x - cos(g->angle) * g->s_m;
		g->c.y = g->c.y - sin(g->angle) * g->s_m;
	}
	else if (g->key_s && check_next_pos_s(g, g->angle))
	{
		g->c.x = g->c.x - sin(g->angle) * g->s_m;
		g->c.y = g->c.y + cos(g->angle) * g->s_m;
	}
	else if (g->key_d && check_next_pos_d(g, g->angle))
	{
		g->c.x = g->c.x + cos(g->angle) * g->s_m;
		g->c.y = g->c.y + sin(g->angle) * g->s_m;
	}
}

int	ft_move(t_g *g)
{
	static double	first;

	if (first == 0)
	{
		g->angle = rotate(g, 'p');
		first = 1;
	}
	if (g->key_e && g->distbutton < 60.0 && g->activatebutton == 0)
	{
		g->affcheck = 1;
		g->activatebutton = 1;
		g->key_e = 0;
	}
	else if (g->key_e && g->distbutton < 60.0 && g->activatebutton == 1)
	{
		g->affcheck = 1;
		g->activatebutton = 0;
		g->key_e = 0;
	}
	ft_move_2(g);
	ft_move_3(g);
	draw_map(g);
	first = 2;
	return (0);
}
