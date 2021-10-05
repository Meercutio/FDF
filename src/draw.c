/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:11:37 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:11:38 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_color(int z1, int z2, t_mtx *data)
{
	if (z1 || z2)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	add_shift(t_coord *coord, t_mtx *data)
{
	coord->fx1 += data->shift_x;
	coord->fx2 += data->shift_x;
	coord->fy1 += data->shift_y;
	coord->fy2 += data->shift_y;
}

void	set_param(t_coord *coord, t_mtx *data)
{
	coord->fx1 = coord->x1;
	coord->fx2 = coord->x2;
	coord->fy1 = coord->y1;
	coord->fy2 = coord->y2;
	coord->fx1 *= data->zoom;
	coord->fx2 *= data->zoom;
	coord->fy1 *= data->zoom;
	coord->fy2 *= data->zoom;
}

void	bresenham(t_coord coord, t_mtx *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z[2];

	set_param(&coord, data);
	z[0] = data->z_matrix[coord.y1][coord.x1];
	z[1] = data->z_matrix[coord.y2][coord.x2];
	add_color(z[0], z[1], data);
	ft_isometric(&coord.fx1, &coord.fy1, z[0], data);
	ft_isometric(&coord.fx2, &coord.fy2, z[1], data);
	add_shift(&coord, data);
	x_step = coord.fx2 - coord.fx1;
	y_step = coord.fy2 - coord.fy1;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(coord.fx1 - coord.fx2) || (int)(coord.fy1 - coord.fy2))
	{
		if (coord.fx1 >= 0 && coord.fx1 < 1920
			&& coord.fy1 >= 0 && coord.fy1 < 1080)
			my_mlx_pixel_put(&data->img, coord.fx1, coord.fy1, data->color);
		coord.fx1 += x_step;
		coord.fy1 += y_step;
	}
}

void	ft_draw(t_mtx *data)
{
	t_coord	coord;

	coord.y1 = 0;
	while (coord.y1 < data->height)
	{
		coord.x1 = 0;
		while (coord.x1 < data->width)
		{
			if (coord.x1 < data->width - 1)
			{
				coord.x2 = coord.x1 + 1;
				coord.y2 = coord.y1;
				bresenham(coord, data);
			}
			if (coord.y1 < data->height - 1)
			{
				coord.x2 = coord.x1;
				coord.y2 = coord.y1 + 1;
				bresenham(coord, data);
			}
			coord.x1++;
		}
		coord.y1++;
	}
}
