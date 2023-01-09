/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:36:01 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 16:24:53 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* *************************** MAIN FUNCTION ******************************** */

void	small_sort(t_node *stack_a, t_node *stack_b)
{
	if (get_list_size(stack_a) - 1 <= 3)
		sort_trio(stack_a, stack_b);
	else
	{
		set_two_aside(stack_a, stack_b);
		if (!is_sorted(stack_a))
			sort_trio(stack_a, stack_b);
		bring_two_back(stack_a, stack_b);
	}
}

void	sort_trio(t_node *stack_a, t_node *stack_b)
{
	while (!is_sorted(stack_a))
	{
		if (is_sorted_asc(stack_a, 0, 2))
			rra(stack_a, stack_b);
		else if (is_sorted_asc(stack_a, 1, 3)
			&& find_largest_nbr(stack_a) == stack_a->next->content)
			ra(stack_a, stack_b);
		else
			sa(stack_a, stack_b);
	}
}

/* **************************** HELPER FUNCTIONS **************************** */

void	set_two_aside(t_node *stack_a, t_node *stack_b)
{
	int		numbers_above_trio;
	int		smallest;
	int		smallest_index;

	numbers_above_trio = (get_list_size(stack_a) - 1) - 3;
	while (numbers_above_trio > 0)
	{
		smallest = find_smallest_nbr(stack_a);
		smallest_index = find_node_position(stack_a, smallest);
		while (stack_a->next->content != smallest)
		{
			if (smallest_index < (get_list_size(stack_a) - 1) / 2)
				ra(stack_a, stack_b);
			else
				rra(stack_a, stack_b);
		}
		pb(stack_a, stack_b);
		numbers_above_trio--;
	}
}

void	bring_two_back(t_node *stack_a, t_node *stack_b)
{
	int	counter;

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
