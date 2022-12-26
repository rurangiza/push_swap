/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:47:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/26 22:31:43 by Arsene           ###   ########.fr       */
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
		
	//info_msg(0, "quicksort %d", counterGlobal++);

	(void)stack_b;
	
	pivot = find_pivot(stack_a, start, end, stack_size);
	
	
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

	// Recursion
	int pivot_index = find_node_position(stack_a, pivot);
	if (!is_sorted_recursive(stack_a, start, pivot_index))
		quicksort(stack_a, stack_b, start, pivot_index);
	if (!is_sorted_recursive(stack_a, pivot_index + 1, end))
		quicksort(stack_a, stack_b, pivot_index + 1, end);
	
}



int	find_pivot(t_node *stack_a, int start, int end, int stack_size)
{
	int	closest;
	int	closest_number;
	int	target;
	int	position;

	target = calc_average(stack_a, start, end, stack_size);
	//target = calc_medthree(stack_a, start, end);
	//return (success_msg(target, "pivot = %d", target));
	
	//info_msg(0, "head: %d", stack_a->next->content);
	//info_msg(0, "target : %d", target);
	closest = INT_MAX;
	closest_number = 0;
	stack_a = stack_a->next;
	position = 0;
	while (stack_a && (position - start < stack_size))
	{
		if (position >= start)
		{
			if (ft_abs(stack_a->content - target) < ft_abs(closest - target))
			{
				closest = stack_a->content;
				closest_number = stack_a->content;
			}
		}
		position++;
		stack_a = stack_a->next;
	}
	//info_msg(0, "closest number : %d", closest_number);
	//pick_best_pivot(stack_a, target, calc_medthree(stack_a, start, end));
	
	return (closest_number);
}

//int	calc_

int	calc_medthree(t_node *stack_a, int start, int end)
{
	int	stack_size = end - start;
	int	medthree[3];
	int	mt_index = 0;
	int	index = 0;

	// medthree up three random numbers
	stack_a = stack_a->next;
	while (stack_a && (index - start < stack_size))
	{
		if (index >= start)
		{
			if (index == start || index == stack_size / 2 || index == end - 1)
			{
				medthree[mt_index] = stack_a->content;
				mt_index++;
			}
		}
		index++;
		stack_a = stack_a->next;
	}
	// Calculate average of those three
	//medthree /= 3;
	// Pick the middle of the three
	mt_index = 0;
	while (mt_index < 3)
	{
		int j = 0;
		int smaller = 0;
		int larger = 0;
		while (j < 3)
		{
			if (j != mt_index)
			{
				if (medthree[j] < medthree[mt_index])
					smaller++;
				else
					larger++;
			}
			j++;
		}
		if (smaller > 0 && larger > 0)
			return (medthree[mt_index]);
		mt_index++;
	}
	
	return (error_msg(-1, "no mid found in calc_medthree"));
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


