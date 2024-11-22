/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:15:15 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/09 19:44:43 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	random_direction(t_data *data)
{
	int	random;

	srand(time(NULL));
	random = rand() % 4;
	if (random == 0 && data->a[data->ym - 1][data->xm] != '1' &&
		data->a[data->ym - 1][data->xm] != 'C' &&
			data->a[data->ym - 1][data->xm] != 'E')
		up_monster(data);
	if (random == 1 && data->a[data->ym + 1][data->xm] != '1' &&
		data->a[data->ym + 1][data->xm] != 'C' &&
			data->a[data->ym + 1][data->xm] != 'E')
		down_monster(data);
	if (random == 2 && data->a[data->ym][data->xm - 1] != '1' &&
		data->a[data->ym][data->xm - 1] != 'C' &&
			data->a[data->ym][data->xm - 1] != 'E')
		left_monster(data);
	if (random == 3 && data->a[data->ym][data->xm + 1] != '1' &&
		data->a[data->ym][data->xm + 1] != 'C' &&
			data->a[data->ym][data->xm + 1] != 'E')
		right_monster(data);
}

int	sprite_anim_monstre(void *param)
{
	t_data		*data;
	static int	new_time_ms2 = 0;

	data = param;
	new_time_ms2 += 1;
	if (new_time_ms2 > 1500)
	{
		if (data->sprite_state == 0)
		{
			data->sprite_state = 1;
			random_direction(data);
		}
		else if (data->sprite_state == 1)
		{
			data->sprite_state = 0;
			random_direction(data);
		}
		data->sprite_on = 1;
		new_time_ms2 = 0;
	}
	return (0);
}
