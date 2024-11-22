/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymoves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:44:15 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 17:54:50 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sprite_anim(void *param)
{
	t_data	*data;

	data = param;
	if (data->orientation == 1)
	{
		sprite_anim_up(param);
	}
	else if (data->orientation == 4)
	{
		sprite_anim_front(param);
	}
	else if (data->orientation == 3)
	{
		sprite_anim_left(param);
	}
	else if (data->orientation == 2)
	{
		sprite_anim_right(param);
	}
	if (data->check_mob == 0)
	{
		sprite_anim_monstre(param);
	}
	return (0);
}

int	exit_open(t_data *data)
{
	return (data->coin_act == data->coin);
}

int	ft_nope(int y, int x, t_data *data)
{
	return (data->a[y][x] == '1' || (data->a[y][x] == 'E' && !exit_open(data)));
}

void	key_hook_dash(int keycode, t_data *data)
{
	static int	last;

	if (!last)
		last = keycode;
	if (keycode == 44 && last == 26
		&& data->a[data->yy - 1][data->xx] != '1'
			&& !ft_nope(data->yy - 2, data->xx, data))
		up_dash(data);
	else if (keycode == 44 && last == 22
		&& data->a[data->yy + 1][data->xx] != '1'
			&& !ft_nope(data->yy + 2, data->xx, data))
		down_dash(data);
	else if (keycode == 44 && last == 4
		&& data->a[data->yy][data->xx - 1] != '1'
			&& !ft_nope(data->yy, data->xx - 2, data))
		left_dash(data);
	else if (keycode == 44 && last == 7
		&& data->a[data->yy][data->xx + 1] != '1'
			&& !ft_nope(data->yy, data->xx + 2, data))
		right_dash(data);
	last = keycode;
}

void	key_hook(int keycode, t_data *data)
{
	char	*score;

	score = ft_itoa(data->score);
	if (keycode == 41)
		close_win(data, 0);
	else if (keycode == 26 && !ft_nope(data->yy - 1, data->xx, data))
		up(data);
	if (keycode == 22 && !ft_nope(data->yy + 1, data->xx, data))
		down(data);
	if (keycode == 4 && !ft_nope(data->yy, data->xx - 1, data))
		left(data);
	if (keycode == 7 && !ft_nope(data->yy, data->xx + 1, data))
		right(data);
	key_hook_dash(keycode, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img[19],
		x_calc(data->a) - 100, y_calc(data->a));
	mlx_string_put(data->mlx, data->mlx_win, x_calc(data->a) - 100,
		y_calc(data->a) + 20, 0xFFFFFFFF, score);
	free(score);
}
