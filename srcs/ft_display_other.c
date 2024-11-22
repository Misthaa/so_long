/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:23:28 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/15 16:04:32 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	random_wall(t_data data)
{
	if (data.x % data.y == 1)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[10],
			(data.x * 64), (data.y * 64));
	else
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[4],
			(data.x * 64), (data.y * 64));
}

void	random_floor(t_data data)
{
	if (data.x * data.y % 9 == 4)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[11],
			(data.x * 64), (data.y * 64));
	else if (data.x * data.y % 9 == 1)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[12],
			(data.x * 64), (data.y * 64));
	else
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[0],
			(data.x * 64), (data.y * 64));
}

void	random_floor_player(t_data data)
{
	if (data.xx * data.yy % 9 == 4)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[11],
			(data.xx * 64), (data.yy * 64));
	else if (data.xx * data.yy % 9 == 1)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[12],
			(data.xx * 64), (data.yy * 64));
	else
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[0],
			(data.xx * 64), (data.yy * 64));
}

void	random_floor_monster(t_data data)
{
	if (data.xm * data.ym % 9 == 4)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[11],
			(data.xm * 64), (data.ym * 64));
	else if (data.xm * data.ym % 9 == 1)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[12],
			(data.xm * 64), (data.ym * 64));
	else
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img[0],
			(data.xm * 64), (data.ym * 64));
}
