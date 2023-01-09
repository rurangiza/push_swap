/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:30:46 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 16:49:12 by arurangi         ###   ########.fr       */
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
	while (stack_a)
	{
		if (stack_a->content < prev_largest)
			return (0);
		prev_largest = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_sorted_asc(t_node *stack, int start, int end)
{
	int	current_largest;
	int	stack_size;
	int	index;

	index = 0;
	stack_size = end - start;
	if (stack->next == NULL)
		return (1);
	stack = stack->next;
	current_largest = INT_MIN;
	while (stack && (index - start < stack_size))
	{
		if (index >= start)
		{
			if (stack->content < current_largest)
				return (0);
			current_largest = stack->content;
		}
		index++;
		stack = stack->next;
	}
	return (1);
}

int	is_sorted_desc(t_node *stack, int start, int end)
{
	int	current_smallest;
	int	index;
	int	stack_size;

	index = 0;
	stack_size = end - start;
	if (stack->next == NULL)
		return (1);
	stack = stack->next;
	current_smallest = INT_MAX;
	while (stack && (index - start < stack_size))
	{
		if (index >= start)
		{
			if (stack->content > current_smallest)
				return (0);
			current_smallest = stack->content;
		}
		index++;
		stack = stack->next;
	}
	return (1);
}
