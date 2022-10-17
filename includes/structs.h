/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:36:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/17 12:54:22 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct	s_cord
{
	double	x;
	double	y;
	double	xmini;
	double	ymini;
	double	o;
}	t_c;

typedef struct	s_data 
{
    void	*img;
    char		*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}	t_data;

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int	f_r;
	int	f_g;
	int	f_b;
	int	c_r;
	int	c_g;
	int	c_b;
	char	**map;
}	t_m;

typedef struct s_rgb
{
	char	*recup_R;
	char	*recup_G;
	char	*recup_B;
}	t_rgb;

typedef struct s_global
{
	t_m	m;
	t_c	c;
	t_data	img;
	t_data	player;
	t_data	hand_1;
	t_data	hand_2;
	t_data	hand_3;
	t_data	cross;
	t_data	nord;
	void	*mlx;
	void	*win;
	int	ac;
	int	i;
	int	s_x;
	int	s_y;
	int	count;
	double	angle;
	double	angleX;
	double	angleY;
	double	Xangle0;
	double	Yangle0;
	double	FOVP;
	double	FOVD2;
	double	R_SPED;
	double	rayAngle;
	double	dir;
	double	dirX;
	double	dirY;
	double	oldX;
	double	oldY;
	int	solcolor;
	int	cielcolor;
	int	aff1;
	int	door;
	int	button;
	int	activateButton;
	double	DistButton;
	int	mouseHide;
	char	**av;
	int	key_A;
	int	key_W;
	int	key_D;
	int	key_S;
	int	key_L;
	int	key_R;
	int	key_E;
	int	key_O;
	int	key_RC;
	int	key_LC;
	int	mouseR;
	int	mouseL;
	int	affCheck;
	double	startTime;
	double	oldTime;
}	t_g;

#endif
