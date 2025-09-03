/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:14:59 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 17:12:24 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_min(int a, int b, int c)
{
	int	temp;

	temp = 0;
	if (a < b)
		temp = a;
	else
		temp = b;
	if (temp < c)
		return (temp);
	return (c);
}

void	ft_initialize_dp(int **dp, char **map, t_map maps)
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
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + ft_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
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

void	ft_maps(char **map, t_map maps)
{
	int	**dp;
	int	*max_info;
	int	i;

	dp = malloc(maps.rows * sizeof(int *));
	i = 0;
	while (i < maps.rows)
	{
		dp[i] = malloc(maps.cols * sizeof(int));
		i++;
	}
	ft_initialize_dp(dp, map, maps);
	max_info = malloc(3 * sizeof(int));
	ft_find_max(dp, maps.rows, maps.cols, max_info);
	ft_mark_square_by_max(map, max_info, maps.full);
}

void	ft_find_fill_bsq(t_map map)
{
	if (!map.grid)
		return ;
	ft_maps(map.grid, map);
}
