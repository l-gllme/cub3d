/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:52:15 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 16:52:49 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	recup_lines(char *file, char **recup)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, 0);
	if (fd == -1)
		return (ft_errors(4), 0);
	recup[i] = get_next_line(fd);
	while (recup[i])
	{
		i++;
		recup[i] = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	recup_direction(char **recup_gnl, t_g *g)
{
	int	i;
	int	j;

	i = 0;
	while (recup_gnl[i])
	{
		j = 0;
		while (recup_gnl[i][j])
		{
			if (recup_gnl[i][j] == 'N' && recup_gnl[i][j + 1] == 'O')
				if (!recup_no(recup_gnl, i, j + 2, g))
					return (0);
			if (recup_gnl[i][j] == 'S' && recup_gnl[i][j + 1] == 'O')
				if (!recup_so(recup_gnl, i, j + 2, g))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	recup_direction_2(char **recup_gnl, t_g *g)
{
	int	i;
	int	j;

	i = 0;
	while (recup_gnl[i])
	{
		j = 0;
		while (recup_gnl[i][j])
		{
			if (recup_gnl[i][j] == 'E' && recup_gnl[i][j + 1] == 'A')
				if (!recup_ea(recup_gnl, i, j + 2, g))
					return (0);
			if (recup_gnl[i][j] == 'W' && recup_gnl[i][j + 1] == 'E')
				if (!recup_we(recup_gnl, i, j + 2, g))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	recup_i_for_map_2(char **recup_gnl, int i, int j, t_g *g)
{
	if (recup_gnl[i][j] == 'N' && recup_gnl[i][j + 1] == 'O')
	{
		g->count += 1;
		g->i = i + 1;
	}
	else if (recup_gnl[i][j] == 'S' && recup_gnl[i][j + 1] == 'O')
	{
		g->count += 1;
		g->i = i + 1;
	}
	else if (recup_gnl[i][j] == 'F')
	{
		g->count += 1;
		g->i = i + 1;
	}
	else if (recup_gnl[i][j] == 'C')
	{
		g->count += 1;
		g->i = i + 1;
	}
}

void	recup_i_for_map(char **recup_gnl, t_g *g)
{
	int	i;
	int	j;

	i = 0;
	while (recup_gnl[i])
	{
		j = 0;
		while (recup_gnl[i][j])
		{
			if (recup_gnl[i][j] == 'E' && recup_gnl[i][j + 1] == 'A')
			{
				g->i = i + 1;
				g->count += 1;
			}
			else if (recup_gnl[i][j] == 'W' && recup_gnl[i][j + 1] == 'E')
			{
				g->count += 1;
				g->i = i + 1;
			}
			else
				recup_i_for_map_2(recup_gnl, i, j, g);
			j++;
		}
		i++;
	}
}
