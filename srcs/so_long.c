/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:10:21 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 21:56:29 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*save_map(char *str)
{
	int		fd;
	char	*tmp;
	char	*map;
	char	*line;

	fd = open(str, O_RDWR);
	if (fd < 1)
	{
		ft_printf("Error, you didn't send me the right thing...\n");
		exit (0);
	}
	line = get_next_line(fd);
	map = ft_strdup("");
	while (line)
	{
		tmp = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
		map = ft_strdup(tmp);
		free(tmp);
	}
	free(line);
	line = NULL;
	close(fd);
	return (map);
}

void	ft_origins(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->mlx_win = mlx_new_window(data->mlx, x_calc(data->a),
			y_calc(data->a) + 60, "サムライダッシュ");
	fileimage(data);
	fileimage_samou(data);
}

void	init_game(char *map_path, t_data data)
{
	char	*map;

	map = save_map(map_path);
	data.a = ft_split(map, '\n');
	data.column = ft_count_line(data.a);
	if (ft_checkall_file(map_path, map, data.a, &data) == 0)
	{
		free(map);
		ft_free_map_checker(data.a, NULL, &data);
		return ;
	}
	free(map);
	if (ft_checkall_map(data.a, &data) == 0)
		return ;
	ft_origins(&data);
	data.line = ft_count_line(data.a);
	display_map(&data);
	init_coin(&data);
	mlx_loop_hook(data.mlx, sprite_anim, &data);
	data.is_init = 1;
	mlx_string_put(data.mlx, data.mlx_win, 100,
		y_calc(data.a) + 20, 0xFFFFFFFF, "Samourai Dash");
	mlx_on_event(data.mlx, data.mlx_win, MLX_WINDOW_EVENT, window_hook, &data);
	mlx_on_event(data.mlx, data.mlx_win, MLX_KEYDOWN, (void *)key_hook, &data);
	mlx_loop(data.mlx);
}

int	create_game(char *map_path, char **av)
{
	t_data	data;

	data.avm = av;
	data.yy = 0;
	data.xx = 0;
	data.coin = 0;
	data.coin_act = 0;
	data.sprite_state = 0;
	data.sprite_on = 0;
	data.is_init = 0;
	data.sound = 0;
	data.check_mob = 0;
	data.score = 0;
	data.column = 0;
	data.a = NULL;
	data.start_time = (clock() * 1000) / CLOCKS_PER_SEC;
	data.orientation = 4;
	init_game(map_path, data);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	create_game(av[1], av);
	return (0);
}
