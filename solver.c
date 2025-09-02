/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:29 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/02 05:10:51 by ibuil            ###   ########.fr       */
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
}
