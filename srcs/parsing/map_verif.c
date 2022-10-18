/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:54:45 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/18 14:57:51 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_first_and_last_line(char **map)
{
	int	i;

	i = -1;
	while (map[0][++i])
	{
		if (check_char(map[0][i]) == 1)
			return (0);
	}
	i = -1;
	while (map[tab_len(map) - 1][++i])
	{
		if (check_char(map[tab_len(map) - 1][i]) == 1)
			return (0);
	}
	return (1);
}

int	check_middle_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < tab_len(map) - 1)
	{
		j = ft_strlen(map[i]) - 2;
		if (map[i][j] != '1' &&  map[i][j] != ' ')
			return (0);
		j = 0;
		if (map[i][j] != '1' &&  map[i][j] != ' ')
			return (0);
		j = 0;
		while (map[i][++j])
		{
			if (check_char(map[i][j]) == 1)
			{
				if (!map[i - 1][j] || map[i - 1][j] == ' ' || map[i + -1][j] == '\n')
					return (0);
				if (!map[i + 1][j] || map[i + 1][j] == ' ' || map[i + 1][j] == '\n')
					return (0);
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

int	check_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == 'P'
		|| c == 'B' || c == 'X')
		return (1);
	if (c == '1' || c == 'M' || c == 'H')
		return (2);
	if (c == ' ')
		return (3);
	return (0);
}

int	check_for_invalid_char(char **map)
{
	int	i;
	int	j;
	int	count_special_char;

	i = -1;
	count_special_char = 0;
	while (map[++i])
	{
		j = -1;
		while (++j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				count_special_char++;
				if (count_special_char > 1)
					return (0);
			}
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != 'P' && map[i][j] != 'B' && map[i][j] == 'M' && map[i][j] == 'X' && map[i][j] == 'H')
				return (0);
		}
	}
	if (count_special_char == 0)
		return (0);
	return (1);
}

int	check_empty_line(char **map)
{
	int	i;
	
	i = -1;
	while (map[++i])
	{
		if (map[i][0] == '\n')
			return (0);
	}
	return (1);
}

int	map_verif(t_m *m)
{
	if (tab_len(m->map) < 3)
		return (ft_errors(0), ft_putstr_fd("cub3d: invalid map\n", 2), 0);
	if (!check_empty_line(m->map))
		return (ft_errors(0), ft_putstr_fd("cub3d: invalid map: empty line\n", 2), 0);
	if (!check_for_invalid_char(m->map))	
		return (ft_errors(5), 0);
	if (!check_first_and_last_line(m->map))
		return (ft_errors(0), ft_putstr_fd("cub3d: invalid map (first/last line)\n", 2), 0);
	if (!check_middle_line(m->map))
		return (ft_errors(0), ft_putstr_fd("cub3d: invalid map (middle lines)\n", 2), 0);
	return (1);
}
