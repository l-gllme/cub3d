/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:46:23 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:37:04 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pp(t_data *data, double x, double y, int color)
{
	char	*dst;

	dst = data->addr + (int)(((double)y * data->line_length
				+ (double)x * (data->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

int	gp(int x, int y, t_data i)
{
	char	*ret;

	ret = i.addr + (y * i.line_length + x * (i.bits_per_pixel / 8));
	return (*(unsigned int *)ret);
}

int	get_pixel_2(int x, int y, t_data *i)
{
	char	*ret;

	ret = i->addr + (y * i->line_length + x * (i->bits_per_pixel / 8));
	return (*(unsigned int *)ret);
}
