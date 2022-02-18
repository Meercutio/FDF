/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:25 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:09:26 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	c1;

	b1 = (unsigned char *)b;
	c1 = (unsigned char)c;
	i = 0;
	while (len)
	{
		b1[i] = c1;
		len--;
		i++;
	}
	return (b);
}
