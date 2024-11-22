/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:15:15 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/10 20:57:48 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->yy -= 1;
	data->orientation = 1;
	data->score++;
	ft_check_coin(data);
	ft_check_death(data);
}

void	down(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->yy += 1;
	data->orientation = 4;
	data->score++;
	ft_check_coin(data);
	ft_check_death(data);
}

void	left(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->xx -= 1;
	data->orientation = 3;
	data->score++;
	ft_check_coin(data);
	ft_check_death(data);
}

void	right(t_data *data)
{
	random_floor_player(*data);
	data->start_time = 0;
	data->xx += 1;
	data->orientation = 2;
	data->score++;
	ft_check_coin(data);
	ft_check_death(data);
}
