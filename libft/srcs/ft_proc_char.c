/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:38 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:09:39 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_proc_char(t_flags *flags, char c)
{
	size_t	len;

	len = 0;
	if (flags->minus == 1)
		write(1, &c, 1);
	len += ft_add_width(flags->width, 1, flags->zero);
	if (flags->minus == 0)
		write(1, &c, 1);
	len++;
	return (len);
}
