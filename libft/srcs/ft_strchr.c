/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:10:32 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:10:33 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s1;
	unsigned char	c1;

	s1 = (char *)s;
	c1 = (unsigned char)c;
	while (*s1 || c1 == '\0')
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	return (NULL);
}
