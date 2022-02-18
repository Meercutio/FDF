/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:11:44 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:11:45 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *file_name)//y
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		ft_error("something wrong");
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)//x
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_mtx *data)
{
	int		fd;
	int		i;
	char	*line;

	check_dir(file_name);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **) malloc(sizeof (int *) * (data->height + 1));//указатель на указатели (коробки)
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *) malloc(sizeof (int) * (data->width + 1));//для каждой коробки
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	data->z_matrix[i] = NULL;
	close(fd);
}
