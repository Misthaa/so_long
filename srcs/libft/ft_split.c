/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:00:26 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 15:30:39 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_len_spt(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_wordlen(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == 0)
			return (word);
		word++;
		while (str[i] != c && str[i])
			i++;
	}
	return (word);
}

char	**free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**fill_str(const char *s, char c, int i[3], char **strf)
{
	while (s[i[0]] != c && s[i[0]])
		strf[i[1]][i[2]++] = s[i[0]++];
	strf[i[1]][i[2]] = 0;
	return (strf);
}

char	**ft_split(char const *s, char c)
{
	int		i[3];
	char	**strf;

	i[0] = 0;
	i[1] = -1;
	if (s == NULL)
		return (NULL);
	strf = malloc(sizeof(char *) * (ft_wordlen(s, c) + 1));
	if (strf == NULL)
		return (NULL);
	while (++i[1] < ft_wordlen(s, c))
	{
		while (s[i[0]] == c)
			i[0]++;
		if (s[i[0]] == 0)
			break ;
		strf[i[1]] = malloc(sizeof(char) * (ft_len_spt(&s[i[0]], c) + 1));
		if (strf == NULL)
			return (free_split(strf));
		i[2] = 0;
		fill_str(s, c, i, strf);
	}
	strf[i[1]] = 0;
	return (strf);
}
