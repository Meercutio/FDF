/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:11:08 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:11:09 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*s1;
	unsigned char	c1;
	int				n;

	s1 = (char *)s;
	c1 = (unsigned char)c;
	n = ft_strlen(s);
	while (c1 == '\0' || n >= 0)
	{
		if (s1[n] == c1)
			return (&s1[n]);
		n--;
	}
	return (NULL);
}
