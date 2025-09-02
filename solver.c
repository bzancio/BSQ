/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:29 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/02 23:53:27 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_solve_bsq(int map_fd)
{
	t_map	map;

	if (ft_read_info(&map, map_fd))
	{
		ft_puterr(ERR_MSG);
		return ;
	}
	if (ft_read_map(&map, map_fd))
	{
		ft_puterr(ERR_MSG);
		return ;
	}
	if (ft_valid_map(map))
	{
		ft_puterr(ERR_MSG);
		ft_free_words(map.grid, map.rows - 1);
		free(map.grid);
		return ;
	}
	ft_free_words(map.grid, map.rows - 1);
	free(map.grid);
}
