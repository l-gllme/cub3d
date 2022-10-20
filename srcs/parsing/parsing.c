/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:17:29 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/20 15:21:24 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	recup_map(char **recup_gnl, t_g *g)
{
	int	k;
	int	c;

	c = 0;
	k = g->i;
	while (recup_gnl[k] && recup_gnl[++k])
		c++;
	g->m.map = malloc(sizeof(char *) * (c + 2));
	if (!g->m.map)
		return (0);
	k = g->i;
	while (recup_gnl[k] && recup_gnl[k + 1] && recup_gnl[++k][0] == '\n')
		g->i = k;
	k = g->i;
	c = 0;
	while (recup_gnl[k] && recup_gnl[++k])
	{
		g->m.map[c] = ft_strdup(recup_gnl[k]);
		c++;
	}
	g->m.map[c] = 0;
	return (1);
}

static int	pars_error(char **recup_gnl, t_g *g)
{
	if (!recup_rgb(recup_gnl, g) || !recup_direction(recup_gnl, g)
		|| !recup_direction_2(recup_gnl, g))
	{
		return (free_char_tab(recup_gnl), ft_errors(6),
			ft_putstr_fd("failed to load elements\n", 2), 0);
	}
	if (!check_rgb_value(g))
	{
		return (free_char_tab(recup_gnl), ft_errors(6),
			ft_putstr_fd("bad rgb value\n", 2), 0);
	}
	return (1);
}

static void	f_p(t_g *g)
{
	free(g->m.no_texture);
	free(g->m.so_texture);
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
	if (!pars_error(recup_gnl, g))
		return (0);
	recup_i_for_map(recup_gnl, g);
	if (g->count > 6 || !check_open_asset(&g->m))
		return (free_char_tab(recup_gnl), f_p(g), ft_errors(6),
			ft_putstr_fd("too much elemets/bad assets\n", 2), 0);
	if (!recup_map(recup_gnl, g))
		return (0);
	if (!map_verif(&g->m))
		return (free_m(g), free_char_tab(recup_gnl), 0);
	free_char_tab(recup_gnl);
	complete_map(g);
	return (1);
}
