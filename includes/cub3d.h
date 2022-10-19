/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 13:16:53 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <sys/time.h>

# include "structs.h"
# include "get_next_line.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

# define W_W 1000.0
# define W_H 700.0

# define W 119
# define A 97
# define S 115
# define D 100
# define E 101
# define O 111
# define LC 65362
# define RC 65364
# define CTRL 65507
# define SHIFT 65505
# define COLOR 0xFF00FF

# define R 65363
# define L 65361

# define ESC 65307

# define SIZE 64
# define SIZEF 64.0

# define FRAME
# define RAD_90 1.5708
# define RAD_180 3.14159
# define RAD_270 4.71239
# define RAD_360 6.28319
# define PI 3.14159265358979311600
# define FOV 50.0
# define SPEED 6.0
# define C_SPEED 8.0
# define WD_SPEED 8.0
# define R_SPEED 4.0
# define INF 10000000

/* ************************************************************************** */
/*          Parsing                                                           */

int	ft_parsing(t_g *g);
void	free_m(t_g *g);

/* ext_check.c */
char	*ft_strstr(char *str, char *to_find);
int	ft_check_file(char *str);
int	ft_check_extension(char *str);

/* map_verif.c */
int	map_verif(t_m *m);
int	check_empty_line(char **map);
int	check_for_invalid_char(char **map);
int	check_char(char c);
int	check_middle_line(char **map);
int	check_first_and_last_line(char **map);

/* ************************************************************************** */
/*          Raycasting                                                        */

int	check_next_pos_W(t_g *g, double angle);
int	check_next_pos_A(t_g *g, double angle);
int	check_next_pos_S(t_g *g, double angle);
int	check_next_pos_D(t_g *g, double angle);
int	ft_move(t_g *g);
int	ft_keyPress(int key, t_g *g);
int	ft_keyRelease(int key, t_g *g);
double	RayCalculator(t_g *g, double angle, double x, double y);

/* ************************************************************************** */
/*          Drawing                                                           */

void	draw_player(t_g *g, t_data *img, t_data *player);

/* ************************************************************************** */
/*          Tools                                                             */

/* str_tools.c */
int	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int	tab_len(char **tab);

/* errors.c */
void	ft_errors(int choice);

int	ft_atoi(const char *str);
char	*ft_itoa(int n);
void    draw_map(t_g *g);

#endif
