/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:03:55 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/09 22:17:08 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_value_map(int ac)
{
	if (ac > 3)
	{
		ft_printf("Error, you cant put more than two maps.\n");
		return (0);
	}
	if (ac < 2)
	{
		ft_printf("Error, you dont have insert map.\n");
		return (0);
	}
	return (1);
}

int	is_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i <= 4)
	{
		ft_printf("Error, not valid file.\n");
		return (0);
	}
	if (str[i - 4] != '.'
		|| str[i - 3] != 'b'
		|| str[i - 2] != 'e'
		|| str[i - 1] != 'r')
	{
		ft_printf("Error, your map doesn't have the correct file extension.\n");
		return (0);
	}
	return (1);
}

int	is_more_or_less_c(char **str)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'E' || str[i][j] == 'P' || str[i][j] == 'M')
				flag++;
		}
	}
	if (flag != 3)
	{
		ft_printf("Error, not valid map.\n");
		return (0);
	}
	return (1);
}

int	is_valid_map_c(char **str)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C' &&
			str[i][j] != 'E' && str[i][j] != 'P' && str[i][j] != 'M')
			{
				ft_printf("A character entered is not valid.\n");
				return (0);
			}
		}
		j = 0;
	}
	if (is_more_or_less_c(str) == 0)
		return (0);
	return (1);
}

int	is_double_bl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n')
			{
				ft_printf("Error, map are not valid.\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}
