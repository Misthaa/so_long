/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:02:19 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 14:06:23 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_display(t_data data)
{
	if (data.x == 0)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[2],
			(data.x * 64), (data.y * 64));
	else if (data.x == (ft_count_column(data.a) - 1))
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[3],
			(data.x * 64), (data.y * 64));
	else if (!(data.y == (ft_count_line(data.a) - 1)) && !(data.y == 0)
		&& data.a[data.y][data.x] == '1')
		random_wall(data);
	else
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[1],
			(data.x * 64), (data.y * 64));
	if (data.a[data.y][data.x] == '0')
		random_floor(data);
	if (data.a[data.y][data.x] == 'C')
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[0],
			(data.x * 64), (data.y * 64));
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[5],
			(data.x * 64), (data.y * 64));
	}
}

void	other_display(t_data *data)
{
	if (data->a[data->y][data->x] == 'P')
	{
		data->xx = data->x;
		data->yy = data->y;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			(data->x * 64), (data->y * 64));
	}
	if (data->a[data->y][data->x] == 'M')
	{
		data->xm = data->x;
		data->ym = data->y;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			(data->x * 64), (data->y * 64));
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[13],
			(data->x * 64), (data->y * 64));
	}
}

void	display_and_use_exit(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->a[data->y])
	{
		while (data->a[data->y][data->x])
		{
			if (data->xx != 0 && data->yy != 0
				&& data->a[data->y][data->x] == 'E')
			{
				data->x_exit = data->x;
				data->y_exit = data->y;
				ft_check_coin(data);
			}
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
}

void	display_map(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->a[data->y])
	{
		while (data->a[data->y][data->x])
		{
			all_display(*data);
			other_display(data);
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	display_and_use_exit(data);
}
