/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:59:30 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/06 13:27:35 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



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
			// 1st case: First && Last < pivot
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
			// 2nd case: First || Last < pivot
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
			// 3rd case: look for next pushable
			else
				ra(stack_a, stack_b);

			// swap top 2 numbers in stack_b (keep largest above)
			if ((get_list_size(stack_b) - 1) >= 2)
			{
				t_node *first_b;
				t_node *second_b;

				if (stack_b->next->content < get_last_node(stack_b)->content)
					rb(stack_b, stack_a);
				
				first_b = stack_b->next;
				second_b = first_b->next;
				if (first_b->content < second_b->content)
					sb(stack_b, stack_a);
			}
				//sort_trio(stack_a, stack_b);
			
			// Update stack_size
			stack_size = get_list_size(stack_a) - 1;
		}
	}

	// Sort stack_a	
	if (!is_sorted(stack_a))
		handle_5(stack_a, stack_b);
	
	// Push -> stack_a (largest first)
	/*
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
	*/
}