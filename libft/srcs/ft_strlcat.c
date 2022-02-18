/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:10:44 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:10:45 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (src == NULL && dst == NULL)
		return (0);
	while (i < d)
	{
		dst++;
		i++;
	}
	if (d < (dstsize - 1) && dstsize > 0)
	{	
		i = 0;
		while (*src && (d + i++) < (dstsize - 1))
			*dst++ = *src++;
		*dst = '\0';
	}
	if (d >= dstsize)
		d = dstsize;
	return (d + s);
}
