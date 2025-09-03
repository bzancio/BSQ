/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:09 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 18:28:57 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_valid_map(t_map map)
{
	int	i;
	int	j;

	if (!map.grid || map.rows <= 0 || map.cols <= 0)
		return (1);
	i = 0;
	while (map.grid[i])
	{
		if (map.grid[i][0] == '\0')
			return (1);
		j = 0;
		while (map.grid[i][j])
		{
			if (map.grid[i][j] != map.empty && map.grid[i][j] != map.obstacle)
				return (1);
			j++;
		}
		if (j != map.cols)
			return (1);
		i++;
	}
	if (i != map.rows)
		return (1);
	return (0);
}

int	ft_get_rows(char *buffer, int pos)
{
	char	str_buffer[INFO_BUFFER_SIZE];
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

int	ft_read_info(t_map *map, char *raw_map)
{
	char	buffer[INFO_BUFFER_SIZE];
	int		pos;

	pos = 0;
	while (raw_map[pos] && raw_map[pos] != '\n')
	{
		if (pos >= 63 || raw_map[pos] < 32 || raw_map[pos] > 126)
			return (1);
		buffer[pos] = raw_map[pos];
		pos++;
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

char	*ft_read_raw_map(int map_fd)
{
	char	map_buffer[MAP_BUFFER_SIZE + 1];
	char	*raw_map;
	char	*temp;
	int		bytes;

	raw_map = malloc(sizeof(char));
	if (!raw_map)
		return (NULL);
	raw_map[0] = '\0';
	bytes = read(map_fd, map_buffer, MAP_BUFFER_SIZE);
	while (bytes > 0)
	{
		map_buffer[bytes] = '\0';
		temp = ft_strjoin(raw_map, map_buffer);
		free(raw_map);
		if (!temp)
			return (NULL);
		raw_map = temp;
		bytes = read(map_fd, map_buffer, MAP_BUFFER_SIZE);
	}
	if (bytes < 0)
		return (free(raw_map), NULL);
	return (raw_map);
}

int	ft_read_map(t_map *map, char *raw_map)
{
	int		i;
	char	*map_start;

	i = 0;
	while (raw_map[i] && raw_map[i] != '\n')
		i++;
	if (raw_map[i] == '\n')
		i++;
	map_start = raw_map + i;
	if (ft_invalid_empty_lines(map_start))
		return (1);
	map->grid = ft_split(map_start, '\n');
	if (!map->grid || !map->grid[0])
		return (1);
	map->cols = ft_strlen(map->grid[0]);
	if (map->cols <= 0)
		return (1);
	return (0);
}
