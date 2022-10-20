/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tool.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:42:42 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/20 15:18:09 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_m(t_g *g)
{
	free_char_tab(g->m.map);
	free(g->m.so_texture);
	free(g->m.no_texture);
	free(g->m.ea_texture);
	free(g->m.we_texture);
}

void	print_info(t_g *g)
{
	int	i;

	i = 0;
	printf("=== Elements ===\n\n");
	printf ("NO %s\n", g->m.no_texture);
	printf ("SO %s\n", g->m.so_texture);
	printf ("EA %s\n", g->m.ea_texture);
	printf ("WE %s\n\n", g->m.we_texture);
	printf ("F %d,%d,%d\n", g->m.f_r, g->m.f_g, g->m.f_b);
	printf ("C %d,%d,%d\n", g->m.c_r, g->m.c_g, g->m.c_b);
	printf("\n=== Map ===\n\n");
	while (g->m.map[i])
	{
		printf ("%s", g->m.map[i]);
		i++;
	}
}

int	check_open_asset(t_m *m)
{
	if (open("imgs", O_DIRECTORY) < 0)
		return (0);
	if (!m->no_texture)
		return (0);
	if (open(m->no_texture + 1, O_RDONLY) < 0)
		return (0);
	if (!m->so_texture)
		return (0);
	if (open(m->so_texture + 1, O_RDONLY) < 0)
		return (0);
	if (!m->ea_texture)
		return (0);
	if (open(m->ea_texture + 1, O_RDONLY) < 0)
		return (0);
	if (!m->we_texture)
		return (0);
	if (open(m->we_texture + 1, O_RDONLY) < 0)
		return (0);
	return (1);
}

int	recup_malloc(char **recup_gnl, int i, int j)
{
	int	c;

	c = 0;
	while (recup_gnl[i][j] != ',')
	{
		c++;
		j++;
	}
	return (c);
}

int	count_lines(char *file)
{
	char	*line;
	int		line_count;
	int		fd;

	fd = open(file, 0);
	if (fd == -1)
		return (ft_errors(4), 0);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}
