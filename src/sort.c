/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:45:12 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/24 17:57:10 by Arsene           ###   ########.fr       */
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

int	is_sorted(t_node *stack_a)
{
	int	prev_largest;
	
	if (stack_a->next == NULL)
		return (1);
	stack_a = stack_a->next;
	prev_largest = stack_a->content;
	while(stack_a)
	{
		if (stack_a->content < prev_largest)
			return (0);
		prev_largest = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}

int		find_smallest_nbr(t_node *stack_a)
{
	t_node	*current_node;
	int		smallest;

	current_node = stack_a->next;
	smallest = current_node->content;
	while (current_node)
	{
		if (current_node->content < smallest)
			smallest = current_node->content;
		current_node = current_node->next;
	}
	return (smallest);
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

int	calc_average(t_node *stack_a)
{
	int	stack_size;
	int	sum;
	int	average;

	stack_size = get_list_size(stack_a);
	sum = 0;
	while (stack_a)
	{
		sum += stack_a->content;
		stack_a = stack_a->next;
	}
	average = sum / stack_size;
	return (average);
}

int	ft_abs(int x)
{
	if (x < 0)
		return -x;
	else
		return (x);
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

void	handle_100(t_node *stack_a, t_node *stack_b)
{
	int	pivot;

	if (get_list_size(stack_a) < 2)
		return ;
	else
	{
		pivot = find_pivot(stack_a);
		partition()
		handle
	}
	// Base case
	// if (stack_size < 2)
	// 	return ;
	// Find a good pivot element
		// Calculate average of all numbers (+  Find size of the stack)
		// Find closest number to the average
		// Set that number as pivot
	// Move items around the pivot element (left = smaller, right = bigger)
}

void	sort(t_node *stack_a, t_node *stack_b)
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