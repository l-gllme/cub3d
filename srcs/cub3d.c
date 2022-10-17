/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:42:06 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/17 20:19:20 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_g(t_g *g, int ac, char **av)
{
	g->ac = ac;
	g->av = av;
	g->count = 0;
	g->i = 0;
}

void	init_struct_m(t_m *m)
{
	m->map = NULL;
	m->no_texture = NULL;
	m->so_texture = NULL;
	m->ea_texture = NULL;
	m->we_texture = NULL;
}

int	ft_key_cross(t_g *g)
{
	(void)g;
	printf("Fermeture de la fenetre...");
	exit(0);
}

void	free_all(t_g *g)
{
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}

int	check_next_pos_W(t_g *g, double angle)
{
	if ((int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE != g->c.y && (int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE != g->c.x)
	{
		if (angle >= 0 * PI / 180 && angle <= 90 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
		else if (angle > 90 * PI / 180 && angle <= 180 * PI * 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 180 * PI / 180 && angle <= 270 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 270 * PI / 180 && angle <= 360 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
	}
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == '1')
		return (0);
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == 'P' && !g->activateButton)
		return (0);
	if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (sin(angle) * (C_SPEED))) / SIZE] == 'B')
		return (0);
	return (1);
}

int	check_next_pos_A(t_g *g, double angle)
{
	if ((int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE != g->c.y && (int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE != g->c.x)
	{
		if (angle >= 0 * PI / 180 && angle <= 90 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
		else if (angle > 90 * PI / 180 && angle <= 180 * PI * 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 180 * PI / 180 && angle <= 270 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 270 * PI / 180 && angle <= 360 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y - (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (cos(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
	}
	if (g->m.map[(int)(g->c.y - (int)(sin(angle) * C_SPEED)) / SIZE][(int)(g->c.x - (int)(cos(angle) * C_SPEED)) / SIZE] == '1')
		return (0);
	if (g->m.map[(int)(g->c.y - (int)(sin(angle) * C_SPEED)) / SIZE][(int)(g->c.x - (int)(cos(angle) * C_SPEED)) / SIZE] == 'P' && !g->activateButton)
		return (0);
	if (g->m.map[(int)(g->c.y - (int)(sin(angle) * C_SPEED)) / SIZE][(int)(g->c.x - (int)(cos(angle) * C_SPEED)) / SIZE] == 'B')
		return (0);
	return (1);
}

int	check_next_pos_S(t_g *g, double angle)
{
	if ((int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE != g->c.y && (int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE != g->c.x)
	{
		if (angle >= 0 * PI / 180 && angle <= 90 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
		else if (angle > 90 * PI / 180 && angle <= 180 * PI * 180)
		{
			if (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 180 * PI / 180 && angle <= 270 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 270 * PI / 180 && angle <= 360 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (cos(angle) * (C_SPEED))) / SIZE][(int)(g->c.x - (sin(angle) * (C_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
	}
	if (g->m.map[(int)(g->c.y + (int)(cos(angle) * C_SPEED)) / SIZE][(int)(g->c.x - (int)(sin(angle) * C_SPEED)) / SIZE] == '1')
		return (0);
	if (g->m.map[(int)(g->c.y + (int)(cos(angle) * C_SPEED)) / SIZE][(int)(g->c.x - (int)(sin(angle) * C_SPEED)) / SIZE] == 'P' && !g->activateButton)
		return (0);
	if (g->m.map[(int)(g->c.y + (int)(cos(angle) * C_SPEED)) / SIZE][(int)(g->c.x - (int)(sin(angle) * C_SPEED)) / SIZE] == 'B')
		return (0);
	return (1);
}

int	check_next_pos_D(t_g *g, double angle)
{
	if ((int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE != g->c.y && (int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE != g->c.x)
	{
		if (angle >= 0 * PI / 180 && angle <= 90 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
		else if (angle > 90 * PI / 180 && angle <= 180 * PI * 180)
		{
			if (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE + 1][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 180 * PI / 180 && angle <= 270 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE + 1] == '1'))
				return (0);
		}
		else if (angle > 270 * PI / 180 && angle <= 360 * PI / 180)
		{
			if (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE - 1][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE] == '1' && (g->m.map[(int)(g->c.y + (sin(angle) * (C_SPEED))) / SIZE][(int)(g->c.x + (cos(angle) * (C_SPEED))) / SIZE - 1] == '1'))
				return (0);
		}
	}
	if (g->m.map[(int)(g->c.y + (int)(sin(angle) * C_SPEED)) / SIZE][(int)(g->c.x + (int)(cos(angle) * C_SPEED)) / SIZE] == '1')
		return (0);
	if (g->m.map[(int)(g->c.y + (int)(sin(angle) * C_SPEED)) / SIZE][(int)(g->c.x + (int)(cos(angle) * C_SPEED)) / SIZE] == 'P' && !g->activateButton)
		return (0);
	if (g->m.map[(int)(g->c.y + (int)(sin(angle) * C_SPEED)) / SIZE][(int)(g->c.x + (int)(cos(angle) * C_SPEED)) / SIZE] == 'B')
		return (0);
	return (1);
}

void	draw_minimap(t_g *g);
int	mouseTracking(t_g *g);
void	drawMiniPlayer(t_g *g, double x, double y, double width, double height);

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
		angle = angle + 2*PI;
	angle = (PI * angle) / 180;
	return (angle);
}

double	print_dist_wall_W(t_g *g, double angle)
{
	double	d;
	double	x;
	double	y;
	double	xOld;
	double	yOld;
	double	cosA;
	double	sinA;

	g->door = 0;
	g->button = 0;
	cosA = cos(angle);
	sinA = sin(angle);
	x = g->c.x;
	y = g->c.y;
	xOld = x;
	yOld = y;
	d = 0;
	//printf("angle = %f\n", angle);
//	if (angle >= 0 && angle <= RAD_90)
	//{
		while (1)
		{
			xOld = x;
			yOld = y;
			y -= cosA;
			x += sinA;
			d += 1;
			//printf("x = %f\n", x);
			//printf("y = %f\n", y);
			if ((int)x / SIZE != (int)xOld / SIZE && (int)y / SIZE != (int)yOld / SIZE)
			{
				if (angle >= 45 * PI / 180 && angle < 135 * PI / 180)
					x = xOld;
				else if (angle >= 135 * PI / 180 && angle < 225 * PI * 180)
					y = yOld;
				else if (angle >= 225 * PI / 180 && angle < 315 * PI / 180)
					x = xOld;
				else if (angle >= 315 * PI / 180 && angle < 360 * PI / 180)
					y = yOld;
				else if (angle >= 0 * PI / 180 && angle < 45 * PI / 180)
					y = yOld;
			}

			if (g->m.map[(int)y / SIZE][(int)x / SIZE] == '1') 
				break;
			if (g->m.map[(int)y / SIZE][(int)x / SIZE] == 'P' && !g->activateButton) 
			{
				g->door = 1;
				break;
			}
			if (g->m.map[(int)y / SIZE][(int)x / SIZE] == 'B') 
			{
				g->button = 1;
				break;
			}
		}
		int i = 0;
		double	newX;
		double	newY;
		while (i < 10)
		{
			newX = (x + xOld) / 2;
			newY = (y + yOld) / 2;
			if (g->m.map[(int)newY / SIZE][(int)newX / SIZE] == '1' || (g->m.map[(int)newY / SIZE][(int)newX / SIZE] == 'P' && !g->activateButton) || g->m.map[(int)newY / SIZE][(int)newX / SIZE] == 'B')
			{
				x = newX;
				y = newY;
			}
			else
			{
				yOld = newY;
				xOld = newX;
			}
			i++;
		}
		d = sqrt(pow((x - g->c.x), 2) + pow((y - g->c.y), 2));
		if (g->button)
			g->DistButton = d;
		g->dirX = x;
		g->dirY = y;
		double Xtest = fmod(x, SIZEF);
		double Ytest = fmod(y, SIZEF);
		if (Xtest <= SIZE / 2)
		{
			if (Ytest <= SIZE / 2)
			{
				if (Xtest < Ytest)
					g->dir = 1;
				else
					g->dir = 3;
			}
			else
			{
				if (Xtest < SIZE - Ytest)
					g->dir = 1;
				else
					g->dir = 4;
			}
		}
		else
		{
			if (Ytest <= SIZE / 2)
			{
				if (SIZE - Xtest < Ytest)
					g->dir = 2;
				else
					g->dir = 3;
			}
			else
			{
				if (Xtest > Ytest)
					g->dir = 2;
				else
					g->dir = 4;
			}
		}
		/*if (SIZE - Xtest >= SIZE / 2 && SIZE - Ytest >= SIZE / 2 && SIZE - Xtest > SIZE - Ytest)
			g->dir = 1;
		else if (SIZE - Xtest <= SIZE / 2 && SIZE - Ytest >= SIZE / 2)// && Xtest - Ytest < SIZE)
			g->dir = 2;
		else if (SIZE - Xtest <= SIZE / 2 && SIZE - Ytest <= SIZE / 2 && SIZE - Xtest < SIZE - Ytest)
			g->dir = 3;
		else if (SIZE - Xtest >= SIZE / 2 && SIZE - Ytest <= SIZE / 2)
			g->dir = 4;*/

//	}
	/*
	if (angle > RAD_90 && angle <= RAD_180)
	{
		while (g->m.map[(int)(y + (cos(angle))) / SIZE][(int)(x + (sin(angle))) / SIZE] != '1')
		{
			y += cos(angle);
			x += sin(angle);
			d++;
		}
	}
	if (angle > RAD_180 && angle <= RAD_270)
	{
		while (g->m.map[(int)(y + (cos(angle))) / SIZE][(int)(x - (sin(angle))) / SIZE] != '1')
		{
			y += cos(angle);
			x -= sin(angle);
			d++;
		}
	}
	if (angle > RAD_270 && angle <= RAD_360)
	{	
		while (g->m.map[(int)(y - (cos(angle))) / SIZE][(int)(x - (sin(angle))) / SIZE] != '1')
		{
			y += cos(angle);
			x -= sin(angle);
			d++;
		}
	}*/
	/*printf("DISTANCE = %f\n", d);
	printf("PlayerX = %f\n", g->c.x);
	printf("PlayerY = %f\n", g->c.y);
	printf("X = %f\n", x);
	printf("Y = %f\n", y);*/
	return (d);
	//printf("wall dist = %f\n", d);
}

void    my_mlx_pixel_put(t_data *data, double x, double y, int color);

void	draw_wallTEST(t_g *g)
{
	int	x = W_W / 2;
	int	y = W_H / 2;

	while (x < W_W / 2 + 20)
	{
		y = W_H / 2 - 20;
		while (y < W_H / 2)
		{
			my_mlx_pixel_put(&g->img, x, y, COLOR);
			y++;
		}
		x++;
	}
}

int	ft_keyRelease(int key, t_g *g);
int	ft_move(t_g *g)
{
	//static	double	angle;
	static	double	first;
	if (g->key_R)
	{
		g->angle = rotate(g, 'r');
	}
	if (g->key_L)
	{
		g->angle = rotate(g, 'l');
	}
	else if (first == 0)
	{
		g->angle = rotate(g, 'p');
		first = 1;
	}
	//g->angle = angle;
	if (g->key_E && g->DistButton < 8.0 && g->activateButton == 0)
	{

		//printf("acti = %f\n", g->DistButton);
		g->affCheck = 1;
		g->activateButton = 1;
	}
	else if (g->key_E && g->DistButton < 8.0 && g->activateButton == 1)
	{
		g->affCheck = 1;
		g->activateButton = 0;
		//printf("acti = %f\n", g->DistButton);
	}
    	if (g->key_W && check_next_pos_W(g, g->angle))
    	{
		g->c.x = g->c.x + sin(g->angle) * SPEED;
		g->c.y = g->c.y - cos(g->angle) * SPEED;
		g->c.xmini = g->c.xmini + sin(g->angle);
		g->c.ymini = g->c.ymini - cos(g->angle);
		//draw_player(g, &g->img, &g->player);
    	}
	else if (g->key_A && check_next_pos_A(g, g->angle))
	{
		//printf("x = %f\n", cos(g->angle));
		//printf("y = %f\n", sin(g->angle));
		g->c.x = g->c.x - cos(g->angle) * SPEED;
		g->c.y = g->c.y - sin(g->angle) * SPEED;
		g->c.xmini = g->c.xmini - sin(g->angle);
		g->c.ymini = g->c.ymini - cos(g->angle);
		//draw_player(g, &g->img, &g->player);
    	}
	else if (g->key_S && check_next_pos_S(g, g->angle))
	{
		g->c.x = g->c.x - sin(g->angle) * SPEED;
		g->c.y = g->c.y + cos(g->angle) * SPEED;
		g->c.xmini = g->c.xmini - sin(g->angle);
		g->c.ymini = g->c.ymini + cos(g->angle);
		//draw_player(g, &g->img, &g->player);
    	}
	else if (g->key_D && check_next_pos_D(g, g->angle))
	{
		g->c.x = g->c.x + cos(g->angle) * SPEED;
		g->c.y = g->c.y + sin(g->angle) * SPEED;
		g->c.xmini = g->c.xmini + sin(g->angle);
		g->c.ymini = g->c.ymini + cos(g->angle);
		//draw_player(g, &g->img, &g->player);
    	}
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
	draw_map(g);
	if (g->key_O)
	{
		printf("x = %f, y = %f\n", g->c.x / 3 / SIZE, g->c.y / 3 / SIZE);
		my_mlx_pixel_put(&g->img, g->c.x / 3 / SIZE, g->c.y / 3 / SIZE, 0x000000);
	}
	//printf("test = %f\n", g->angle);
	//printf("start x = %f\n", g->c.x);
	//printf("start y = %f\n", g->c.y);
	//draw_wallTEST(g);
	//draw_player(g, &g->img, &g->player);
	//print_dist_wall_W(g, angle);
	first = 2;
	return (0);
}

int	ft_keyPress(int key, t_g *g)
{
	if (key == ESC)
	{
		free_all(g);
		printf("ESC PRESSED");
		exit(0);
	}
	if (key == W)
		g->key_W = 1;
	if (key == A)
		g->key_A = 1;
	if (key == S)
		g->key_S = 1;
	if (key == D)
		g->key_D = 1;
	if (key == E)
		g->key_E = 1;
	if (key == R)
		g->key_R = 1;
	if (key == L)
		g->key_L = 1;
	if (key == O)
		g->key_O = 1;
	if (key == RC)
		g->key_RC = 1;
	if (key == LC)
		g->key_LC = 1;
	return (0);
}

int	ft_keyRelease(int key, t_g *g)
{
	if (key == W)
		g->key_W = 0;
	if (key == A)
		g->key_A = 0;
	if (key == S)
		g->key_S = 0;
	if (key == D)
		g->key_D = 0;
	if (key == E)
		g->key_E = 0;
	if (key == R)
		g->key_R = 0;
	if (key == L)
		g->key_L = 0;
	if (key == O)
		g->key_O = 0;
	if (key == RC)
		g->key_RC = 0;
	if (key == LC)
		g->key_LC = 0;
	return (0);
}

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;

	dst = data->addr + (int)(((double)y * data->line_length + (double)x * (data->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}

/*int	get_longest_line_map(char **m, int choice)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (m[++i])
	{
		if (ft_strlen(m[i]) > ret && choice)
			ret = ft_strlen(m[i]);
	}
	if (choice)
		return (ret);
	return (i);
}

void	draw_1(t_g *g, t_data *img, double x, double y, double width, double height)
{
	double	to_go;
	double	to_g;
	double	i;
	double	value;
	(void)g;

	value = print_dist_wall_W(g, g->angle);
	if (value < 0)
		value *= -1;
	i = x;
	if (value)
		height = 100 / value;
	to_go = x + width;
	to_g = y + height;// - value + height;
	printf("distance = %f\n", value);
	printf("height = %f\n", height);
	double j = y + height;
	if (y < W_H / 2 && y > 1)
	{
		to_g += W_H / 2 - to_g;
		while (j < to_g)
		{
			i = x;
			while (i < to_go)
			{
				my_mlx_pixel_put(img, i, j, 0x4c5057);
				i++;
			}
			j++;
		}
	}
	else
	{
		while (j < to_g)
		{
			i = x;
			while (i < to_go)
			{
				my_mlx_pixel_put(img, i, j, 0x4c5057);
				i++;
			}
			j++;
		}
	}
}

void	draw_0(t_g *g, t_data *img, int x, int y, int width, int height)
{
	int	to_go;
	int	to_g;
	int	i;
	(void)g;

	i = x;
	to_go = x + width;
	to_g = y + height;
	int j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			my_mlx_pixel_put(img, i, j, 0x8ebbde);
			i++;
		}
		j++;
	}
*/


int	create_trgb(int t, int r, int g, int b);

void	draw_start(t_g *g, t_data *img, int x, int y)
{
	(void)x;
	(void)y;
	my_mlx_pixel_put(img, g->s_x, g->s_y, 0xFF0000);
}
void    test_draw(t_g *g, t_data *img, t_data *player);

void	display_sol(t_g *g, t_data *img, double j, double height, double y)
{
	while (j++ > W_H / 2 + height / 2)
		my_mlx_pixel_put(img, j, y, g->solcolor);
}

void	display_ciel(t_g *g, t_data *img, double j, double height, double y)
{
	while (j++ < W_H / 2 - height / 2)
		my_mlx_pixel_put(img, j, y, g->cielcolor);
}

int	checkSideCase(t_g *g)
{
	(void)g;
	return (0);
		
}
int    get_pixel(int x, int y, t_data i)
{
	char	*ret;

	ret = i.addr + (y * i.line_length + x * (i.bits_per_pixel / 8));
	return (*(unsigned int *)ret);
}

void	drawLineTEST(t_g *g, t_data *img, double x, double y);

void	draw_row(t_g *g, t_data *img, double y, double height)
{
	double j = -1;
	double	ciel;
	double floor1;
	ciel =  (W_H / 2) - (height / 2);
	floor1 = (W_H / 2) + (height / 2);
	while (++j < W_H)
	{
		if (j < ciel)
			my_mlx_pixel_put(img, y, j, g->cielcolor);
		else if (j > floor1)
			my_mlx_pixel_put(img, y, j, g->solcolor);
		else
		{
			if (g->door == 1 && !g->activateButton && (g->dir == 3 || g->dir == 4))
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirX, SIZEF),(j - ciel) * (SIZEF / height), g->d));
			else if (g->door == 1 && !g->activateButton && (g->dir == 1 || g->dir == 2))
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirY, SIZEF),(j - ciel) * (SIZEF / height), g->d));
			else if (g->button == 1 && (g->dir == 1 || g->dir == 2) && !g->activateButton)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirY, SIZEF),(j - ciel) * (SIZEF / height), g->b));
			else if (g->button == 1 && (g->dir == 3 || g->dir == 4) && !g->activateButton)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirX, SIZEF),(j - ciel) * (SIZEF / height), g->b));
			else if (g->button == 1 && (g->dir == 1 || g->dir == 2) && g->activateButton)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirY, SIZEF),(j - ciel) * (SIZEF / height), g->bc));
			else if (g->button == 1 && (g->dir == 3 || g->dir == 4) && g->activateButton)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirX, SIZEF),(j - ciel) * (SIZEF / height), g->bc));
			else if (g->dir == 1)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirY, SIZEF),(j - ciel) * (SIZEF / height), g->est));
			else if (g->dir == 1)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirY, SIZEF),(j - ciel) * (SIZEF / height), g->est));
			else if (g->dir == 2)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirY, SIZEF),(j - ciel) * (SIZEF / height), g->ouest));
			else if (g->dir == 3)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirX, SIZEF) ,(j - ciel) * (SIZEF / height), g->sud));
			else if (g->dir == 4)
				my_mlx_pixel_put(img, y, j, get_pixel((int)fmod(g->dirX, SIZEF),(j - ciel) * (SIZEF / height), g->nord));

		}
	}
}

void	drawRow1(t_g *g, t_data *img, double x, double y)
{
	double	d;
	double	wallDist;
	double	height = 0.0;
	double	fix;
	(void)y;
	(void)x;
	double i = 0;
	double Pi = 2 * PI;

	while (i < W_W)
	{
		d = (double)((g->FOVP / (W_W - 1) * i) + (double)((double)g->angle - (double)g->FOVD2));
		if (d < 0)
			d+= 360 * PI / 180;
		fix = g->angle - d;
		if (fix < 0)
			fix += Pi;
		else if (fix > Pi)
			fix -= Pi;
		g->rayAngle = d;
		wallDist = print_dist_wall_W(g, d) * cos(fix);
		height = 55000 / wallDist;
		draw_row(g, img, i, height);
		i++;
	}
}

void	drawLineTEST(t_g *g, t_data *img, double x, double y)
{
	while (x < W_W)
	{
		while (y < W_H)
		{
			my_mlx_pixel_put(img, x, y, g->cielcolor);
			y++;
		}
		x++;
	}
}

long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

long long	ft_currentTime(t_g *g)
{
	return ((get_time() - g->startTime));
}

void	affTime(t_g *g)
{
	char		*temp;
	u_int64_t	time;
	double		frame;

	time = get_time() - g->startTime;
	frame = (time - g->oldTime) / 1000.0;
	temp = ft_itoa((int)(1 / frame));
	g->oldTime = time;
	mlx_string_put(g->mlx, g->win, W_W - 50, 25, \
		0x444444, temp);
	mlx_string_put(g->mlx, g->win, W_W - 20, 25, \
		0x444444, "FPS");
	free(temp);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	get_pixel_2(int x, int y, t_data *i)
{
	char	*ret;

	ret = i->addr + (y * i->line_length + x * (i->bits_per_pixel / 8));
	return (*(unsigned int*)ret);
}

void	create_crosshair(t_data img, t_data h)
{
	int	i = -1;
	int	j = -1;
	int	i_w;
	int	color;
	int	pos = 0;

	(void)color;
	i_w = (h.line_length / 4);
	while (++j < i_w)
	{
		i = -1;
		while (++i < 64)
		{
			pos = i * 4 + h.line_length * j;
			if (h.addr[pos+3] == 0)
			{
				my_mlx_pixel_put(&img, i + (W_W / 2) - i_w / 2 , j + (W_H / 2) - 32, get_pixel_2(i, j, &h));
			}
		}
	}
}


void	create_hand_img(t_data img, t_data h)
{
	int	i = -1;
	int	j = -1;
	int	i_w;
	int	pos = 0;

	i_w = (h.line_length / 4) * 2;
	while (++j < i_w)
	{
		i = -1;
		while (++i < 400)
		{
			pos = (i / 2) * 4 + h.line_length * (j / 2);
			if (h.addr[pos+3] == 0)
			{
				my_mlx_pixel_put(&img, i + (W_W / 2 - i_w / 2) , j + (W_H - 400), get_pixel_2(i /2, j /2, &h));
			}
		}
	}
}

void    draw_map(t_g *g)
{

	//test_draw(g, img, &g->player);
	//width = W_W / (get_longest_line_map(g->m.map, 1)+1);
	//height = W_H / (get_longest_line_map(g->m.map, 0)+ 1);
	/*int a = 0;
	while (g->m.map[a])
	{
		int b = 0;
		while (g->m.map[a][b])
		{
			printf("%c\n", g->m.map[a][b]);
			b++;
		}
		a++;
	}*/
			
	/*while (g->m.map[++i])
		;
	i--;
	int k = 0;
	j = 0;
	while (j < i)
	{
		x = 0;
		k = 0;
		while (j < i)
		{
			if (g->m.map[j][k] == '1')
			{*/
				drawRow1(g, &g->img, 0, 0);
				//drawLineTEST(g, img, x, y);
		//	}
	//		x += width;
	//		j++;
	//	}
	//	k++;
	//	y += height;
//	}

	if (g->activateButton && g->affCheck)
	{
		//mlx_string_put(g->mlx, g->win, W_W / 2, W_H / 2, 0x444444, "Porte ouvertes");
		g->affCheck = 0;
	}
	if (!g->activateButton && !g->affCheck)
	{
		//mlx_string_put(g->mlx, g->win, W_W / 2, W_H / 2, 0x000000, "Portes fermees");
		g->affCheck = 0;
	}
	draw_minimap(g);
	if (g->key_LC == 0)
		create_hand_img(g->img, g->hand_1);
	else if (g->key_LC == 1 && g->key_RC == 0)
		create_hand_img(g->img, g->hand_3);
	else if (g->key_LC == 1 && g->key_RC == 1)
		create_hand_img(g->img, g->hand_2);
	create_crosshair(g->img, g->cross);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	//affTime(g);
}

void	recuStartPos(t_g *g)
{
	int	i;
	int	width;
	int	height;
	int	j;
	int	y;
	int	x;
	width = SIZE;
	height = SIZE;


	if (!g->aff1)
	{
	i = -1;
	y = 0;
	while (g->m.map[++i])
	{
		j = -1;
		x = 0;
		while (g->m.map[i][++j])
		{
			if (g->m.map[i][j] == 'N')
			{
				g->c.x = x + SIZE / 2;
				g->c.y = y + SIZE / 2;
				g->c.o = 0;
			}
			if (g->m.map[i][j] == 'S')
			{
				g->c.x = x + SIZE / 2;
				g->c.y = y + SIZE / 2;
				g->c.o = 180;
			}
			if (g->m.map[i][j] == 'W')
			{
				g->c.x = x + SIZE / 2;
				g->c.y = y + SIZE / 2;
				g->c.o = 270;
			}
			if (g->m.map[i][j] == 'E')
			{
				g->c.x = x + SIZE / 2;
				g->c.y = y + SIZE / 2;
				g->c.o = 90;
			}
			x += width;

		}
		y += height;
	}
	g->aff1 = 1;
	}
}
	/*i = 0;
	while (i <= W_W)
	{
		j = -1;
		while (++j < W_H)
		{
			my_mlx_pixel_put(img, i, j, 0x808080);
		}
		i += width;
	}
	i = 0;
	while (i <= W_H)
	{
		j = -1;
		while (++j < W_W)
		{
			my_mlx_pixel_put(img, j, i, 0x808080);
		}
		i += height;
	}
	mlx_put_image_to_window(g->mlx, g->win, img->img, 0, 0);*/

void	drawMinisol(t_g *g, int x, int y, int width, int height)
{
	int	to_go;
	int	to_g;
	int	i;
	(void)g;

	i = x;
	to_go = x + width;
	to_g = y + height;
	int j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			my_mlx_pixel_put(&g->img, i, j, 0x8ebbde);
			i++;
		}
		j++;
	}
}

void	drawMiniWall(t_g *g, double x, double y, double width, double height)
{
	double	to_go;
	double	to_g;
	double	i;
	(void)g;

	i = x;
	to_go = x + width;
	to_g = y + height;
	double	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			my_mlx_pixel_put(&g->img, i, j, 0x4c5057);
			i++;
		}
		j++;
	}
}

void	drawMiniPorte(t_g *g, double x, double y, double width, double height)
{
	double	to_go;
	double	to_g;
	double	i;
	(void)g;

	i = x;
	to_go = x + width;
	to_g = y + height;
	double	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			my_mlx_pixel_put(&g->img, i, j, 0x610000);
			i++;
		}
		j++;
	}
}

void	drawMiniButton(t_g *g, double x, double y, double width, double height)
{
	double	to_go;
	double	to_g;
	double	i;
	(void)g;

	i = x;
	to_go = x + width;
	to_g = y + height;
	double	j = y;
	while (j < to_g)
	{
		i = x;
		while (i < to_go)
		{
			my_mlx_pixel_put(&g->img, i, j, 0x045213);
			i++;
		}
		j++;
	}
}

void	drawMiniPlayer(t_g *g, double x, double y, double width, double height)
{
	double	i;
	double	j;
	double	to_go;
	double	to_g;

	//printf("X = %f, Y = %f\n", x, y);
	(void)g;
	to_go = x + width;
	to_g = y + height;
	i = y;
	while (i < to_g)
	{
		j = x;
		while (j < to_go)
		{
			my_mlx_pixel_put(&g->player, j, i, 0x000000);
			j++;
		}
		i++;
	}
	//mlx_put_image_to_window(g->mlx, g->mlx, &g->player.img, 0, 0);
}

void	draw_minimap(t_g *g)
{
	int	i;
	int	j;
	double	width;
	double	height;
	double	x;
	double	y;

	height = SIZE / 3;
	width = SIZE / 3;
	i = -1;
	y = 0;
	while (g->m.map[++i])
	{
		j = -1;
		x = 0;
		while (g->m.map[i][++j])
		{
			//if (j == (int)g->c.x / SIZE && i == (int)g->c.y / SIZE)
			//{
			//	printf ("x = %f, y = %f\n", x, y);
			//	drawMiniPlayer(g, (int)x, (int)y , 10, 10);
			//}
			if (g->m.map[i][j] == '1')
				drawMiniWall(g, y, x, width, height);
			else if (g->m.map[i][j] == 'P' && !g->activateButton)
				drawMiniPorte(g, y, x, width, height);
			else if (g->m.map[i][j] == 'B')
			{
				drawMiniButton(g, y, x, width, height);
			}
			else if (g->m.map[i][j] == '0' || g->m.map[i][j] == 'N' || g->m.map[i][j] == 'S'
				|| g->m.map[i][j] == 'E' || g->m.map[i][j] == 'W'
				|| (g->m.map[i][j]== 'P' && g->activateButton))
				drawMinisol(g, y, x, width, height);
			//printf("gX = %d, gY = %d\n", (int)g->c.x / (SIZE / 3), (int)g->c.y / (SIZE / 3));
			//printf("x = %f, y = %f\n", x , y);
			//printf("i = %d, j = %d\n", i, j);
		//	}
			x += width;
		}
		y += height;
	}
	//drawMiniPlayer(g);
}





void	draw_player(t_g *g, t_data *img, t_data *player)
{
	//int	i;
	//int	j;

	(void)player;
	(void)g;
	(void)img;
	/*j = -1;
	while (++j <= 9)
	{
		i = -1;
		while (++i <= 9)
			my_mlx_pixel_put(player, j, i, 0xfcdb35);
	}*/
	//printf ("player : x = %f, y = %f\n", g->c.x / SIZE, g->c.y / SIZE);
	//mlx_put_image_to_window(g->mlx, g->win, player->img, g->c.x, g->c.y);// - 4);
}

int	createRGB(t_g *g)
{
	return (g->m.c_r * 8 << 16 | g->m.c_g * 8 << 8 | g->m.c_b * 8);
}

int	createRGBsol(t_g *g)
{
	return (g->m.f_r * 8 << 16 | g->m.f_g * 8 << 8 | g->m.f_b * 8);
}

void	test_draw(t_g *g, t_data *img, t_data *player)
{
	(void)player;
	g->cielcolor = createRGB(g);
	g->solcolor = createRGBsol(g);
	
	int	y = 0;	
	int	x = 0;
	while (x < W_W)
	{
	//	x = y;
		y = 0;
		while (y < W_H)
		{
			if (y < W_H / 2)
				my_mlx_pixel_put(img, x, y, g->cielcolor);
			else
				my_mlx_pixel_put(img, x, y, g->solcolor);
			y++;
		}
		x++;
	}
	//draw_map(g, img);
}

int	mouseTracking(t_g *g)
{
	int	x = 0;
	int	y = 0;

	//mlx_mouse_move(g->mlx, g->win, W_W / 2, W_H / 2);
	//if (g->mouseHide)
	//	mlx_mouse_show(g->mlx, g->win);
	//if (!g->mouseHide)
	//{
		mlx_mouse_hide(g->mlx, g->win);
		mlx_mouse_get_pos(g->mlx, g->win, &x, &y);
		if(x > W_W / 2)
		{
			ft_keyPress(R, g);
			g->mouseR = 1;
		}
		if (x < W_W / 2)
		{
			ft_keyPress(L, g);
			g->mouseL = 1;
		}
		mlx_mouse_move(g->mlx, g->win, W_W / 2, W_W / 2);
	//}
	return (0);
}
int	start(t_g *g)
{
	ft_move(g);
	mouseTracking(g);
	return (0);
}

int	main(int ac, char **av)
{
	t_m	m;
	t_g	g;
	t_data	img;
	t_data	player;
	t_data	hand_1;
	t_data	hand_2;
	t_data	hand_3;
	t_data	cross;
	t_data	nord;
	t_data	sud;
	t_data	est;
	t_data	b;
	t_data	bc;
	t_data	d;
	t_data	ouest;
	int	i_h;
	int	i_w;

	init_struct_g(&g, ac, av);
	init_struct_m(&m);
	//g.s_x = 100;
	//g.s_y = 100;
	g.activateButton = 0;
	g.affCheck = 0;
	g.mouseHide = 1;
	g.key_W = 0;
	g.key_A = 0;
	g.key_S = 0;
	g.key_D = 0;
	g.key_O = 0;
	g.key_R = 0;
	g.key_L = 0;
	g.key_E = 0;
	g.key_LC = 0;
	g.key_RC = 0;
	g.DistButton = 999;
	g.startTime = 0;
	g.oldTime = 0;
	g.mouseR = 0;
	g.mouseL = 0;
	//g.m = m;
	g.FOVP = FOV * PI / 180;
	g.FOVD2 = (FOV / 2) * PI / 180;
	g.angle = 0;
	if (ac != 2)
		return (ft_errors(2), -1);
	if(!ft_parsing(&g))
		return(-1);
	g.mlx = mlx_init();
	if (!g.mlx)
		return (free_m(&g), ft_errors(3), -1);
	g.win = mlx_new_window(g.mlx, W_W, W_H, "cub3d");
	img.img = mlx_new_image(g.mlx, W_W, W_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	hand_1.img = mlx_xpm_file_to_image(g.mlx, "hand_1.xpm", &i_w, &i_h);
	hand_1.addr = mlx_get_data_addr(hand_1.img, &hand_1.bits_per_pixel, &hand_1.line_length, &hand_1.endian);
	hand_3.img = mlx_xpm_file_to_image(g.mlx, "hand_3.xpm", &i_w, &i_h);
	hand_3.addr = mlx_get_data_addr(hand_3.img, &hand_3.bits_per_pixel, &hand_3.line_length, &hand_3.endian);
	hand_2.img = mlx_xpm_file_to_image(g.mlx, "hand_2.xpm", &i_w, &i_h);
	hand_2.addr = mlx_get_data_addr(hand_2.img, &hand_2.bits_per_pixel, &hand_2.line_length, &hand_2.endian);
	nord.img = mlx_xpm_file_to_image(g.mlx, "N.xpm", &i_w, &i_h);
	nord.addr = mlx_get_data_addr(nord.img, &nord.bits_per_pixel, &nord.line_length, &nord.endian);
	sud.img = mlx_xpm_file_to_image(g.mlx, "S.xpm", &i_w, &i_h);
	sud.addr = mlx_get_data_addr(sud.img, &sud.bits_per_pixel, &sud.line_length, &sud.endian);
	ouest.img = mlx_xpm_file_to_image(g.mlx, "O.xpm", &i_w, &i_h);
	ouest.addr = mlx_get_data_addr(ouest.img, &ouest.bits_per_pixel, &ouest.line_length, &ouest.endian);
	est.img = mlx_xpm_file_to_image(g.mlx, "E.xpm", &i_w, &i_h);
	est.addr = mlx_get_data_addr(est.img, &est.bits_per_pixel, &est.line_length, &est.endian);
	d.img = mlx_xpm_file_to_image(g.mlx, "D.xpm", &i_w, &i_h);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, &d.endian);
	b.img = mlx_xpm_file_to_image(g.mlx, "B.xpm", &i_w, &i_h);
	b.addr = mlx_get_data_addr(b.img, &b.bits_per_pixel, &b.line_length, &b.endian);
	bc.img = mlx_xpm_file_to_image(g.mlx, "BC.xpm", &i_w, &i_h);
	bc.addr = mlx_get_data_addr(bc.img, &bc.bits_per_pixel, &bc.line_length, &bc.endian);
	est.img = mlx_xpm_file_to_image(g.mlx, "E.xpm", &i_w, &i_h);
	est.addr = mlx_get_data_addr(est.img, &est.bits_per_pixel, &est.line_length, &est.endian);
	cross.img = mlx_xpm_file_to_image(g.mlx, "crosshair.xpm", &i_w, &i_h);
	cross.addr = mlx_get_data_addr(cross.img, &cross.bits_per_pixel, &cross.line_length, &cross.endian);
	img.img = mlx_new_image(g.mlx, W_W, W_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	player.img = mlx_new_image(g.mlx, 9, 9);
	player.addr = mlx_get_data_addr(player.img, &player.bits_per_pixel, &player.line_length, &player.endian);
	g.img = img;
	g.hand_1 = hand_1;
	g.hand_2 = hand_2;
	g.hand_3 = hand_3;
	g.nord = nord;
	g.b = b;
	g.bc = bc;
	g.d = d;
	g.sud = sud;
	g.ouest = ouest;
	g.est = est;
	g.cross = cross;
	g.player = player;
	g.aff1 = 0;
	recuStartPos(&g);
	test_draw(&g, &img, &player);
	draw_map(&g);
	//mlx_put_image_to_window(g.mlx, g.win, img.img, 0, 0);
	g.c.xmini = g.c.x;
	g.c.ymini = g.c.y;
	mlx_mouse_move(g.mlx, g.win, W_W / 2, W_H / 2);
	mlx_loop_hook(g.mlx, start, &g);
	mlx_hook(g.win, 2, 1L << 0, ft_keyPress, &g);
	mlx_hook(g.win, 3, 1L << 1, ft_keyRelease, &g);
	mlx_hook(g.win, 17, 1L << 0, ft_key_cross, &g);
	//mlx_hook(g.win, 6, 1L << 6, mouseTracking, &g);
	mlx_loop(g.mlx);
	free_m(&g);
	return (0);
}
