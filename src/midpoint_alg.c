/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:01 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/03 17:02:15 by arurangi         ###   ########.fr       */
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
	int		*chunks;
	int		index;

	stack_size = get_list_size(stack_a) - 1;
	chunks = malloc(sizeof(int) * divisions_by_two(stack_size)); 
	index = 0;

	// Midpoint algorithm for stack_a
	while (stack_size > 2)
	{
		// Find the median
		pivot = find_median(stack_a, 0, stack_size, stack_size);
		// Move elements smaller than median -> stack_b
		pushables = count_pushables(stack_a, pivot, 0, stack_size);
		chunks[index] = pushables; // Remeber different chunks size
		while (pushables > 0)
		{
			if (stack_a->next->content < pivot)
			{
				pb(stack_a, stack_b);
				pushables--;
			}
			else if (get_last_node(stack_a)->content < pivot)
			{
				rra(stack_a, stack_b);
				pb(stack_a, stack_b);
				pushables--;
			}
			else
				ra(stack_a, stack_b);
		}
		index++;
		stack_size = get_list_size(stack_a) - 1;
	}
	if (find_largest_nbr(stack_a) == stack_a->next->content)
		sa(stack_a, stack_b);

	// Print result
	for (int i = index - 1; i >= 0; i--)
	{
		info_msg("%d chunks", chunks[i]);
		usleep(1000000);
	}

	// Midpoint algorithm for stack_b
	stack_size = get_list_size(stack_b) - 1;
	while (stack_size > 2)
	{
		break_msg("1st loop");

		index -= 1;
		int chunk_size = chunks[index];
		while (chunk_size > 0)
		{
			pivot = find_median(stack_b, 0, chunk_size, chunk_size);
			pushables = count_pushables(stack_b, pivot, 0, chunk_size);
			int	rotations = 0;
			t_node *first_b = stack_b->next;
			break_msg("-- 2nd loop | chunk_size = %d | pushables = %d", chunk_size, pushables);
			// if (is_sorted_desc(stack_b, 0, chunk_size))
			// {
			// 	while (pushables > 0)
			// 		pa(stack_b, stack_a);
			// }
			if (chunk_size == 1)
				pa(stack_a, stack_b);
			else
			{
				while (pushables > 0)
				{
					break_msg("---- 3rd loop");
					if (first_b->content > pivot)
					{
						pa(stack_b, stack_a);
						pushables--;
						chunk_size--;
					}
					// else if (first_b->content < first_b->next->content)
					// 	sb(stack_b, stack_a);
					else
					{
						rb(stack_b, stack_a);
						rotations++;
					}
				}
				while (rotations > 0 && index != 0) // Not last chunk
				{
					rrb(stack_b, stack_a);
					rotations--;
				}
			}
		}
		index--;
		stack_size = get_list_size(stack_b) - 1;
	}
	break_msg("Finished!");
}
