/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:45:12 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/26 22:29:22 by Arsene           ###   ########.fr       */
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
	int	start;
	int	end;
	
	(void)stack_b;
	stack_size = get_list_size(stack_a) - 1;

	if (is_sorted(stack_a))
	{
		success_msg(1, "aleready sorted");
		return ;
	}
	if (stack_size <= 3) // 5 cases
		handle_3(stack_a, stack_b);
	else if (stack_size <= 5)
		handle_5(stack_a, stack_b);
	/*
	else if (stack_size <= )
	{
		info_msg(0, "handling 15 case...");
		handle_15(stack_a, stack_size, stack_b);
	}
	*/
	else if (stack_size <= 100)
	{
		start = 0;
		//info_msg(0, "list size = %d", get_list_size(stack_a));
		end = get_list_size(stack_a) - 1;
		quicksort(stack_a, stack_b, start, end);
	}
}

void	handle_15(t_node *stack_a, int stack_size, t_node *stack_b)
{
	/*
	(void)stack_size;
	display_stack(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	rrb(stack_b, stack_a);
	*/
	
	int	largest;
	int	elements_to_push;

	// Move elements to stack_b
	elements_to_push = stack_size;
	while (elements_to_push != 0)
	{
		pb(stack_a, stack_b);
		elements_to_push--;
	}

	// Repeat until empty
	while (stack_b->next != NULL)
	{
		// find largest
		largest = find_largest_nbr(stack_b);
		// rb or rrb until reach the largest
		if (stack_b->next->content != largest)
		{
			if (find_node_position(stack_b, largest) < stack_size / 2)
				rb(stack_b, stack_a);
			else
				rrb(stack_b, stack_a);
		}
		else
			pa(stack_a, stack_b);
	}
	
}

void	handle_3(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	
	first = stack_a->next;
	second = first->next;
	third = second->next;
	
	if (first->content > second->content && first->content < third->content)
		sa(stack_a, stack_b);
	else if (first->content > second->content && second->content > third->content)
	{
		sa(stack_a, stack_b);
		rra(stack_a, stack_b);
	}
	else if (first->content > second->content && first->content > third->content)
		ra(stack_a, stack_b);
	else if (first->content < second->content && first->content < third->content)
	{
		sa(stack_a, stack_b);
		ra(stack_a, stack_b);
	}
	else if (first->content < second->content && first->content > third->content)
		rra(stack_a, stack_b);
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
			rra(stack_a, stack_b);
		else
		{
			while (stack_a->next->content != smallest)
			{
				ra(stack_a, stack_b);
			}
		}
		pb(stack_a, stack_b);
		counter--;
	}
	if (!is_sorted(stack_a))
		handle_3(stack_a, stack_b);
	counter = (get_list_size(stack_b) - 1);
	while (counter > 0)
	{
		pa(stack_a, stack_b);
		counter--;
	}
}

// 8 2 1 7 18 3 4 11 6 12


