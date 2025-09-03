/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:14:59 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 15:20:01 by sergio-alej      ###   ########.fr       */
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


void	ft_mark_square(char **map, int max_i, int max_j, int size_max)
{
	int	i;
	int	j;

	i = max_i;
	while (i > max_i - size_max)
	{
		j = max_j;
		while (j > max_j - size_max)
		{
			map[i][j] = 'x';
			j--;
		}
		i--;
	}
}

void	ft_maps(char **map, int rows, int cols, char sign_obs)
{
	int	dp[rows][cols];
	int	max;
	int	max_i;
	int	max_j;
	int	i;
	int	j;

	max = 0;
	max_i = 0;
	max_j = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == sign_obs)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + ft_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
			if (dp[i][j] > max)
			{
				max = dp[i][j];
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}
	ft_mark_square(map, max_i, max_j, max);
}

void	ft_find_fill_bsq(t_map map)
{
	if (!map.grid)
		return ;

	ft_maps(map.grid,map.rows,map.cols,map.obstacle);
	
}