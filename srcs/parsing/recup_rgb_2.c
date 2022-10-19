/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_rgb_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:39:40 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 16:39:58 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cut_rgb_floor(char **recup_gnl, int i, int j, t_rgb *rgb)
{
	int		k;

	while (recup_gnl[i][j] == ' ')
		j++;
	k = 0;
	while (recup_gnl[i][j] != ',')
		rgb->recup_R[k++] = recup_gnl[i][j++];
	rgb->recup_R[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != ',')
		rgb->recup_G[k++] = recup_gnl[i][j++];
	rgb->recup_G[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != '\n')
		rgb->recup_B[k++] = recup_gnl[i][j++];
	rgb->recup_B[k] = 0;
}

int	recup_rgb_floor(char **recup_gnl, int i, int j, t_g *g)
{
	t_rgb	rgb;

	init_struct_rgb(&rgb, recup_gnl, i, j);
	cut_rgb_floor(recup_gnl, i, j, &rgb);
	g->m.f_r = ft_atoi(rgb.recup_R);
	g->m.f_g = ft_atoi(rgb.recup_G);
	g->m.f_b = ft_atoi(rgb.recup_B);
	if (!check_rgb_value_2(&rgb))
		return (ft_free_struct_rgb(&rgb), 0);
	return (ft_free_struct_rgb(&rgb), 1);
}

static void	cut_rgb_ciel(char **recup_gnl, int i, int j, t_rgb *rgb)
{
	int	k;

	k = 0;
	while (recup_gnl[i][j] != ',')
		rgb->recup_R[k++] = recup_gnl[i][j++];
	rgb->recup_R[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != ',')
		rgb->recup_G[k++] = recup_gnl[i][j++];
	rgb->recup_G[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != '\n')
		rgb->recup_B[k++] = recup_gnl[i][j++];
	rgb->recup_B[k] = 0;
}

int	recup_rgb_ciel(char **recup_gnl, int i, int j, t_g *g)
{
	t_rgb	rgb;
	int		k;

	k = j;
	init_struct_rgb(&rgb, recup_gnl, i, j);
	while (recup_gnl[i][k] == ' ')
		k++;
	if (j == k)
		return (0);
	j = k;
	if (j < 1)
		exit(0);
	cut_rgb_ciel(recup_gnl, i, j, &rgb);
	g->m.c_r = ft_atoi(rgb.recup_R);
	g->m.c_g = ft_atoi(rgb.recup_G);
	g->m.c_b = ft_atoi(rgb.recup_B);
	if (!check_rgb_value_2(&rgb))
		return (ft_free_struct_rgb(&rgb), 0);
	return (ft_free_struct_rgb(&rgb), 1);
}
