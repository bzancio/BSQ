/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 03:02:37 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 16:14:01 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_map_has_empty(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.cols)
		{
			if (map.grid[i][j] == map.empty)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_invalid_empty_lines(char *raw_map)
{
	int	i;

	if (!raw_map || raw_map[0] == '\n')
		return (1);
	i = 1;
	while (raw_map[i])
	{
		if (raw_map[i] == '\n' && raw_map[i - 1] == '\n')
			return (1);
		i++;
	}
	if (raw_map[i - 1] != '\n')
		return (1);
	return (0);
}
