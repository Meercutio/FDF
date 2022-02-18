/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:49 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:09:51 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_proc_percent(t_flags *flags)
{
	size_t	len;

	len = 0;
	if (flags->minus == 1)
		len += ft_putstr_prec("%", 1);
	len += ft_add_width(flags->width, 1, flags->zero);
	if (flags->minus == 0)
		len += ft_putstr_prec("%", 1);
	return (len);
}
