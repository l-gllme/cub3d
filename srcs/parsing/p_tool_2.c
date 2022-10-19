/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tool_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:48:18 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 16:49:56 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_char_tab(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i])
			free(s[i]);
		i++;
	}
	free(s);
}

char	*ft_strdup(char *s)
{
	char	*cpy;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!cpy)
		return (0);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

void	complete_map(t_g *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->m.map[i])
	{
		j = 0;
		while (g->m.map[i][j])
		{
			if (g->m.map[i][j] == ' ')
				g->m.map[i][j] = 'M';
			if (g->m.map[i][j] == '\n')
				g->m.map[i][j] = 'M';
			j++;
		}
		i++;
	}
	g->m.map[i] = ft_strdup(g->m.map[i - 1]);
	g->m.map[i + 1] = 0;
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
