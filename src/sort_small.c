/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:36:01 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 07:20:40 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	small_sort(t_node *stack_a, t_node *stack_b)
// {
// 	return ;
// }

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

void	sort_trio(t_node *stack_a, t_node *stack_b)
{
	t_node *first_b;
	t_node *second_b;
	
	//if (get_list_size(stack_a) - 1 <= 3);
	// swap top 2 numbers in stack_b (keep largest above)
	if ((get_list_size(stack_b) - 1) <= 3)
		handle_3(stack_a, stack_b);
	else
	{
		// Top 2
		if (stack_b->next->content < get_last_node(stack_b)->content)
			rb(stack_b, stack_a);
		
		first_b = stack_b->next;
		second_b = first_b->next;
		if (first_b->content < second_b->content)
			sb(stack_b, stack_a);
			
		// first_b = stack_b->next;
		// second_b = first_b->next;
		// if ()
		// // Top 3
		// if (get_list_size(stack_b) - 1 >= 3)
		// {
			
		// }
	}
}



void	small_sort(t_node *stack_a, t_node *stack_b)
{
	int		smallest;
	int		sm_index;
	int		counter;
	//t_node	*last_node;
	if ((get_list_size(stack_a) - 1) <= 3)
	{
		handle_3(stack_a, stack_b);
		return ;
	}
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
