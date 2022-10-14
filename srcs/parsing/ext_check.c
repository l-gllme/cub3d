/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:20:28 by jtaravel          #+#    #+#             */
/*   Updated: 2022/06/15 13:26:38 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;
	int	len;

	len = ft_strlen(to_find);
	i = 0;
	if (to_find[i] == 0)
		return (str);
	while (str[i] != 0)
	{
		n = 0;
		while (str[i + n] == to_find[n])
		{
			if (n == len - 1)
				return (&str[i]);
			n++;
		}
		i++;
	}
	return (0);
}

int	ft_check_file(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

int	ft_check_end(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
		i++;
	i--;
	j = i;
	if (str[i] == 'b')
		i--;
	if (str[i] == 'u')
		i--;
	if (str[i] == 'c')
		i--;
	if (str[i] == '.')
		i--;
	if (j == i)
		return (0);
	return (1);
}

int	ft_check_extension(char *str)
{
	if (!ft_check_end(str) || !ft_strstr(str, ".cub") || !ft_check_file(str))
		return (0);
	return (1);
}
