/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:47:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/27 14:55:12 by arurangi         ###   ########.fr       */
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

//int counterGlobal = 0;

void	quicksort(t_node *stack_a, t_node *stack_b, int start, int end)
{
	int		pivot;
	int		stack_size;
	int     pushables;
	int		sorted_items;
	int     rotated_items;

	// Base case
	if (start >= end)
		return ;
	
	stack_size = end - start;
		
	(void)stack_b;
	
	//pivot = find_pivot(stack_a, start, end, stack_size);
	pivot = find_median(stack_a, start, end, stack_size);

	// Count number of items to push
	pushables = count_pushables(stack_a, pivot, start, end);
	// Send to back already sorted items
	sorted_items = 0;
	while (sorted_items < start)
	{
		ra(stack_a, stack_b);
		sorted_items++;
	}
	// Cutoff 
	if (stack_size <= 50)
	{
		handle_15(stack_a, stack_size, stack_b);
		while (sorted_items > 0)
		{
			rra(stack_a, stack_b);
			sorted_items--;
		}
		return ;
	}
	// Push items to stack_b (or move out of the way)
	rotated_items = push_to_b(stack_a, stack_b, pushables, pivot, stack_size);
	// Replace back in order
	while (rotated_items-- > 0)
		rra(stack_a, stack_b);
	// Move pivot to top of stack_a
	move_pivot_ontop(stack_a, pivot, stack_b);
	// Send back all numbers in stack_b to stack_a
	while (stack_b->next != NULL)
		pa(stack_a, stack_b);
	// Move back sorted items
	while (sorted_items > 0)
	{
		rra(stack_a, stack_b);
		sorted_items--;
	}

	int pivot_index = find_node_position(stack_a, pivot);
	if (!is_sorted_recursive(stack_a, start, pivot_index))
		quicksort(stack_a, stack_b, start, pivot_index);
	if (!is_sorted_recursive(stack_a, pivot_index + 1, end))
		quicksort(stack_a, stack_b, pivot_index + 1, end);
}

int	push_to_b(t_node *stack_a, t_node *stack_b, int elements_to_push, int pivot, int stack_size)
{
	int	rotation_counter;;

	rotation_counter = 0;
	while (elements_to_push > 0 && stack_size != 0)
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
		stack_size--;
	}
	return (rotation_counter);
}

void    move_pivot_ontop(t_node *stack_a, int pivot, t_node *stack_b)
{
    //int pivot_position;
	//int	stack_size;
	int	rotated_items;

	rotated_items = 0;
	while (stack_a->next->content != pivot)
	{
		ra(stack_a, stack_b);
		rotated_items++;
	}
	while (rotated_items != 0)
	{
		rra(stack_a, stack_b);
		sa(stack_a, stack_b);
		rotated_items--;
	}
	/*
	stack_size = get_list_size(stack_a);
    pivot_position = find_node_position(stack_a, pivot);
	if (pivot_position == -1)
		return ;
	while (stack_a->next->content != pivot)
	{
		if (pivot_position < stack_size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	*/
}


