/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementCheck_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <jtaravel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:23:07 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 23:24:15 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_next_pos_w_2(t_g *g, double angle)
{
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE]
		[(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == '1')
		return (0);
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE]
		[(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == 'P'
		&& !g->activatebutton)
		return (0);
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE]
		[(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == 'B')
		return (0);
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE]
		[(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == 'H')
		return (0);
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE]
		[(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == 'G')
		return (0);
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE]
		[(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == 'M')
		return (0);
	return (1);
}

int	angle_check_w(t_g *g, double angle)
{
	if (angle > 180 * PI / 180 && angle <= 270 * PI / 180)
	{
		if (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE - 1]
			[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE] == '1'
			&& (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE]
			[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE + 1] == '1'))
			return (0);
	}
	else if (angle > 270 * PI / 180 && angle <= 360 * PI / 180)
	{
		if (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE - 1]
			[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE] == '1'
			&& (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE]
			[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE - 1] == '1'))
			return (0);
	}
	else if (angle > 90 * PI / 180 && angle <= 180 * PI * 180)
	{
		if (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE + 1]
			[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE] == '1'
			&& (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE]
			[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE + 1] == '1'))
			return (0);
	}
	return (1);
}

int	check_next_pos_w(t_g *g, double angle)
{
	if ((int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE != (int)g->c.y / SIZE
		&& (int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE !=
		(int)g->c.x / SIZE)
	{
		if (angle >= 0 * PI / 180 && angle <= 90 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE + 1]
				[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE] == '1'
			&& (g->m.map[(int)(g->c.y - (cos(angle) * (WD_SPEED))) / SIZE]
			[(int)(g->c.x + (sin(angle) * (WD_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
		else
			if (!angle_check_w(g, angle))
				return (0);
	}
	if (!check_next_pos_w_2(g, angle))
		return (0);
	return (1);
}
