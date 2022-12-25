/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:45:12 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/25 17:06:31 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A sorting algorithm is set of instructions used to arrange elements
 * of an array/list in a specific order
 * 
 * Differemt sorting algorithms :
 * - bubble
 * - insertion
 * - selection
 * - quicksort
 * - merge
 * - radix
 * ..
*/

#include "../includes/push_swap.h"

void	sort_stack(t_node *stack_a, t_node *stack_b)
{
	int	stack_size;
	
	(void)stack_b;
	stack_size = get_list_size(stack_a) - 1;

	if (is_sorted(stack_a))
	{
		success_msg(1, "aleready sorted");
		return ;
	}
	if (stack_size <= 3) // 5 cases
		handle_3(stack_a);
	else if (stack_size <= 5)
		handle_5(stack_a, stack_b);
	else if (stack_size <= 100)
		handle_100(stack_a, stack_b);
	/*
	else
		handle_500(stack_a, stack_b);
	*/
}

void	handle_3(t_node *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	
	first = stack_a->next;
	second = first->next;
	third = second->next;
	
	if (first->content > second->content && first->content < third->content)
		sa(stack_a);
	else if (first->content > second->content && second->content > third->content)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first->content > second->content && first->content > third->content)
		ra(stack_a);
	else if (first->content < second->content && first->content < third->content)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first->content < second->content && first->content > third->content)
		rra(stack_a);
}

void	handle_5(t_node *stack_a, t_node *stack_b)
{
	int		smallest;
	t_node	*last_node;
	int		counter;


	counter = (get_list_size(stack_a) - 1) - 3;
	while (counter > 0)
	{
		smallest = find_smallest_nbr(stack_a);
		last_node = get_last_node(stack_a);
		if (last_node->content == smallest)
			rra(stack_a);
		else
		{
			while (stack_a->next->content != smallest)
			{
				ra(stack_a);
			}
		}
		pb(stack_a, stack_b);
		counter--;
	}
	if (!is_sorted(stack_a))
		handle_3(stack_a);
	counter = (get_list_size(stack_b) - 1);
	while (counter > 0)
	{
		pa(stack_a, stack_b);
		counter--;
	}
}

// 8 2 1 7 18 3 4 11 6 12

void	handle_100(t_node *stack_a, t_node *stack_b)
{
	if (get_list_size(stack_a) < 2)
		return ;
	else
		partition(stack_a, stack_b);
	// Base case
	// if (stack_size < 2)
	// 	return ;
	// Find a good pivot element
		// Calculate average of all numbers (+  Find size of the stack)
		// Find closest number to the average
		// Set that number as pivot
	// Move items around the pivot element (left = smaller, right = bigger)
}

