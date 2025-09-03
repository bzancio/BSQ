/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:29 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 18:29:26 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_solve_bsq(int map_fd)
{
	t_map	map;
	char	*raw_map;

	map.grid = NULL;
	raw_map = ft_read_raw_map(map_fd);
	if (!raw_map || ft_read_info(&map, raw_map)
		|| ft_read_map(&map, raw_map)
		|| ft_valid_map(map) || !ft_map_has_empty(map))
	{
		ft_puterr(ERR_MSG);
		free(raw_map);
		return ;
	}
	free(raw_map);
	ft_find_fill_bsq(map);
	ft_print_map(map.grid);
	ft_free_all(map.grid);
}
