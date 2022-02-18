/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:07:19 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:07:27 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	long long int	num;
	int				sign;

	num = 0;
	sign = 1;
	while (*str && ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r')))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = (num * 10) + (*str - '0');
		if (num > 2147483647)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		str++;
	}
	return (num * sign);
}
