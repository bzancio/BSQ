/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:29 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 16:19:26 by ibuil            ###   ########.fr       */
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
	if (ft_valid_map(map) || !ft_map_has_empty(map))
	{
		ft_puterr(ERR_MSG);
		ft_free_all(map.grid);
		return ;
	}
	ft_find_fill_bsq(map);
	ft_print_map(map.grid);
	ft_free_all(map.grid);
}
