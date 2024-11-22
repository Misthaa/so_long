/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:33:19 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 20:11:02 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_column(char **str)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (str[0][j])
	{
		count++;
		j++;
	}
	return (count);
}

int	ft_count_line(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_check_wall(char **str, t_data *data)
{
	int	i;
	int	j;
	int	line;

	i = -1;
	line = ft_count_column(str) - 1;
	data->column = ft_count_line(str) - 1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][0] != '1'
				|| str[0][j] != '1'
				|| str[data->column][j] != '1'
				|| str[i][line] != '1')
			{
				ft_printf("Error, the map are not closed !\n");
				return (0);
			}
		}
	}
	return (1);
}

int	ft_checkall_map(char **str, t_data *data)
{
	int		random;

	srand(time(NULL));
	random = rand() % 10;
	if (ft_check_wall(str, data) == 0)
		return (0);
	if (random == 7)
		system("paplay ./music/SPECIAL.ogg &");
	else
		system("paplay ./music/main.ogg &");
	return (1);
}
