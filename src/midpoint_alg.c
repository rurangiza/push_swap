/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:01 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/05 11:12:42 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	divisions_by_two(int nbr)
{
	int	count;
	
	count = 0;
	while (nbr > 2)
	{
		nbr /= 2;
		count++;
	}
	return (count);
}

int	is_sorted_desc(t_node *stack, int start, int end)
{
	int	prev_largest;
	int	index;
	int	size;

	size = end - start;
	
	if (stack->next == NULL)
		return (1);
	stack = stack->next;
	index = 0;
	while(stack && (index - start < size))
	{
		if (index >= start)
		{
			if (index == start)
				prev_largest = stack->content;
			else if (stack->content > prev_largest)
				return (0);
			prev_largest = stack->content;
		}
		index++;
		stack = stack->next;
	}
	return (1);
}

void	handle_100(t_node *stack_a, t_node *stack_b)
{
	int		pivot;
	int		pushables;
	int		stack_size;
	t_node *first;
	int pivot_switcher = 0;

	// Push -> stack_b (smallest first)
	stack_size = get_list_size(stack_a) - 1;
	while (stack_size > 5)
	{
		// Find the pivot
		pivot = find_quartile(stack_a, 0, stack_size, stack_size);
		// Push all numbers < median -> stack_b
		pushables = count_pushables(stack_a, pivot, 0, stack_size);
		while (pushables > 0 && stack_size > 5)
		{
			first = stack_a->next;
			// Push pivot instead of last pushable
			if (pushables == 1 && first->next->content < first->content)
			{
				int	rotated_items;
				int	closer_to;

				if (find_node_position(stack_a, pivot) < get_list_size(stack_a) / 2)
					closer_to = _top;
				else
					closer_to = _bottom;

				rotated_items = 0;
				while (stack_a->next->content != pivot)
				{
					if (closer_to == _top)
						ra(stack_a, stack_b);
					else
						rra(stack_a, stack_b);
					rotated_items++;
				}
				pb(stack_a, stack_b); // Push to stack_b
				pushables--;
			}
			
			// First && Last < pivot
			if (first->content < pivot && get_last_node(stack_a)->content < pivot)
			{
				if (first->content < get_last_node(stack_a)->content)
					pb(stack_a, stack_b);
				else
				{
					rra(stack_a, stack_b);
					pb(stack_a, stack_b);
				}
				pushables--;
			}
			// First || Last < pivot
			else if (first->content < pivot || get_last_node(stack_a)->content < pivot)
			{
				if (first->content < pivot)
					pb(stack_a, stack_b);
				else
				{
					rra(stack_a, stack_b);
					pb(stack_a, stack_b);
				}
				pushables--;
			}
			else
				ra(stack_a, stack_b);
			// Stack_b : keep largest on top
			if ((get_list_size(stack_b) - 1) >= 2)
			{
				t_node *first_b = stack_b->next;
				t_node *second_b = first_b->next;
				if (first->content < get_last_node(stack_b)->content)
					rb(stack_b, stack_a);
				else if (first_b->content < second_b->content)
					sb(stack_b, stack_a);
			}
			stack_size = get_list_size(stack_a) - 1;
		}
		pivot_switcher++;
	}

	// Sort stack_a	
	if (!is_sorted(stack_a))
		handle_5(stack_a, stack_b);
	
	// Push -> stack_a (largest first)
	int		largest;
	int		lgst_position;
	t_node	*first_a;
	while (stack_b->next != NULL)
	{
		largest = find_largest_nbr(stack_b); // Find largest
		lgst_position = find_node_position(stack_b, largest);
		while (stack_b->next->content != largest) // Move it on top or bottom depending on quickest
		{
			if (lgst_position < (get_list_size(stack_b) - 1) / 2)
				rb(stack_b, stack_a);
			else
				rrb(stack_b, stack_a);
		}
		pa(stack_a, stack_b);
		
		first_a = stack_a->next;
		if (first_a->content > first_a->next->content)
			sa(stack_a, stack_b);
	}
}
