/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:32:02 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/09 16:56:51 by arurangi         ###   ########.fr       */
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

int	find_smallest_nbr(t_node *stack_a)
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

int	find_largest_nbr(t_node *stack_a)
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

void	bring_closest_pushable_ontop(t_node *stack_a, t_node *stack_b,
			int pivot)
{
	t_node	*front;
	t_node	*back;
	int		front_counter;
	int		back_counter;

	front = stack_a->next;
	back = get_last_node(stack_a);
	front_counter = 0;
	while (front->content >= pivot && front != NULL)
	{
		front_counter++;
		front = front->next;
	}
	back_counter = 0;
	while (back->content >= pivot && back != NULL)
	{
		back_counter++;
		back = back->previous;
	}
	if (front_counter <= back_counter)
		ra(stack_a, stack_b);
	else
		rra(stack_a, stack_b);
}
