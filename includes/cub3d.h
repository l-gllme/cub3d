/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:22 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/20 11:34:07 by jtaravel         ###   ########.fr       */
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

int		ft_parsing(t_g *g);
void	free_m(t_g *g);
void	init_struct_g(t_g *g, int ac, char **av);
void	init_struct_m(t_m *m);
void	recustartpos(t_g *g);
void	init_wall_textures(t_g *g);
void	init_bonus_textures(t_data hand_1, t_data hand_2,
			t_data hand_3, t_g *g);
void	init_bonus_textures_2(t_data b, t_data bc, t_data d, t_g *g);
void	init_bonus_textures_3(t_data cross, t_data img, t_g *g);
int		creatergb(t_g *g);
int		creatergbsol(t_g *g);
void	recuprgb(t_g *g);

/* ext_check.c */
char	*ft_strstr(char *str, char *to_find);
int		ft_check_file(char *str);
int		ft_check_extension(char *str);

/* map_verif.c */
int		map_verif(t_m *m);
int		check_for_invalid_char(char **map, int i, int j);
int		check_char(char c);
int		check_middle_line(char **map, int i, int j);
int		check_first_and_last_line(char **map);

/* recup_path.c */
int		recup_no(char **recup_gnl, int i, int j, t_g *g);
int		recup_ea(char **recup_gnl, int i, int j, t_g *g);
int		recup_we(char **recup_gnl, int i, int j, t_g *g);
int		recup_so(char **recup_gnl, int i, int j, t_g *g);

/* recup_rgb.c */
void	init_struct_rgb(t_rgb *rgb, char **recup_gnl, int i, int j);
void	ft_free_struct_rgb(t_rgb *rgb);
int		check_rgb_value_2(t_rgb *rgb);
int		recup_rgb(char **recup_gnl, t_g *g);
int		check_rgb_value(t_g *g);

/* recup_rgb_2.c */
int		recup_rgb_ciel(char **recup_gnl, int i, int j, t_g *g);
int		recup_rgb_floor(char **recup_gnl, int i, int j, t_g *g);

/* p_tool.c */
int		recup_malloc(char **recup_gnl, int i, int j);
int		count_lines(char *file);
void	free_m(t_g *g);
void	print_info(t_g *g);
int		check_open_asset(t_m *m);

/* p_tool_2.c */
int		check_empty_line(char **map);
void	complete_map(t_g *g);
char	*ft_strdup(char *s);
void	free_char_tab(char **s);

/* recups.c */
void	recup_i_for_map(char **recup_gnl, t_g *g);
void	recup_i_for_map_2(char **recup_gnl, int i, int j, t_g *g);
int		recup_direction_2(char **recup_gnl, t_g *g);
int		recup_direction(char **recup_gnl, t_g *g);
int		recup_lines(char *file, char **recup);
int		open_img_64(t_g *g, t_data *img, char *path);

/* ************************************************************************** */
/*          Raycasting                                                        */

int		check_next_pos_w(t_g *g, double angle);
int		check_next_pos_a(t_g *g, double angle);
int		check_next_pos_s(t_g *g, double angle);
int		check_next_pos_d(t_g *g, double angle);
int		ft_move(t_g *g);
int		ft_keypress(int key, t_g *g);
int		ft_keyrelease(int key, t_g *g);
double	ray_calculator(t_g *g, double angle, double x, double y);
double	ray_calculator_while(t_g *g, double angle, double d);

/* ************************************************************************** */
/*          Drawing                                                           */

void	draw_player(t_g *g, t_data *img, t_data *player);
void	draw_minimap(t_g *g);
void	drawminibutton(t_g *g, double x, double y, double width);
void	drawminiporte(t_g *g, double x, double y, double width);
void	drawminibreak(t_g *g, double x, double y, double width);
void	drawminiwall(t_g *g, double x, double y, double width);
void	drawminisol(t_g *g, int x, int y, int width);
void	pp(t_data *data, double x, double y, int color);
int		gp(int x, int y, t_data i);
void	drawrow1(t_g *g, t_data *img, double i, double d);
void	draw_row(t_g *g, t_data *img, double y, double height);
void	displaypix(t_g *g, double y, double j, double ciel);
int		mousetracking(t_g *g);
void	afftime(t_g *g);
void	create_crosshair(t_data img, t_data h);

/* pistol_anim.c */

void	pistol_anim(t_g *g);

/* ************************************************************************** */
/*          Tools                                                             */

void	pp(t_data *data, double x, double y, int color);
int		get_pixel_2(int x, int y, t_data *i);
void	checkposexit(t_g *g);
int		ft_key_cross(t_g *g);

/* str_tools.c */
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int		tab_len(char **tab);

/* errors.c */
void	ft_errors(int choice);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	draw_map(t_g *g);
void	free_all(t_g *g);

#endif
