/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 03:02:37 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 03:26:09 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
	if (raw_map[i - 1] == '\n')
		return (1);
	return (0);
}
