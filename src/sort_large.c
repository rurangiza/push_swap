/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:35:49 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 07:16:44 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	large_sort(t_node *stack_a, t_node *stack_b)
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
		if (stack_size > 100)
			pivot = find_octile(stack_a, 0, stack_size, stack_size);
		else
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
	break_msg("5 Hundred Triage");
	if (!is_sorted(stack_a))
		small_sort(stack_a, stack_b);
	
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
	/*
	*/
}
