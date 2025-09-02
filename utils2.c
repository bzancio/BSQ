/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuil <ibuil@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 05:17:39 by ibuil             #+#    #+#             */
/*   Updated: 2025/09/03 00:31:07 by ibuil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_words(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
}

int	ft_word_len(char *str, int start, char sep)
{
	int	len;

	len = 0;
	while (str[start] && str[start] != sep)
	{
		len++;
		start++;
	}
	return (len);
}

char	*ft_alloc_word(char *str, int *index, char sep)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = ft_word_len(str, *index, sep);
	word = malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = str[*index];
		i++;
		(*index)++;
	}
	word[word_len] = '\0';
	return (word);
}

int	ft_count_words(char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char *str, char sep)
{
	char	**res;
	int		words;
	int		index;
	int		i;

	words = ft_count_words(str, sep);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	index = 0;
	i = 0;
	while (i < words)
	{
		while (str[index] == sep)
			index++;
		res[i] = ft_alloc_word(str, &index, sep);
		if (!res[i])
		{
			ft_free_words(res, i - 1);
			return (free(res), NULL);
		}
		i++;
	}
	res[words] = NULL;
	return (res);
}
