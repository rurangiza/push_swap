/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:53:44 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/23 11:39:41 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Linked Lists Operations
*/

#include "../../includes/push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	add_back(t_node **lst, t_node *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	//printf("Current: (%d) / ", new->content);
	new->previous = get_last_node(*lst);
	get_last_node(*lst)->next = new;
	//printf("Previous %d\n", new->previous->content);
	new->index = new->previous->index + 1;
}

/*
 * Returns the last node of the list
*/
t_node	*get_last_node(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	delete_all_nodes(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		tmp->content = 0;
		free(tmp);
		tmp = *lst;
	}
	*lst = 0;
}

int	get_list_size(t_node *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
