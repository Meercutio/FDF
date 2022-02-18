/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:14:15 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:14:16 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mtx
{
	int		height;//y
	int		width;//x
	int		**z_matrix;//z
	int		zoom;
	int 	color;
	int		shift_x;
	int 	shift_y;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
}				t_mtx;

typedef struct	s_coord
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	float	fx1;
	float	fy1;
	float	fx2;
	float	fy2;
}	t_coord;

void	read_file(char *file_name, t_mtx *data);
void	bresenham(t_coord coord, t_mtx *data);
void	ft_draw(t_mtx *data);
int		ft_deal_key(int key, t_mtx *data);
float	ft_max(float num1, float num2);
float	ft_abs(float num);
void	ft_isometric(float *x, float *y, int z, t_mtx *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_error(char *msg);
void	free_data_z(t_mtx *data);
void	check_dir(char *file_name);

# endif
