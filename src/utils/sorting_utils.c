/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:30:46 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/26 15:59:49 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_node *stack_a)
{
	int	prev_largest;
	
	if (stack_a->next == NULL)
		return (1);
	stack_a = stack_a->next;
	prev_largest = stack_a->content;
	while(stack_a)
	{
		if (stack_a->content < prev_largest)
			return (0);
		prev_largest = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_sorted_recursive(t_node *stack_a, int start, int end)
{
	int	prev_largest;
	int	stack_size;
	int	position;

	position = 0;
	stack_size = end - start;
	
	if (stack_a->next == NULL)
		return (1);
	stack_a = stack_a->next;
	prev_largest = INT_MIN;
	while(stack_a && (position - start < stack_size))
	{
		if (position >= start)
		{
			if (stack_a->content < prev_largest)
				return (0);
			prev_largest = stack_a->content;
		}
		position++;
		stack_a = stack_a->next;
	}
	return (1);
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