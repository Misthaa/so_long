/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:23:56 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 21:55:42 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_checker(char **map, char **map2, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->column)
	{
		free(map[i]);
		i++;
	}
	free(map);
	i = -1;
	if (map2 == NULL)
		return ;
	while (map2[++i])
		free(map2[i]);
	free(map2);
}

void	destroy_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(data->mlx, data->img2[i]);
		i++;
	}
}

void	ft_free_data(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

void	close_win(t_data *data, int leave)
{
	char	*reload;

	reload = 0;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_images(data);
	free(data->img);
	free(data->img2);
	ft_free_data(data->a);
	mlx_destroy_display(data->mlx);
	system("killall paplay");
	if (leave == 1)
	{
		reload = ft_strjoin_sys("./so_long ", data->avm[2]);
		system(reload);
	}
	exit(0);
}

int	window_hook(int event, void *param)
{
	t_data	*data;

	data = param;
	if (event == 0)
		close_win(data, 0);
	return (0);
}
