/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:01 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/27 16:48:19 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	midpoint_alg(t_node *stack_a, t_node *stack_b)
{
	int	*array;
	int	array_pos;
	int	median;
	int	stack_size;
	t_node *tmp;

	stack_size = get_list_size(stack_a) - 1;
	
	// Store stack_a in an array
	array = malloc(sizeof(int) * stack_size);
	array_pos = 0;
	info_msg(0, "---> here");
	tmp = stack_a;
	while (tmp != NULL)
	{
		array[array_pos] = tmp->content;
		array_pos++;
		tmp = tmp->next;
	}
	// Sort the array
	selection_sort(array, stack_size);
	// Find the midpoint value
	median = array[(stack_size / 2)];
	
	// Move everything < median -> stack_b
	int pushables = count_pushables(stack_a, median, 0, stack_size);
	while (pushables > 0)
	{
		if (stack_a->next->content < median)
			pb(stack_a, stack_b);
		else if (get_last_node(stack_a)->content < median)
		{
			rra(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		else
		{
			while (stack_a->next->content != median)
				ra(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		pushables--;
	}
	free(array);

}