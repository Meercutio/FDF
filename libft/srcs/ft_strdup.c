/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:10:37 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:10:38 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s1);
	ptr = (char *)malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, n + 1);
	return (ptr);
}
