/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:01:47 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/11 15:36:24 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fileimage2(t_data *data)
{
	int	img_width;
	int	img_height;

	data->img[9] = mlx_png_file_to_image(data->mlx,
			"sprite/intro2.png", &img_width, &img_height);
	data->img[10] = mlx_png_file_to_image(data->mlx,
			"sprite/grave.png", &img_width, &img_height);
	data->img[11] = mlx_png_file_to_image(data->mlx,
			"sprite/floorv.png", &img_width, &img_height);
	data->img[12] = mlx_png_file_to_image(data->mlx,
			"sprite/floorv2.png", &img_width, &img_height);
	data->img[13] = mlx_png_file_to_image(data->mlx,
			"sprite/hollow_front.png", &img_width, &img_height);
	data->img[14] = mlx_png_file_to_image(data->mlx,
			"sprite/hollow_back.png", &img_width, &img_height);
	data->img[15] = mlx_png_file_to_image(data->mlx,
			"sprite/hollow_left.png", &img_width, &img_height);
	data->img[16] = mlx_png_file_to_image(data->mlx,
			"sprite/hollow_right.png", &img_width, &img_height);
	data->img[17] = mlx_png_file_to_image(data->mlx,
			"sprite/soul2.png", &img_width, &img_height);
	data->img[18] = mlx_png_file_to_image(data->mlx,
			"sprite/tp.png", &img_width, &img_height);
	data->img[19] = mlx_png_file_to_image(data->mlx,
			"sprite/black.png", &img_width, &img_height);
}

void	fileimage(t_data *data)
{
	int	img_width;
	int	img_height;

	data->img = malloc(sizeof(void *) * 30);
	data->img[0] = mlx_png_file_to_image(data->mlx,
			"sprite/floor2.png", &img_width, &img_height);
	data->img[1] = mlx_png_file_to_image(data->mlx,
			"sprite/wall.png", &img_width, &img_height);
	data->img[2] = mlx_png_file_to_image(data->mlx,
			"sprite/wallv.png", &img_width, &img_height);
	data->img[3] = mlx_png_file_to_image(data->mlx,
			"sprite/wallv2.png", &img_width, &img_height);
	data->img[4] = mlx_png_file_to_image(data->mlx,
			"sprite/vase.png", &img_width, &img_height);
	data->img[5] = mlx_png_file_to_image(data->mlx,
			"sprite/soul.png", &img_width, &img_height);
	data->img[6] = mlx_png_file_to_image(data->mlx,
			"sprite/exit.png", &img_width, &img_height);
	data->img[7] = mlx_png_file_to_image(data->mlx,
			"sprite/exitoff.png", &img_width, &img_height);
	data->img[8] = mlx_png_file_to_image(data->mlx,
			"sprite/intro1.png", &img_width, &img_height);
	fileimage2(data);
}

void	fileimage_samou(t_data *data)
{
	int	img_width;
	int	img_height;

	data->img2 = malloc(sizeof(void *) * 20);
	data->img2[0] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_right1.png", &img_width, &img_height);
	data->img2[1] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_right2.png", &img_width, &img_height);
	data->img2[2] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_back1.png", &img_width, &img_height);
	data->img2[3] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_back2.png", &img_width, &img_height);
	data->img2[4] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_left1.png", &img_width, &img_height);
	data->img2[5] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_left2.png", &img_width, &img_height);
	data->img2[6] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_front1.png", &img_width, &img_height);
	data->img2[7] = mlx_png_file_to_image(data->mlx,
			"sprite/samou/samou_front2.png", &img_width, &img_height);
	data->img2[8] = mlx_png_file_to_image(data->mlx,
			"sprite/floor_sh.png", &img_width, &img_height);
	data->img2[9] = mlx_png_file_to_image(data->mlx,
			"sprite/floor_sh2.png", &img_width, &img_height);
}
