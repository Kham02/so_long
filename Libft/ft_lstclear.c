/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:39:46 by abernita          #+#    #+#             */
/*   Updated: 2022/03/12 15:49:11 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current = *lst;
		next_lst = current->next;
		ft_lstdelone(current, del);
		*lst = next_lst;
	}
}
