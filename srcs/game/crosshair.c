/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:20:39 by jtaravel          #+#    #+#             */
/*   Updated: 2022/10/19 17:22:41 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_crosshair(t_data img, t_data h)
{
	int	i;
	int	j;
	int	i_w;
	int	pos;

	i = -1;
	j = -1;
	i_w = (h.line_length / 4);
	while (++j < i_w)
	{
		i = -1;
		while (++i < 64)
		{
			pos = i * 4 + h.line_length * j;
			if (h.addr[pos + 3] == 0)
			{
				pp(&img, i + (W_W / 2) - i_w / 2, j
					+ (W_H / 2) - 32, get_pixel_2(i, j, &h));
			}
		}
	}
}
