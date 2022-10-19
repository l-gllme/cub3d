/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:31:39 by lguillau          #+#    #+#             */
/*   Updated: 2022/10/19 17:36:42 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_errors(int choice)
{
	ft_putstr_fd("Error\n", 2);
	if (choice == 0)
		return ;
	else if (choice == 1)
		ft_putstr_fd("cub3d: bad extension or file not found: \
			need \"file.cub\"\n", 2);
	else if (choice == 2)
		ft_putstr_fd("cub3d: 1 argument required: file.cub\n", 2);
	else if (choice == 3)
		ft_putstr_fd("cub3d: env variable missing: minilibx launch failed\n", 2);
	else if (choice == 4)
		ft_putstr_fd("cub3d: open failled\n", 2);
	else if (choice == 5)
		ft_putstr_fd("cub3d: bad map format: only 1,0,N,S,E,W are allowed\n", 2);
	else if (choice == 6)
		ft_putstr_fd("cub3d: ", 2);
}
