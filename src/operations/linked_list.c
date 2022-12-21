/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:53:44 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/21 14:51:02 by arurangi         ###   ########.fr       */
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
	get_last_node(*lst)->next = new;
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

/*
 * Copie every node of a linked list
 * into a new linked list
 * after modifying the content of each node with a given function
*/
void	duplicate_linkedlist(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;

	if (!stack_a)
		error_msg(0, "%duplicate_linkedlist: stack_a is empty");
	while (stack_a)
	{
		tmp = malloc(sizeof(t_node));
		if (!tmp)
			delete_all_nodes(&stack_b);
		else
		{
			tmp->content = stack_a->content;
			tmp->next = NULL;
			add_back(&stack_b, tmp);
		}
		stack_a = stack_a->next;
	}
}