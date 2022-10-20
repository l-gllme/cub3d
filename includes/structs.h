/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:36:44 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/20 11:28:22 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cord
{
	double	x;
	double	y;
	double	xmini;
	double	ymini;
	double	o;
}	t_c;

typedef struct s_data
{	
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	char	**map;
}	t_m;

typedef struct s_rgb
{
	char	*recup_r;
	char	*recup_g;
	char	*recup_b;
}	t_rgb;

typedef struct s_global
{
	t_m		m;
	t_c		c;
	t_data	img;
	t_data	player;
	t_data	hand_1;
	t_data	hand_2;
	t_data	hand_3;
	t_data	hand_4;
	t_data	hand_5;
	t_data	cross;
	t_data	nord;
	t_data	sud;
	t_data	est;
	t_data	ouest;
	t_data	d;
	t_data	b;
	t_data	bc;
	t_data	w_1;
	t_data	w_2;
	t_data	exit;
	void	*mlx;
	void	*win;
	int		ac;
	int		i;
	int		w_1check;
	int		w_2check;
	int		s_x;
	int		s_y;
	int		count;
	double	actuheight;
	double	angle;
	double	fovp;
	double	fovd2;
	double	rayangle;
	double	dir;
	double	dirx;
	double	diry;
	int		solcolor;
	int		cielcolor;
	int		aff1;
	int		door;
	int		button;
	int		activatebutton;
	double	distbutton;
	char	**av;
	int		key_a;
	int		key_w;
	int		key_d;
	int		key_s;
	int		key_l;
	int		key_r;
	int		key_e;
	int		key_o;
	int		key_rc;
	int		key_lc;
	int		key_ctrl;
	int		key_shift;
	int		s_m;
	int		button_left;
	int		button_right;
	int		mouser;
	int		mousel;
	int		exitcheck;
	int		affcheck;
	double	starttime;
	double	oldtime;
	double	xold;
	double	yold;
	double	tmpx;
	double	tmpy;
	double	cosa;
	double	sina;
	double	xmap;
	double	ymap;
	int		anim;
}	t_g;

#endif
