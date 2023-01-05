/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:01 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/05 11:51:50 by arurangi         ###   ########.fr       */
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

int	closest_pushable(t_node *stack, int pivot)
{
	t_node	*front;
	t_node	*back;
	int		front_counter;
	int		back_counter;
	
	front = stack->next;
	front_counter = 0;
	while (front != NULL)
	{
		if (front->content < pivot)
			break ;
		front_counter++;
		front = front->next;
	}
	
	back = get_last_node(stack);
	back_counter = 0;
	while (back != NULL)
	{
		if (back->content < pivot)
			break ;
		back_counter++;
		back = back->previous;
	}
	if (front_counter < back_counter)
		return (_top);
	return (_bottom);
}

void	handle_100(t_node *stack_a, t_node *stack_b)
{
	int		pivot;
	int		pushables;
	int		stack_size;
	t_node	*first;
	t_node	*last;

	// Push -> stack_b (smallest first)
	stack_size = get_list_size(stack_a) - 1;
	while (stack_size > 5)
	{
		// Find the pivot
		pivot = find_quartile(stack_a, 0, stack_size, stack_size);
		// Push numbers < pivot -> stack_b (smallest first)
		pushables = count_pushables(stack_a, pivot, 0, stack_size);
		while (pushables > 0 && stack_size > 5)
		{
			first = stack_a->next;
			last = get_last_node(stack_a);
			// First && Last < pivot
			if (first->content < pivot && last->content < pivot)
			{
				if (first->content < last->content)
					pb(stack_a, stack_b);
				else
				{
					rra(stack_a, stack_b);
					pb(stack_a, stack_b);
				}
				pushables--;
			}
			// First || Last < pivot
			else if (first->content < pivot || last->content < pivot)
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
