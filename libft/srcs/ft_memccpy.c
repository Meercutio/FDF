/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:00 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:09:01 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	c1 = (unsigned char)c;
	while (n--)
	{
		*dst1++ = *src1++;
		if (*(dst1 - 1) == c1)
			return (dst1);
	}
	return (NULL);
}
