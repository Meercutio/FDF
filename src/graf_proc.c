/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graf_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:20:11 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/30 17:20:12 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_isometric(float *x, float *y, int z, t_mtx *data)
{
	float	tmp;

	tmp = *x;
	*x = (*x - *y) * cosf(data->angle);
	*y = (tmp + *y) * sinf(data->angle) - (float)z;
}
