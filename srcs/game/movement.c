/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:20:46 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 15:12:19 by jtaravel         ###   ########.fr       */
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
	if (g->key_R)
		g->angle = rotate(g, 'r');
	if (g->key_L)
		g->angle = rotate(g, 'l');
	if (g->mouseR)
	{
		ft_keyRelease(R, g);
		g->mouseR = 0;
	}
	if (g->mouseL)
	{
		ft_keyRelease(L, g);
		g->mouseL = 0;
	}
}

void	ft_move_2(t_g *g)
{
	if (g->key_W && check_next_pos_W(g, g->angle))
	{
		g->c.x = g->c.x + sin(g->angle) * g->S_M;
		g->c.y = g->c.y - cos(g->angle) * g->S_M;
	}
	else if (g->key_A && check_next_pos_A(g, g->angle))
	{
		g->c.x = g->c.x - cos(g->angle) * g->S_M;
		g->c.y = g->c.y - sin(g->angle) * g->S_M;
	}
	else if (g->key_S && check_next_pos_S(g, g->angle))
	{
		g->c.x = g->c.x - sin(g->angle) * g->S_M;
		g->c.y = g->c.y + cos(g->angle) * g->S_M;
	}
	else if (g->key_D && check_next_pos_D(g, g->angle))
	{
		g->c.x = g->c.x + cos(g->angle) * g->S_M;
		g->c.y = g->c.y + sin(g->angle) * g->S_M;
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
	if (g->key_E && g->DistButton < 60.0 && g->activateButton == 0)
	{
		g->affCheck = 1;
		g->activateButton = 1;
		g->key_E = 0;
	}
	else if (g->key_E && g->DistButton < 60.0 && g->activateButton == 1)
	{
		g->affCheck = 1;
		g->activateButton = 0;
		g->key_E = 0;
	}
	ft_move_2(g);
	ft_move_3(g);
	draw_map(g);
	first = 2;
	return (0);
}
