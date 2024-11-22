/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:15:15 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/09 19:56:41 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_dash(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->yy -= 2;
	data->orientation = 1;
	if (data->yy + 1 == data->ym && data->xx == data->xm)
	{
		data->check_mob = 1;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			(data->xm * 64), (data->ym * 64));
		data->ym = 0;
		system("paplay ./music/slash.ogg &");
	}
	else
		system("paplay ./music/dash2.ogg &");
	ft_check_coin(data);
	ft_check_death(data);
}

void	down_dash(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->yy += 2;
	data->orientation = 4;
	if (data->yy - 1 == data->ym && data->xx == data->xm)
	{
		data->check_mob = 1;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			(data->xm * 64), (data->ym * 64));
		data->ym = 0;
		system("paplay ./music/slash.ogg &");
	}
	else
		system("paplay ./music/dash2.ogg &");
	ft_check_coin(data);
	ft_check_death(data);
}

void	left_dash(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->xx -= 2;
	data->orientation = 3;
	if (data->yy == data->ym && data->xx + 1 == data->xm)
	{
		data->check_mob = 1;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			(data->xm * 64), (data->ym * 64));
		data->ym = 0;
		system("paplay ./music/slash.ogg &");
	}
	else
		system("paplay ./music/dash2.ogg &");
	ft_check_coin(data);
	ft_check_death(data);
}

void	right_dash(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->xx += 2;
	data->orientation = 2;
	if (data->yy == data->ym && data->xx - 1 == data->xm)
	{
		data->check_mob = 1;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[0],
			(data->xm * 64), (data->ym * 64));
		data->ym = 0;
		system("paplay ./music/slash.ogg &");
	}
	else
		system("paplay ./music/dash2.ogg &");
	ft_check_coin(data);
	ft_check_death(data);
}
