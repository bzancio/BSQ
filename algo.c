/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:14:59 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 17:56:08 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_initialize_dp(int **d, char **map, t_map maps)
{
	int	i;
	int	j;

	i = 0;
	while (i < maps.rows)
	{
		j = 0;
		while (j < maps.cols)
		{
			if (map[i][j] == maps.obstacle)
				d[i][j] = 0;
			else if (i == 0 || j == 0)
				d[i][j] = 1;
			else
				d[i][j] = 1 + ft_min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
			j++;
		}
		i++;
	}
}

void	ft_find_max(int **dp, int rows, int cols, int *max_info)
{
	int	i;
	int	j;

	max_info[0] = 0;
	max_info[1] = 0;
	max_info[2] = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (dp[i][j] > max_info[2])
			{
				max_info[2] = dp[i][j];
				max_info[0] = i;
				max_info[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_mark_square_by_max(char **map, int *max, char sign_full)
{
	int	i;
	int	j;

	i = max[0];
	while (i > max[0] - max[2])
	{
		j = max[1];
		while (j > max[1] - max[2])
		{
			map[i][j] = sign_full;
			j--;
		}
		i--;
	}
}

int	ft_maps(char **map, t_map maps)
{
	int	**dp;
	int	*max_info;
	int	i;

	dp = malloc(maps.rows * sizeof(int *));
	if (!dp)
		return (1);
	i = 0;
	while (i < maps.rows)
	{
		dp[i] = malloc(maps.cols * sizeof(int));
		if (!dp[i])
		{
			ft_free_all_int(dp, i);
			return (1);
		}
		i++;
	}
	ft_initialize_dp(dp, map, maps);
	max_info = malloc(3 * sizeof(int));
	if (!max_info)
		return (ft_free_all_int(dp, i), 1);
	ft_find_max(dp, maps.rows, maps.cols, max_info);
	ft_mark_square_by_max(map, max_info, maps.full);
	return (ft_free_all_int(dp, i), free(max_info), 0);
}

void	ft_find_fill_bsq(t_map map)
{
	if (!map.grid)
		return ;
	if (ft_maps(map.grid, map))
	{
		ft_puterr(ERR_MSG);
		return ;
	}
}
