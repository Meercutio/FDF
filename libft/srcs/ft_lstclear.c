/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucile <jlucile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:08:26 by jlucile           #+#    #+#             */
/*   Updated: 2021/09/23 16:08:27 by jlucile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next_elem;

	tmp = *lst;
	while (tmp)
	{
		next_elem = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next_elem;
	}
	*lst = NULL;
}
