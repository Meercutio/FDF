/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:20:15 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/30 17:20:16 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

float	ft_max(float num1, float num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}
