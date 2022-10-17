/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:17:29 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/17 21:02:10 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *file)
{
	int	line_count;
	char	*line;
	int	fd;

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

int	check_RGB_value_2(t_rgb *rgb)
{

	if (ft_strlen(rgb->recup_R) > 3)
		return (0);
	if (ft_strlen(rgb->recup_G) > 3)
		return (0);
	if (ft_strlen(rgb->recup_B) > 3)
		return (0);
	return (1);
}


int	recup_RGB_floor(char **recup_gnl, int i, int j, t_g *g)
{
	t_rgb	rgb;
	int	k;
	
	init_struct_rgb(&rgb, recup_gnl, i, j);
	while (recup_gnl[i][j] == ' ')
		j++;
	k = 0;
	while (recup_gnl[i][j] != ',')
		rgb.recup_R[k++] = recup_gnl[i][j++];
	rgb.recup_R[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != ',')
		rgb.recup_G[k++] = recup_gnl[i][j++];
	rgb.recup_G[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != '\n')
		rgb.recup_B[k++] = recup_gnl[i][j++];
	rgb.recup_B[k] = 0;
	g->m.f_r = ft_atoi(rgb.recup_R);
	g->m.f_g = ft_atoi(rgb.recup_G);
	g->m.f_b = ft_atoi(rgb.recup_B);
	if (!check_RGB_value_2(&rgb))
		return (ft_free_struct_rgb(&rgb), 0);
	return (ft_free_struct_rgb(&rgb), 1);
}

int	recup_RGB_ciel(char **recup_gnl, int i, int j, t_g *g)
{
	t_rgb	rgb;
	int	k;
	
	k = j;
	init_struct_rgb(&rgb, recup_gnl, i, j);
	while (recup_gnl[i][k] == ' ')
		k++;
	if (j == k)
		return (0);
	j = k;
	k = 0;
	if (j < 1)
		exit(0);
	while (recup_gnl[i][j] != ',')
		rgb.recup_R[k++] = recup_gnl[i][j++];
	rgb.recup_R[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != ',')
		rgb.recup_G[k++] = recup_gnl[i][j++];
	rgb.recup_G[k] = 0;
	k = 0;
	j++;
	while (recup_gnl[i][j] != '\n')
		rgb.recup_B[k++] = recup_gnl[i][j++];
	rgb.recup_B[k] = 0;
	g->m.c_r = ft_atoi(rgb.recup_R);
	g->m.c_g = ft_atoi(rgb.recup_G);
	g->m.c_b = ft_atoi(rgb.recup_B);
	if (!check_RGB_value_2(&rgb))
		return (ft_free_struct_rgb(&rgb), 0);
	return (ft_free_struct_rgb(&rgb), 1);
}

int	recup_RGB(char **recup_gnl, t_g *g)
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
				if (!recup_RGB_floor(recup_gnl, i, j + 1, g))
					return (0);
			if (recup_gnl[i][j] == 'C')
				if (!recup_RGB_ciel(recup_gnl, i, j + 1, g))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_RGB_value(t_g *g)
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

int	recup_NO(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.no_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.no_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.no_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.no_texture[c] = 0;
	return (1);
}

int	recup_EA(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.ea_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.ea_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.ea_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.ea_texture[c] = 0;
	return (1);
}

int	recup_WE(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.we_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.we_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.we_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.we_texture[c] = 0;
	return (1);
}

int	recup_SO(char **recup_gnl, int i, int j, t_g *g)
{
	int	k;
	int	c;

	k = j;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		j++;
		c++;
	}
	g->m.so_texture = malloc(sizeof(char) * (c + 1));
	if (!g->m.so_texture)
		return (0);
	j = k;
	c = 0;
	while (recup_gnl[i][j] != '\n')
	{
		g->m.so_texture[c] = recup_gnl[i][j];
		c++;
		j++;
	}
	g->m.so_texture[c] = 0;
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
				if (!recup_NO(recup_gnl, i, j + 2, g))
					return (0);
			if (recup_gnl[i][j] == 'S' && recup_gnl[i][j + 1] == 'O')
				if (!recup_SO(recup_gnl, i, j + 2, g))
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
				if (!recup_EA(recup_gnl, i, j + 2, g))
					return (0);
			if (recup_gnl[i][j] == 'W' && recup_gnl[i][j + 1] == 'E')
				if (!recup_WE(recup_gnl, i, j + 2, g))
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

void	completeMAP(t_g *g)
{
	int i;
	int j;

	i = 0;
	while (g->m.map[i])
	{
		j = 0;
		while (g->m.map[i][j])
		{
			if (g->m.map[i][j] == ' ')
				g->m.map[i][j] = 'M';
			j++;
		}
		i++;
	}
}


int	recup_map(char **recup_gnl, t_g *g)
{
	int	k;
	int	c;

	c = 0;
	k = g->i;
	while (recup_gnl[++k])
		c++;
	g->m.map = malloc(sizeof(char *) * (c + 1));
	if (!g->m.map)
		return (0);
	k = g->i;
	while (recup_gnl[k + 1] && recup_gnl[++k][0] == '\n')
		g->i = k;
	k = g->i;
	c = 0;
	while (recup_gnl[++k])
	{
		g->m.map[c] = ft_strdup(recup_gnl[k]);
		c++;
	}
	g->m.map[c] = 0;
	return (1);
}

int	check_open_asset(t_m *m)
{
	if (open("imgs", O_DIRECTORY) < 0)
		return (0);
	if (open(m->no_texture + 1, O_RDONLY) < 0)
		return (0);
	if (open(m->so_texture + 1, O_RDONLY) < 0)
		return (0);
	if (open(m->ea_texture + 1, O_RDONLY) < 0)
		return (0);
	if (open(m->we_texture + 1, O_RDONLY) < 0)
		return (0);
	return (1);
}

void	print_info(t_g *g)
{
	int	i = 0;

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

void	free_m(t_g *g)
{
	free_char_tab(g->m.map);
	free(g->m.so_texture);
	free(g->m.no_texture);
	free(g->m.ea_texture);
	free(g->m.we_texture);
}

int	ft_parsing(t_g *g)
{
	char	**recup_gnl;

	if (!ft_check_extension(g->av[1]))
		return (ft_errors(1), 0);
	recup_gnl = malloc(sizeof(char *) * (count_lines(g->av[1]) + 1));
	if (!recup_gnl)
		return (ft_errors(0), 0);
	recup_lines(g->av[1], recup_gnl);
	if(!recup_RGB(recup_gnl, g) || !recup_direction(recup_gnl, g) || !recup_direction_2(recup_gnl, g))
		return (free_char_tab(recup_gnl), ft_errors(6), ft_putstr_fd("failed to load elements\n", 2), 0);
	if (!check_RGB_value(g))
		return (free_char_tab(recup_gnl), ft_errors(6),ft_putstr_fd("bad rgb value\n", 2), 0);
	recup_i_for_map(recup_gnl, g);
	if (g->count > 6 || !check_open_asset(&g->m))
		return (free_char_tab(recup_gnl), ft_errors(6), ft_putstr_fd("too much elemets/bad assets\n", 2), 0);
	if (!recup_map(recup_gnl, g))
		return (0);
	if (!map_verif(&g->m))
		return (free_m(g), free_char_tab(recup_gnl), 0);
	print_info(g);
	free_char_tab(recup_gnl);
	completeMAP(g);
	return (1);
}
