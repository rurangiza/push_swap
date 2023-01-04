/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:01 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/04 17:22:07 by arurangi         ###   ########.fr       */
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

void	midpoint_alg(t_node *stack_a, t_node *stack_b)
{
	int		pivot;
	int		pushables;
	int		stack_size;
	t_node *first;
	//int		*chunks;
	//int		index;

	stack_size = get_list_size(stack_a) - 1;
	//chunks = malloc(sizeof(int) * divisions_by_two(stack_size)); 
	//index = 0;

	// Midpoint algorithm for stack_a
	while (stack_size > 5)
	{
		// Find the median
		pivot = find_median(stack_a, 0, stack_size, stack_size);
		// Move elements smaller than median -> stack_b
		pushables = count_pushables(stack_a, pivot, 0, stack_size);
		//chunks[index] = pushables; // Remember different chunks size
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
			// First and Last < pivot
			else if (first->content < pivot && get_last_node(stack_a)->content < pivot)
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
			// First or Last < pivot
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
		//chunks[index] -= pushables;
		//index++;
	}

	if (!is_sorted(stack_a))
		handle_5(stack_a, stack_b);
	/*
	int		largest;
	//t_node	*first_a;
	while (stack_b->next != NULL)
	{
		// Find largest
		largest = find_largest_nbr(stack_b);
		// Move it on top or bottom depending on quickest
		while (stack_b->next->content != largest)
		{
			// Push it to stack_a
			if (find_node_position(stack_b, largest) < (get_list_size(stack_b) - 1) / 2)
				rb(stack_b, stack_a);
			else
				rrb(stack_b, stack_a);
		}
		pa(stack_a, stack_b);
		
		// first_a = stack_a->next;
		// if (first->next != NULL)
		// {
		// 	if (first_a->content > first->next->content)
		// 	{
		// 		break_msg("--- Here");
		// 		sa(stack_a, stack_b);
		// 	}
		// }
		*/
	}
	

	
	// Midpoint algorithm for stack_b
	// stack_size = get_list_size(stack_b) - 1;
	// int chunk_size;
	// t_node *first_b;
	// index -= 1;
	// while (stack_b->next != NULL)
	// {
	// 	chunk_size = chunks[index];
	// 	while (chunk_size > 0)
	// 	{
	// 		pivot = find_median(stack_b, 0, chunk_size, chunk_size);
	// 		break_msg("Midpoint = %d", pivot);
	// 		pushables = count_pushables(stack_b, pivot, 0, chunk_size);
	// 		int	rotations = 0;
	// 		if (chunk_size == 1)
	// 		{
	// 			break_msg("1st case (chunk == 1)");
	// 			break_msg("    pushing (%d) -> A", stack_b->next->content);
	// 			pa(stack_a, stack_b);
	// 			chunk_size--;
	// 		}
	// 		else if (chunk_size == 2)
	// 		{
	// 			break_msg("2nd case (chunk == 2)");
	// 			if (find_largest_nbr(stack_b) != stack_b->next->content)
	// 			{
	// 				break_msg("    swaping (%d)", stack_b->next->content);
	// 				sb(stack_b, stack_a);
	// 			}
	// 			break_msg("    pushing (%d) -> A", stack_b->next->content);
	// 			pa(stack_a, stack_b);
	// 			pa(stack_a, stack_b);
	// 			chunk_size -= 2;
	// 		}
	// 		else
	// 		{
	// 			while (pushables > 0)
	// 			{
	// 				break_msg("3rd case : chunks %d", chunk_size);
	// 				first_b = stack_b->next;
	// 				if (first_b->content > pivot)
	// 				{
	// 					break_msg("    pushing (%d) -> A", stack_b->next->content);
	// 					pa(stack_a, stack_b);
	// 					pushables--;
	// 					chunk_size--;
	// 				}
	// 				else if (first_b->content == pivot && pushables == 1)
	// 				{
	// 					break_msg("    pushing midpoint (%d) -> A", stack_b->next->content);
	// 					pa(stack_a, stack_b);
	// 					pushables--;
	// 					chunk_size--;
	// 				}
	// 				else
	// 				{
	// 					rb(stack_b, stack_a);
	// 					rotations++;
	// 				}
	// 			}
	// 			while (rotations > 0 && index != 0) // Not last chunk
	// 			{
	// 				rrb(stack_b, stack_a);
	// 				rotations--;
	// 			}
	// 		}
	// 	}
	// 	index--;
	// 	stack_size = get_list_size(stack_b) - 1;
	// }
	//break_msg("Finished!");
	//break_msg("Selection sort..");
	//quicksort(stack_a, get_list_size(stack_a) - 1, stack_b);
	/*
}
	*/
