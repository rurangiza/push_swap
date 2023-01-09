/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:59:30 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/09 15:43:35 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* *************************** MAIN FUNCTION ******************************** */

void	large_sort(t_node *stack_a, t_node *stack_b)
{
	empty_main_stack(stack_a, stack_b, 5);
	if (!is_sorted(stack_a))
		small_sort(stack_a, stack_b);
	empty_temporary_stack(stack_a,stack_b);
}

/* ************************** HELPER FUNCTIONS ****************************** */

void	empty_main_stack(t_node *stack_a, t_node *stack_b, int cutoff)
{
	int		pivot;
	int		pushables;
	int		stack_size;

	stack_size = get_list_size(stack_a) - 1;
	while (stack_size > cutoff)
	{
		if (stack_size > 100)
			pivot = find_octile(stack_a, 0, stack_size, stack_size);
		else
			pivot = find_quartile(stack_a, 0, stack_size, stack_size);
		pushables = count_pushables(stack_a, pivot, 0, stack_size);
		while (pushables > 0 && stack_size > cutoff)
		{
			handle_pushables(stack_a, stack_b, pivot, &pushables);
			keep_largest_ontop(stack_a, stack_b);
			stack_size = get_list_size(stack_a) - 1;
		}
	}
}

void	empty_temporary_stack(t_node *stack_a, t_node *stack_b)
{
	int		largest;
	int		lgst_position;
	t_node	*first_a;

	while (stack_b->next != NULL)
	{
		largest = find_largest_nbr(stack_b);
		lgst_position = find_node_position(stack_b, largest);
		while (stack_b->next->content != largest)
		{
			if (lgst_position < (get_list_size(stack_b) - 1) / 2)
				rb(stack_b, stack_a);
			else
				rrb(stack_b, stack_a);
		}
		pa(stack_a, stack_b);
		first_a = stack_a->next;
		if (first_a->content > first_a->next->content)
			sa(stack_a, stack_b);
	}
}

void	handle_pushables(t_node *stack_a, t_node *stack_b, int pivot, int *pushables)
{
	t_node	*first;
	t_node	*last;

	first = stack_a->next;
	last = get_last_node(stack_a);
	if (first->content < pivot && last->content < pivot)
	{
		if (last->content < first->content)
			rra(stack_a, stack_b);
		pb(stack_a, stack_b);
		(*pushables)--;
	}
	else if (first->content < pivot || last->content < pivot)
	{
		if (first->content < pivot)
			pb(stack_a, stack_b);
		else
		{
			rra(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		(*pushables)--;
	}
	else
		ra(stack_a, stack_b);
}

void	keep_largest_ontop(t_node *stack_a, t_node *stack_b)
{
	t_node *first_b;
	t_node *second_b;

	if ((get_list_size(stack_b) - 1) >= 2)
	{

		if (stack_b->next->content < get_last_node(stack_b)->content)
			rb(stack_b, stack_a);
		
		first_b = stack_b->next;
		second_b = first_b->next;
		if (first_b->content < second_b->content)
			sb(stack_b, stack_a);
	}
}
