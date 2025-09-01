/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:47:34 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/02 00:15:46 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ERR_MSG "map error\n"

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

void	ft_putstr(char *str);
void	ft_puterr(char *str);
void	ft_solve_bsq(int map_fd);
int		ft_read_info(t_map *map, int map_fd);
int		ft_get_rows(char *buffer, int pos);
int		ft_atoi(char *str);

#endif
