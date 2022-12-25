/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:47:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 16:01:10 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	partition(t_node *stack_a, t_node *stack_b, int pivot)
{
	int     rotation_counter;
	int     elements_to_push;

	// Count number of items to push
    elements_to_push = count_elements_to_push(stack_a, pivot);
	// Push items to stack_b (or move out of the way)
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
	// Replace back in order
	while (rotation_counter-- > 0)
		rra(stack_a);
	// Move pivot to top of stack_a
    place_pivot_ontop(stack_a, pivot);
	// Send back all numbers in stack_b to stack_a
	while (stack_b->next != NULL)
		pa(stack_a, stack_b);
}

int count_elements_to_push(t_node *stack_a, int pivot)
{
    t_node  *tmp;
    int     elements_to_push;

    tmp = stack_a->next;
	elements_to_push = 0;
	while (tmp)
	{
		if (tmp->content < pivot)
			elements_to_push++;
		tmp = tmp->next;
	}
    return (elements_to_push);
}

void    place_pivot_ontop(t_node *stack_a, int pivot)
{
    int pivot_position;
    
    pivot_position = find_node_position(stack_a, pivot);
	if (pivot_position == -1)
		return ;
	while (stack_a->next->content != pivot)
	{
		if (pivot_position < get_list_size(stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	find_node_position(t_node *list, int content)
{
	t_node	*tmp;
	int		index;

	tmp = list->next;
	index = 0;
	while (tmp)
	{
		if (tmp->content == content)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (-1);
}
