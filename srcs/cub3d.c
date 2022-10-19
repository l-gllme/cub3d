/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:42:06 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 16:28:21 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	CheckPosExit(t_g *g);


void	init_struct_g(t_g *g, int ac, char **av)
{
	g->ac = ac;
	g->av = av;
	g->count = 0;
	g->i = 0;
	g->anim = 0;
	g->activateButton = 0;
	g->affCheck = 0;
	g->mouseHide = 1;
	g->key_W = 0;
	g->key_A = 0;
	g->key_S = 0;
	g->key_D = 0;
	g->key_O = 0;
	g->key_R = 0;
	g->key_L = 0;
	g->key_E = 0;
	g->key_LC = 0;
	g->key_RC = 0;
	g->DistButton = 999;
	g->startTime = 0;
	g->oldTime = 0;
	g->mouseR = 0;
	g->mouseL = 0;
	g->FOVP = FOV * PI / 180;
	g->FOVD2 = (FOV / 2) * PI / 180;
	g->angle = 0;
	g->tmpX = 0;
	g->tmpY = 0;
	g->xOld = 0;
	g->yOld = 0;
	g->xmap = 0;
	g->ymap = 0;
}

void	init_struct_m(t_m *m)
{
	m->map = NULL;
	m->no_texture = NULL;
	m->so_texture = NULL;
	m->ea_texture = NULL;
	m->we_texture = NULL;
}

int	ft_key_cross(t_g *g)
{
	(void)g;
	printf("Fermeture de la fenetre...");
	exit(0);
}

void	free_all(t_g *g)
{
	mlx_destroy_image(g->mlx, g->ouest.img);
	mlx_destroy_image(g->mlx, g->nord.img);
	mlx_destroy_image(g->mlx, g->sud.img);
	mlx_destroy_image(g->mlx, g->est.img);
	mlx_destroy_image(g->mlx, g->bc.img);
	mlx_destroy_image(g->mlx, g->b.img);
	mlx_destroy_image(g->mlx, g->d.img);
	mlx_destroy_image(g->mlx, g->hand_1.img);
	mlx_destroy_image(g->mlx, g->hand_2.img);
	mlx_destroy_image(g->mlx, g->hand_3.img);
	mlx_destroy_image(g->mlx, g->cross.img);
	mlx_destroy_image(g->mlx, g->img.img);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	int	i = -1;
	while (g->m.map[++i])
		free(g->m.map[i]);
	free(g->m.map);
	free(g->m.no_texture);
	free(g->m.so_texture);
	free(g->m.ea_texture);
	free(g->m.we_texture);
}

int	mouseTracking(t_g *g);
void	drawMiniPlayer(t_g *g, double x, double y, double width, double height);

void     pp(t_data *data, double x, double y, int color);

void	 pp(t_data *data, double x, double y, int color)
{
	char	*dst;

	dst = data->addr + (int)(((double)y * data->line_length + (double)x * (data->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}

int    get_pixel(int x, int y, t_data i)
{
	char	*ret;

	ret = i.addr + (y * i.line_length + x * (i.bits_per_pixel / 8));
	return (*(unsigned int *)ret);
}


void	DisplayPix_2(t_g *g, double y, double j, double ciel)
{
	double	height;
	double	t;
	
	height = g->ActuHeight;
	t = (j - ciel) * (SIZEF / height);
	if (g->button == 1 && g->dir == 3 && g->activateButton)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirX, SIZEF), t, g->bc));
	else if (g->button == 1 && g->dir == 4 && g->activateButton)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirX, SIZEF), t, g->bc));
	else if (g->w_1check == 1 && g->dir == 1)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirY, SIZEF), t, g->w_1));
	else if (g->w_1check == 1 && g->dir == 2)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirY, SIZEF), t, g->w_1));
	else if (g->w_1check == 1 && g->dir == 3)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirX, SIZEF), t, g->w_1));
	else if (g->w_1check == 1 && g->dir == 4)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirX, SIZEF), t, g->w_1));
	else if (g->w_2check == 1 && g->dir == 1)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirY, SIZEF), t, g->w_2));
	else if (g->w_2check == 1 && g->dir == 2)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirY, SIZEF), t, g->w_2));
	else if (g->w_2check == 1 && g->dir == 3)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirX, SIZEF), t, g->w_2));
	else if (g->w_2check == 1 && g->dir == 4)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirX, SIZEF), t, g->w_2));
	else if (g->dir == 1 && g->exitcheck)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirY, SIZEF), t, g->exit));
	else if (g->dir == 2 && g->exitcheck)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirY, SIZEF), t, g->exit));
	else if (g->dir == 3 && g->exitcheck)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirX, SIZEF) , t, g->exit));
	else if (g->dir == 4 && g->exitcheck)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirX, SIZEF), t, g->exit));
	else if (g->dir == 1)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirY, SIZEF), t, g->est));
	else if (g->dir == 2)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirY, SIZEF), t, g->ouest));
	else if (g->dir == 3)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirX, SIZEF) , t, g->sud));
	else if (g->dir == 4 && !g->w_1check && !g->w_2check)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirX, SIZEF), t, g->nord));

}

void	DisplayPix(t_g *g, double y, double j, double ciel)
{
	double	height;
	double		t;
	
	height = g->ActuHeight;
	t = (j - ciel) * (SIZEF / height);
	if (g->door == 1 && !g->activateButton && g->dir == 3)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirX, SIZEF), t, g->d));
	else if (g->door == 1 && !g->activateButton && g->dir == 4)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirX, SIZEF), t, g->d));
	else if (g->door == 1 && !g->activateButton && g->dir == 1)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirY, SIZEF), t, g->d));
	else if (g->door == 1 && !g->activateButton && g->dir == 2)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirY, SIZEF), t, g->d));
	else if (g->button == 1 && g->dir == 1 && !g->activateButton)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirY, SIZEF), t, g->b));
	else if (g->button == 1 && g->dir == 2 && !g->activateButton)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirY, SIZEF), t, g->b));
	else if (g->button == 1 && g->dir == 3 && !g->activateButton)
		 pp(&g->img, y, j, get_pixel(SIZE - (int)fmod(g->dirX, SIZEF), t, g->b));
	else if (g->button == 1 && g->dir == 4 && !g->activateButton)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirX, SIZEF), t, g->b));
	else if (g->button == 1 && g->dir == 1 && g->activateButton)
		 pp(&g->img, y, j, get_pixel((int)fmod(g->dirY, SIZEF), t, g->bc));
	else if (g->button == 1 && g->dir == 2 && g->activateButton)
		 pp(&g->img, y, j, get_pixel(SIZE -(int)fmod(g->dirY, SIZEF), t, g->bc));
	else
		DisplayPix_2(g, y, j, ciel);
}

void	draw_row(t_g *g, t_data *img, double y, double height)
{
	double j;
	double	ciel;
	double floor1;

	g->ActuHeight = height;
	ciel =  (W_H / 2) - (height / 2);
	floor1 = (W_H / 2) + (height / 2);
	j = -1;
	while (++j < W_H)
	{
		if (j < ciel)
			 pp(img, y, j, g->cielcolor);
		else if (j > floor1)
			 pp(img, y, j, g->solcolor);
		else
			DisplayPix(g, y, j, ciel);
	}
}

void	drawRow1(t_g *g, t_data *img, double x, double y)
{
	double	d;
	double	wallDist;
	double	height = 0.0;
	double	fix;
	(void)y;
	(void)x;
	double i = 0;
	double Pi = 2 * PI;

	while (i < W_W)
	{
		d = (double)((g->FOVP / (W_W - 1) * i) + (double)((double)g->angle - (double)g->FOVD2));
		if (d < 0)
			d+= 360 * PI / 180;
		fix = g->angle - d;
		if (fix < 0)
			fix += Pi;
		else if (fix > Pi)
			fix -= Pi;
		g->rayAngle = d;
		wallDist = ray_calculator(g, d, g->c.x, g->c.y) * cos(fix);
		height = 55000 / wallDist;
		draw_row(g, img, i, height);
		i++;
	}
}

void	drawLineTEST(t_g *g, t_data *img, double x, double y)
{
	while (x < W_W)
	{
		while (y < W_H)
		{
			 pp(img, x, y, g->cielcolor);
			y++;
		}
		x++;
	}
}

long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

long long	ft_currentTime(t_g *g)
{
	return ((get_time() - g->startTime));
}

void	affTime(t_g *g)
{
	char		*temp;
	u_int64_t	time;
	double		frame;

	time = get_time() - g->startTime;
	frame = (time - g->oldTime) / 1000.0;
	temp = ft_itoa((int)(1 / frame));
	g->oldTime = time;
	mlx_string_put(g->mlx, g->win, W_W - 50, 25, 0x444444, temp);
	mlx_string_put(g->mlx, g->win, W_W - 35, 25, 0x444444, "FPS");
	free(temp);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	get_pixel_2(int x, int y, t_data *i)
{
	char	*ret;

	ret = i->addr + (y * i->line_length + x * (i->bits_per_pixel / 8));
	return (*(unsigned int*)ret);
}

void	create_crosshair(t_data img, t_data h)
{
	int	i = -1;
	int	j = -1;
	int	i_w;
	int	color;
	int	pos = 0;

	(void)color;
	i_w = (h.line_length / 4);
	while (++j < i_w)
	{
		i = -1;
		while (++i < 64)
		{
			pos = i * 4 + h.line_length * j;
			if (h.addr[pos+3] == 0)
			{
				 pp(&img, i + (W_W / 2) - i_w / 2 , j + (W_H / 2) - 32, get_pixel_2(i, j, &h));
			}
		}
	}
}

void    draw_map(t_g *g)
{

	drawRow1(g, &g->img, 0, 0);
	if (g->activateButton && g->affCheck)
	{
		//mlx_string_put(g->mlx, g->win, W_W / 2, W_H / 2, 0x444444, "Porte ouvertes");
		g->affCheck = 0;
	}
	if (!g->activateButton && !g->affCheck)
	{
		//mlx_string_put(g->mlx, g->win, W_W / 2, W_H / 2, 0x000000, "Portes fermees");
		g->affCheck = 0;
	}
	draw_minimap(g);
	pistol_anim(g);
	create_crosshair(g->img, g->cross);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	affTime(g);
}

void	recuStartPos_N(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;		
	g->c.y = y + SIZE / 2;
	g->c.o = 0;
}

void	recuStartPos_S(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;
	g->c.y = y + SIZE / 2;
	g->c.o = 180;
}

void	recuStartPos_W(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;
	g->c.y = y + SIZE / 2;
	g->c.o = 270;
}

void	recuStartPos_E(t_g *g, int x, int y)
{
	g->c.x = x + SIZE / 2;
	g->c.y = y + SIZE / 2;
	g->c.o = 90;
}

void	recuStartPos(t_g *g)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = -1;
	y = 0;
	while (g->m.map[++i])
	{
		j = -1;
		x = 0;
		while (g->m.map[i][++j])
		{
			if (g->m.map[i][j] == 'N')
				recuStartPos_N(g, x, y);
			if (g->m.map[i][j] == 'S')
				recuStartPos_S(g, x, y);
			if (g->m.map[i][j] == 'W')
				recuStartPos_W(g, x, y);
			if (g->m.map[i][j] == 'E')
				recuStartPos_E(g, x, y);
			x += SIZE;
		}
		y += SIZE;
	}
}

int	createRGB(t_g *g)
{
	return ((g->m.c_r << 16) + (g->m.c_g << 8) + g->m.c_b );
}

int	createRGBsol(t_g *g)
{
	return ((g->m.f_r << 16) + (g->m.f_g << 8) + g->m.f_b);
}

void	recupRGB(t_g *g)
{
	g->cielcolor = createRGB(g);
	g->solcolor = createRGBsol(g);
}
int	mouseTracking(t_g *g)
{
	int	x = 0;
	int	y = 0;

	//mlx_mouse_hide(g->mlx, g->win);
	mlx_mouse_get_pos(g->mlx, g->win, &x, &y);
	if(x > W_W / 2)
	{
		ft_keypress(R, g);
		g->mouseR = 1;
	}
	if (x < W_W / 2)
	{
		ft_keypress(L, g);
		g->mouseL = 1;
	}
	mlx_mouse_move(g->mlx, g->win, W_W / 2, W_W / 2);
	return (0);
}

int	start(t_g *g)
{
	CheckPosExit(g);
	ft_move(g);
	mouseTracking(g);
	return (0);
}

void	initWallTextures_2(t_data ouest, t_g *g)
{
	int	i_h;
	int	i_w;

	ouest.img = mlx_xpm_file_to_image(g->mlx, g->m.we_texture + 1, &i_w, &i_h);
	ouest.addr = mlx_get_data_addr(ouest.img, &ouest.bits_per_pixel, &ouest.line_length, &ouest.endian);
	g->ouest = ouest;
}

void	initWallTextures(t_data nord, t_data sud, t_data est, t_g *g)
{
	int	i_h;
	int	i_w;

	nord.img = mlx_xpm_file_to_image(g->mlx, g->m.no_texture + 1, &i_w, &i_h);
	nord.addr = mlx_get_data_addr(nord.img, &nord.bits_per_pixel, &nord.line_length, &nord.endian);
	sud.img = mlx_xpm_file_to_image(g->mlx, g->m.so_texture + 1, &i_w, &i_h);
	sud.addr = mlx_get_data_addr(sud.img, &sud.bits_per_pixel, &sud.line_length, &sud.endian);
	est.img = mlx_xpm_file_to_image(g->mlx, g->m.ea_texture + 1, &i_w, &i_h);
	est.addr = mlx_get_data_addr(est.img, &est.bits_per_pixel, &est.line_length, &est.endian);
	g->nord = nord;
	g->sud = sud;
	g->est = est;
}

void	initBonusTextures(t_data hand_1, t_data hand_2, t_data hand_3, t_g *g)
{
	int	i_h;
	int	i_w;
	t_data	hand_4;
	t_data	hand_5;

	hand_1.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_1.xpm", &i_w, &i_h);
	hand_1.addr = mlx_get_data_addr(hand_1.img, &hand_1.bits_per_pixel, &hand_1.line_length, &hand_1.endian);
	hand_2.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_2.xpm", &i_w, &i_h);
	hand_2.addr = mlx_get_data_addr(hand_2.img, &hand_2.bits_per_pixel, &hand_2.line_length, &hand_2.endian);
	hand_3.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_3.xpm", &i_w, &i_h);
	hand_3.addr = mlx_get_data_addr(hand_3.img, &hand_3.bits_per_pixel, &hand_3.line_length, &hand_3.endian);
	hand_4.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_4.xpm", &i_w, &i_h);
	hand_4.addr = mlx_get_data_addr(hand_4.img, &hand_4.bits_per_pixel, &hand_4.line_length, &hand_4.endian);
	hand_5.img = mlx_xpm_file_to_image(g->mlx, "imgs/hand_5.xpm", &i_w, &i_h);
	hand_5.addr = mlx_get_data_addr(hand_5.img, &hand_5.bits_per_pixel, &hand_5.line_length, &hand_5.endian);
	g->hand_1 = hand_1;
	g->hand_2 = hand_2;
	g->hand_3 = hand_3;
	g->hand_4 = hand_4;
	g->hand_5 = hand_5;
}

void	initBonusTextures_2(t_data b, t_data bc, t_data d, t_g *g)
{
	int	i_h;
	int	i_w;

	if (!(d.img = mlx_xpm_file_to_image(g->mlx, "imgs/D.xpm", &i_w, &i_h)))
		exit(0);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, &d.endian);
	b.img = mlx_xpm_file_to_image(g->mlx, "imgs/B.xpm", &i_w, &i_h);
	b.addr = mlx_get_data_addr(b.img, &b.bits_per_pixel, &b.line_length, &b.endian);
	bc.img = mlx_xpm_file_to_image(g->mlx, "imgs/BC.xpm", &i_w, &i_h);
	bc.addr = mlx_get_data_addr(bc.img, &bc.bits_per_pixel, &bc.line_length, &bc.endian);
	g->b = b;
	g->bc = bc;
	g->d = d;
}

void	initBonusTextures_3(t_data cross, t_data img, t_g *g)
{
	int	i_h;
	int	i_w;

	cross.img = mlx_xpm_file_to_image(g->mlx, "imgs/crosshair.xpm", &i_w, &i_h);
	cross.addr = mlx_get_data_addr(cross.img, &cross.bits_per_pixel, &cross.line_length, &cross.endian);
	img.img = mlx_new_image(g->mlx, W_W, W_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	g->img = img;
	g->cross = cross;
}

void	initBonusTextures_4(t_data w_1, t_data w_2, t_data exit, t_g *g)
{
	int	i_h;
	int	i_w;

	w_1.img = mlx_xpm_file_to_image(g->mlx, "imgs/w_1.xpm", &i_w, &i_h);
	w_1.addr = mlx_get_data_addr(w_1.img, &w_1.bits_per_pixel, &w_1.line_length, &w_1.endian);
	w_2.img = mlx_xpm_file_to_image(g->mlx, "imgs/w_2.xpm", &i_w, &i_h);
	w_2.addr = mlx_get_data_addr(w_2.img, &w_2.bits_per_pixel, &w_2.line_length, &w_2.endian);
	exit.img = mlx_xpm_file_to_image(g->mlx, "imgs/Exit.xpm", &i_w, &i_h);
	exit.addr = mlx_get_data_addr(exit.img, &exit.bits_per_pixel, &exit.line_length, &exit.endian);
	g->w_1 = w_1;
	g->w_2 = w_2;
	g->exit = exit;
}

int	ft_buttonPress(int button, t_g *g)
{
	if (button == 1)
		g->button_left = 1;
	if (button == 1 && g->button_left == 1)
		g->button_left = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_m	m;
	t_g	g;

	if (ac != 2)
		return (ft_errors(2), -1);
	init_struct_g(&g, ac, av);
	init_struct_m(&m);
	g.w_1check = 0;
	g.button_left = 0;
	g.button_right = 0;
	g.S_M = SPEED;
	if(!ft_parsing(&g))
		return(-1);
	g.mlx = mlx_init();
	if (!g.mlx)
		return (free_m(&g), ft_errors(3), -1);
	g.win = mlx_new_window(g.mlx, W_W, W_H, "cub3d");
	initWallTextures(g.nord, g.sud, g.est, &g);
	initWallTextures_2(g.ouest, &g);
	initBonusTextures(g.hand_1, g.hand_2, g.hand_3, &g);
	initBonusTextures_2(g.b, g.bc, g.d, &g);
	initBonusTextures_3(g.cross, g.img, &g);
	initBonusTextures_4(g.w_1, g.w_2, g.exit, &g);
	recuStartPos(&g);
	recupRGB(&g);
	draw_map(&g);
	mlx_mouse_move(g.mlx, g.win, W_W / 2, W_H / 2);
	mlx_loop_hook(g.mlx, start, &g);
	mlx_hook(g.win, 2, 1L << 0, ft_keypress, &g);
	mlx_hook(g.win, 3, 1L << 1, ft_keyrelease, &g);
	mlx_hook(g.win, 17, 1L << 0, ft_key_cross, &g);
	//mlx_hook(g.win, 4, 1L << 2, ft_buttonPress, &g);
	mlx_loop(g.mlx);
	return (0);
}
