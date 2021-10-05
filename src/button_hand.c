/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:20:04 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/30 17:20:05 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_key(int key)
{
	return (key == 126 || key == 125 || key == 124 || key == 123);
}

void	exec_key(int key, t_mtx *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 123)
		data->shift_x -= 10;
}

void	full_black(t_mtx *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < 1920)
	{
		while (++j < 1080)
			my_mlx_pixel_put(&data->img, i, j, 0);
		j = -1;
	}
}

void	free_data_z(t_mtx *data)
{
	int	i;

	i = data->height - 1;
	while (i >= 0)
	{
		free(data->z_matrix[i]);
		i--;
	}
	free(data->z_matrix);
}

int	ft_deal_key(int key, t_mtx *data)
{
	if (is_key(key))
	{
		full_black(data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		exec_key(key, data);
		ft_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img, 0, 0);
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_data_z(data);
		free(data);
		exit(0);
	}
	return (0);
}
