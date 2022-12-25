/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:47:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 16:56:38 by Arsene           ###   ########.fr       */
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

void	partition(t_node *stack_a, t_node *stack_b)
{
	int		pivot;
	int     pushables;
	int     rotated_items;

	pivot = find_pivot(stack_a);
	// Count number of items to push
    pushables = count_pushables(stack_a, pivot);
	// Push items to stack_b (or move out of the way)
	rotated_items = push_to_b(stack_a, stack_b, pushables, pivot);
	// Replace back in order
	while (rotated_items-- > 0)
		rra(stack_a);
	// Move pivot to top of stack_a
    move_pivot_ontop(stack_a, pivot);
	// Send back all numbers in stack_b to stack_a
	while (stack_b->next != NULL)
		pa(stack_a, stack_b);
	// 
}

int	find_pivot(t_node *stack_a)
{
	int	closest;
	int	closest_number;
	int	target;

	target = calc_average(stack_a);
	
	closest = INT_MAX;
	closest_number = 0;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (ft_abs(stack_a->content - target) < ft_abs(closest - target))
		{
			closest = stack_a->content;
			closest_number = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (closest_number);
}

int	push_to_b(t_node *stack_a, t_node *stack_b, int elements_to_push, int pivot)
{
	int	rotation_counter;;

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
			ra(stack_a);
			rotation_counter++;
		}
	}
	return (rotation_counter);
}

void    move_pivot_ontop(t_node *stack_a, int pivot)
{
    int pivot_position;
	int	stack_size;

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
}


