/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:47:34 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 15:20:40 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ERR_MSG "map error\n"
# define MAP_BUFFER_SIZE 16384
# define INFO_BUFFER_SIZE 64

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
int		ft_read_map(t_map *map, int map_fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_raw_map(int map_fd);
char	**ft_split(char *str, char sep);
int		ft_count_words(char *str, char sep);
char	*ft_alloc_word(char *str, int *index, char sep);
int		ft_word_len(char *str, int start, char sep);
void	ft_free_words(char **res, int i);
int		ft_valid_map(t_map map);
void	ft_free_all(char **grid);
void	ft_print_map(char **map);
void	ft_find_fill_bsq(t_map map);
int		ft_invalid_empty_lines(char *raw_map);
int		ft_min(int a, int b, int c);
void	ft_mark_square(char **map, int max_i, int max_j, int size_max);
void	ft_maps(char **map, int rows, int cols, char sign_obs);


#endif
