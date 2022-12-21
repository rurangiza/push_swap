/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:53:44 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/21 09:39:55 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Linked Lists Operations
*/

#include "../includes/push_swap.h"

t_dllist	*dll_create_node(int content)
{
	t_dllist	*node;

	node = (t_dllist *)malloc(sizeof(t_dllist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	dll_add_back(t_dllist **lst, t_dllist *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

#include "libft.h"

void	dll_clear_all(t_dllist **lst, void (*del)(void *))
{
	t_dllist	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
		tmp = *lst;
	}
	*lst = 0;
}

void	dll_clear_one(t_dllist *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}