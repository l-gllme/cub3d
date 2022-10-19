/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:38:50 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 16:39:22 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_rgb(t_rgb *rgb, char **recup_gnl, int i, int j)
{
	int	c;

	c = recup_malloc(recup_gnl, i, j);
	rgb->recup_R = malloc(sizeof(char) * (c + 1));
	c = recup_malloc(recup_gnl, i, j + c + 1);
	rgb->recup_G = malloc(sizeof(char) * (c + 1));
	c = recup_malloc(recup_gnl, i, j + c + 1);
	rgb->recup_B = malloc(sizeof(char) * (c + 5));
}

void	ft_free_struct_rgb(t_rgb *rgb)
{
	if (rgb->recup_R)
	{
		free(rgb->recup_R);
		rgb->recup_R = NULL;
	}
	if (rgb->recup_G)
	{
		free(rgb->recup_G);
		rgb->recup_G = NULL;
	}
	if (rgb->recup_B)
	{
		free(rgb->recup_B);
		rgb->recup_B = NULL;
	}
}

int	check_rgb_value_2(t_rgb *rgb)
{
	if (ft_strlen(rgb->recup_R) > 3)
		return (0);
	if (ft_strlen(rgb->recup_G) > 3)
		return (0);
	if (ft_strlen(rgb->recup_B) > 3)
		return (0);
	return (1);
}

int	recup_rgb(char **recup_gnl, t_g *g)
{
	int	i;
	int	j;

	i = 0;
	while (recup_gnl[i])
	{
		j = 0;
		while (recup_gnl[i][j])
		{
			if (recup_gnl[i][j] == 'F')
				if (!recup_rgb_floor(recup_gnl, i, j + 1, g))
					return (0);
			if (recup_gnl[i][j] == 'C')
				if (!recup_rgb_ciel(recup_gnl, i, j + 1, g))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rgb_value(t_g *g)
{
	if (g->m.f_r < 0 || g->m.f_r > 255)
		return (0);
	if (g->m.f_g < 0 || g->m.f_g > 255)
		return (0);
	if (g->m.f_b < 0 || g->m.f_b > 255)
		return (0);
	if (g->m.c_r < 0 || g->m.c_r > 255)
		return (0);
	if (g->m.c_g < 0 || g->m.c_g > 255)
		return (0);
	if (g->m.c_b < 0 || g->m.c_b > 255)
		return (0);
	return (1);
}
