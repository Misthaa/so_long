/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:31:10 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/09 19:55:15 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_anim_right(void *param)
{
	t_data	*data;

	data = param;
	data->new_time_ms = (clock() * 1000) / CLOCKS_PER_SEC;
	if (data->new_time_ms > data->start_time + 200)
	{
		if (data->sprite_state == 0)
		{
			data->sprite_state = 1;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[8],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[0],
				(data->xx * 64), (data->yy * 64));
		}
		else if (data->sprite_state == 1)
		{
			data->sprite_state = 0;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[9],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[1],
				(data->xx * 64), (data->yy * 64));
		}
		data->sprite_on = 1;
		data->start_time = data->new_time_ms;
	}
}

void	sprite_anim_up(void *param)
{
	t_data	*data;

	data = param;
	data->new_time_ms = (clock() * 1000) / CLOCKS_PER_SEC;
	if (data->new_time_ms > data->start_time + 200)
	{
		if (data->sprite_state == 0)
		{
			data->sprite_state = 1;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[8],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[2],
				(data->xx * 64), (data->yy * 64));
		}
		else if (data->sprite_state == 1)
		{
			data->sprite_state = 0;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[9],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[3],
				(data->xx * 64), (data->yy * 64));
		}
		data->sprite_on = 1;
		data->start_time = data->new_time_ms;
	}
}

void	sprite_anim_left(void *param)
{
	t_data	*data;

	data = param;
	data->new_time_ms = (clock() * 1000) / CLOCKS_PER_SEC;
	if (data->new_time_ms > data->start_time + 200)
	{
		if (data->sprite_state == 0)
		{
			data->sprite_state = 1;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[8],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[4],
				(data->xx * 64), (data->yy * 64));
		}
		else if (data->sprite_state == 1)
		{
			data->sprite_state = 0;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[9],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[5],
				(data->xx * 64), (data->yy * 64));
		}
		data->sprite_on = 1;
		data->start_time = data->new_time_ms;
	}
}

void	sprite_anim_front(void *param)
{
	t_data	*data;

	data = param;
	data->new_time_ms = (clock() * 1000) / CLOCKS_PER_SEC;
	if (data->new_time_ms > data->start_time + 200)
	{
		if (data->sprite_state == 0)
		{
			data->sprite_state = 1;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[8],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[6],
				(data->xx * 64), (data->yy * 64));
		}
		else if (data->sprite_state == 1)
		{
			data->sprite_state = 0;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[9],
				(data->xx * 64), (data->yy * 64));
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2[7],
				(data->xx * 64), (data->yy * 64));
		}
		data->sprite_on = 1;
		data->start_time = data->new_time_ms;
	}
}
