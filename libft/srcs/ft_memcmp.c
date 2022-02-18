/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:09 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:09:10 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (n--)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		else
		{
			d1++;
			d2++;
		}
	}
	return (0);
}
