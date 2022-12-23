/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:45:12 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/23 19:53:05 by Arsene           ###   ########.fr       */
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

void	handle_100(t_node *stack_a, t_node *stack_b)
{
	(void)stack_a;
	(void)stack_b;
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