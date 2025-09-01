/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:54:09 by serromer          #+#    #+#             */
/*   Updated: 2025/09/01 21:25:35 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2 && argv)
	{
		ft_puterr(ERR_ARGC);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		ft_solve_bsq(argv[i]);
		if (i + 1 < argc)
			write(1, "\n", 1);
		i++;
	}
}
