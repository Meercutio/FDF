/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:11:40 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:11:41 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_param_z_a(t_mtx *data)
{
	data->zoom = 10;
	data->angle = 0.55;
	data->shift_x = 200;
	data->shift_y = 200;
}

int	main(int argc, char **argv)
{
	t_mtx	*data;

	if (argc == 2)
	{
		data = (t_mtx *) malloc(sizeof(t_mtx));
		set_param_z_a(data);
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->img.img = mlx_new_image(data->mlx_ptr, 1920, 1080);
		data->img.addr = mlx_get_data_addr(data->img.img,
				   &data->img.bits_per_pixel, &data->img.line_length,
				   &data->img.endian);
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
		ft_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img, 0, 0);
		mlx_key_hook(data->win_ptr, ft_deal_key, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		exit(1);
}
