/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:44:33 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/09 19:45:07 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_monster(t_data *data)
{
	random_floor_monster(*data);
	data->ym -= 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[14],
		(data->xm * 64), (data->ym * 64));
	ft_check_coin(data);
	ft_check_death(data);
}

void	down_monster(t_data *data)
{
	random_floor_monster(*data);
	data->ym += 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[13],
		(data->xm * 64), (data->ym * 64));
	ft_check_coin(data);
	ft_check_death(data);
}

void	left_monster(t_data *data)
{
	random_floor_monster(*data);
	data->xm -= 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[15],
		(data->xm * 64), (data->ym * 64));
	ft_check_coin(data);
	ft_check_death(data);
}

void	right_monster(t_data *data)
{
	random_floor_monster(*data);
	data->xm += 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[16],
		(data->xm * 64), (data->ym * 64));
	ft_check_coin(data);
	ft_check_death(data);
}
