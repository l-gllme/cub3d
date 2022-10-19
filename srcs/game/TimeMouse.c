/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeMouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:05:36 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:07:06 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mousetracking(t_g *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(g->mlx, g->win, &x, &y);
	if (x > W_W / 2)
	{
		ft_keypress(R, g);
		g->mouseR = 1;
	}
	if (x < W_W / 2)
	{
		ft_keypress(L, g);
		g->mouseL = 1;
	}
	mlx_mouse_move(g->mlx, g->win, W_W / 2, W_W / 2);
	return (0);
}

long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

long long	ft_currenttime(t_g *g)
{
	return ((get_time() - g->startTime));
}

void	afftime(t_g *g)
{
	char		*temp;
	u_int64_t	time;
	double		frame;

	time = get_time() - g->startTime;
	frame = (time - g->oldTime) / 1000.0;
	temp = ft_itoa((int)(1 / frame));
	g->oldTime = time;
	mlx_string_put(g->mlx, g->win, W_W - 50, 25, 0x444444, temp);
	mlx_string_put(g->mlx, g->win, W_W - 35, 25, 0x444444, "FPS");
	free(temp);
}
