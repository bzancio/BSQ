/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:54:09 by serromer          #+#    #+#             */
/*   Updated: 2025/09/02 08:45:13 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	i;
	int	map_fd;

	if (argc == 1)
		ft_solve_bsq(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			map_fd = open(argv[i], O_RDONLY);
			if (map_fd < 0)
				ft_puterr(ERR_MSG);
			else
			{
				ft_solve_bsq(map_fd);
				close(map_fd);
			}
			if (i + 1 < argc)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
