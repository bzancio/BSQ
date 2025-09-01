/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:09 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/02 00:52:27 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_get_rows(char *buffer, int pos)
{
	char	str_buffer[64];
	int		i;

	i = 0;
	while (i < pos)
	{
		str_buffer[i] = buffer[i];
		i++;
	}
	str_buffer[i] = '\0';
	return (ft_atoi(str_buffer));
}

int	ft_read_info(t_map *map, int map_fd)
{
	char	buffer[64];
	char	c;
	int		pos;

	pos = 0;
	while (read(map_fd, &c, 1) > 0 && c != '\n')
	{
		if (pos >= 63 || c < 32 || c > 126)
			return (1);
		buffer[pos++] = c;
	}
	if (pos < 4)
		return (1);
	buffer[pos] = '\0';
	map->empty = buffer[pos - 3];
	map->obstacle = buffer[pos - 2];
	map->full = buffer[pos - 1];
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (1);
	map->rows = ft_get_rows(buffer, pos - 3);
	if (map->rows <= 0)
		return (1);
	return (0);
}
