/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:33:40 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 17:53:57 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**str_cpy_map(char **str)
{
	int		i;
	char	**cpy;

	i = 0;
	while (str[i])
		i++;
	cpy = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (str[i])
	{
		cpy[i] = ft_strdup(str[i]);
		i++;
	}
	return (cpy);
}

int	is_possible_map(char **str, t_data *data)
{
	int		i;
	int		j;
	char	**map2;
	char	**tmp;

	i = -1;
	map2 = str_cpy_map(str);
	tmp = flood_fill(map2);
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if ((str[i][j] == 'E' && map2[i][j] != 'S')
				|| (str[i][j] == 'C' && map2[i][j] != 'S'))
			{
				ft_printf("Your map is not finishable.\n");
				ft_free_map_checker(map2, NULL, data);
				return (0);
			}
		}
		j = 0;
	}
	ft_free_map_checker(map2, NULL, data);
	return (1);
}

void	position(char ***str, int *i, int *j)
{
	(*i) = 0;
	while ((*str)[*i])
	{
		(*j) = 0;
		while ((*str)[*i][*j])
		{
			if ((*str)[*i][*j] == 'P')
			{
				(*str)[*i][*j] = 'S';
				return ;
			}
			(*j)++;
		}
		(*i)++;
	}
}

char	**flood_fill(char **str)
{
	int	i;
	int	j;

	position(&str, &i, &j);
	if (str[i + 1][j] == '0' || str[i + 1][j] == 'C' || str[i + 1][j] == 'E')
	{
		str[i + 1][j] = 'P';
		flood_fill(str);
	}
	if (str[i][j + 1] == '0' || str[i][j + 1] == 'C' || str[i][j + 1] == 'E')
	{
		str[i][j + 1] = 'P';
		flood_fill(str);
	}
	if (str[i - 1][j] == '0' || str[i - 1][j] == 'C' || str[i - 1][j] == 'E')
	{
		str[i - 1][j] = 'P';
		flood_fill(str);
	}
	if (str[i][j - 1] == '0' || str[i][j - 1] == 'C' || str[i][j - 1] == 'E')
	{
		str[i][j - 1] = 'P';
		flood_fill(str);
	}
	return (str);
}

int	ft_checkall_file(char *map_path, char *strbl, char **str, t_data *data)
{
	if (is_ber(map_path) == 0)
		return (0);
	if (is_double_bl(strbl) == 0)
		return (0);
	if (is_valid_map_c(str) == 0)
		return (0);
	if (is_possible_map(str, data) == 0)
		return (0);
	return (1);
}
