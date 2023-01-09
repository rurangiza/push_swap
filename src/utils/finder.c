/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:32:02 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/09 15:33:27 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_node_position(t_node *list, int content)
{
	t_node	*tmp;
	int		index;

	tmp = list->next;
	index = 0;
	while (tmp)
	{
		if (tmp->content == content)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (-1);
}

int		find_smallest_nbr(t_node *stack_a)
{
	t_node	*current_node;
	int		smallest;

	current_node = stack_a->next;
	smallest = current_node->content;
	while (current_node)
	{
		if (current_node->content < smallest)
			smallest = current_node->content;
		current_node = current_node->next;
	}
	return (smallest);
}

int		find_largest_nbr(t_node *stack_a)
{
	t_node	*current_node;
	int		largest;

	current_node = stack_a->next;
	largest = current_node->content;
	while (current_node)
	{
		if (current_node->content > largest)
			largest = current_node->content;
		current_node = current_node->next;
	}
	return (largest);
}
