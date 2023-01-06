/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:36:01 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/06 10:41:50 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_3(t_node *stack_a, t_node *stack_b)
{
	while (!is_sorted(stack_a))
	{
		if (is_sorted_asc(stack_a, 0, 2))
			rra(stack_a, stack_b);
		else if (is_sorted_asc(stack_a, 1, 3) && find_largest_nbr(stack_a) == stack_a->next->content)
			ra(stack_a, stack_b);
		else
			sa(stack_a, stack_b);
	}
}

void	handle_5(t_node *stack_a, t_node *stack_b)
{
	int		smallest;
	int		sm_index;
	//t_node	*last_node;
	int		counter;
	counter = (get_list_size(stack_a) - 1) - 3;
	while (counter > 0)
	{
		smallest = find_smallest_nbr(stack_a);
		//last_node = get_last_node(stack_a);
		sm_index = find_node_position(stack_a, smallest);

		while (stack_a->next->content != smallest)
		{
			if (sm_index < (get_list_size(stack_a) - 1) / 2)
				ra(stack_a, stack_b);
			else
				rra(stack_a, stack_b);
		}
		pb(stack_a, stack_b);
		counter--;
	}
	if (!is_sorted(stack_a))
		handle_3(stack_a, stack_b);
	
	if ((get_list_size(stack_b) - 1) >= 2)
		counter = 2;
	else
		counter = 1;
	while (counter > 0)
	{
		pa(stack_a, stack_b);
		counter--;
	}
}
