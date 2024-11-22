/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:07:02 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/09 23:18:01 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_calc(char **a)
{
	int	y;
	int	x;
	int	result;

	y = 0;
	result = 0;
	x = 0;
	while (a[y][x])
	{
		result += 64;
		x++;
	}
	return (result);
}

int	y_calc(char **a)
{
	int	y;
	int	result;

	y = 0;
	result = 0;
	while (a[y])
	{
		result += 64;
		y++;
	}
	return (result);
}

int	ft_check_death(t_data *data)
{
	if (data->yy == data->ym && data->xx == data->xm)
	{
		ft_printf("You are dead, it fills you with determination.\n");
		close_win(data, 0);
	}
	return (1);
}

int	ft_check_coin(t_data *data)
{
	if (data->a[data->yy][data->xx] == 'C')
	{
		data->a[data->yy][data->xx] = '0';
		data->coin_act++;
	}
	if (data->is_init && data->coin_act == data->coin)
	{
		if (data->sound == 0)
		{
			system("paplay ./music/portal.ogg &");
			data->sound = 1;
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[6],
			(data->x_exit * 64), (data->y_exit * 64));
		if (data->a[data->yy][data->xx] == 'E')
			close_win(data, 1);
		return (1);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[7],
		(data->x * 64), (data->y * 64));
	return (0);
}

void	init_coin(t_data *data)
{
	data->y = 0;
	while (data->a[data->y])
	{
		data->x = 0;
		while (data->a[data->y][data->x])
		{
			if (data->a[data->y][data->x] == 'C')
				data->coin++;
			data->x++;
		}
		data->y++;
	}
}
