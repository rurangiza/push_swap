/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:47:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/29 16:49:14 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * In computer science, partitioning refers to the division of a computer's
 * hard drive, or other data storage device, into separate areas
 * where data can be stored. 
 * These separate areas are called "partitions."
*/

/*
 * In the Quicksort algorithm, paritioning is the process of finding a pivot
 * number in an array, and arranging that array so that all the numbers
 * smaller than the pivot are to its left, and all the numbers bigger than
 * the pivot are on its right. 
 * And then applying that same process to each side (recusrively or
 * iteratively) until the entire array is sorted
*/

#include "../includes/push_swap.h"

void	quicksort(t_node *stack_a, t_node *stack_b, int start, int end)
{
	int		pivot;
	int		stack_size;
	int     pushables;
	int		sorted_items;
	//int     rotated_items;

	stack_size = end - start;

	// Base case
	if (start >= end)
		return ;
	
	

	// Find pivot
	pivot = find_median(stack_a, start, end, stack_size);
	success_msg(0, "pivot = %d", pivot);
	usleep(1000000);

	// Move sorted elements
	sorted_items = 0;
	while (sorted_items < start)
	{
		ra(stack_a, stack_b);
		sorted_items++;
	}
	
	/*
	// Base case 3
	if (stack_size == 3)
		handle_3_any(stack_a);
	*/

	// Cutoff
	if (stack_size <= 50)
	{
		handle_15(stack_a, stack_size, stack_b);
		while (sorted_items > 0)
		{
			rra(stack_a, stack_b);
			sorted_items--;
		}
		//ra(stack_a, stack_b);
		return ;
	}

	// -> stack B
	pushables = count_pushables(stack_a, pivot, 0, end - start);
	push_to_b(stack_a, stack_b, pushables, pivot);
	// rotated_items = push_to_b(stack_a, stack_b, pushables, pivot);	
	// while (rotated_items-- > 0)
	// 	rra(stack_a, stack_b);

	// Move pivot to top of stack_a
	move_pivot_ontop(stack_a, pivot, stack_b);
	
	
	// stack A <-
	while (stack_b->next != NULL)
	{
		int largest = find_largest_nbr(stack_b);
		if (stack_b->next->content != largest)
		{
			if (find_node_position(stack_b, largest) < get_list_size(stack_b) / 2)
				rb(stack_b, stack_a);
			else
				rrb(stack_b, stack_a);
		}
		else
			pa(stack_a, stack_b);
	}
	
	// Move back sorted items
	while (sorted_items > 0)
	{
		rra(stack_a, stack_b);
		sorted_items--;
	}

	// Recall quicksort
	int pivot_index = find_node_position(stack_a, pivot);
	if (!is_sorted_recursive(stack_a, start, pivot_index))
		quicksort(stack_a, stack_b, start, pivot_index);
	if (!is_sorted_recursive(stack_a, pivot_index + 1, end))
		quicksort(stack_a, stack_b, pivot_index + 1, end);
	
}

int	push_to_b(t_node *stack_a, t_node *stack_b, int elements_to_push, int pivot)
{
	int	rotation_counter;

	rotation_counter = 0;
	while (elements_to_push > 0)
	{
		if (stack_a->next->content < pivot)
		{
			pb(stack_a, stack_b);
			elements_to_push--;
		}
		else
		{
			ra(stack_a, stack_b);
			rotation_counter++;
		}
	}
	return (rotation_counter);
}

void    move_pivot_ontop(t_node *stack_a, int pivot, t_node *stack_b)
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
	while (rotated_items != 0)
	{
		if (closer_to == _top)
		{
			rra(stack_a, stack_b);
			sa(stack_a, stack_b);
		}
		else
		{
			sa(stack_a, stack_b);
			ra(stack_a, stack_b);
		}
		rotated_items--;
	}
}


