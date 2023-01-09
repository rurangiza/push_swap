/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:28:33 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 09:01:24 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	calc_average(t_node *stack_a, int start, int end, int stack_size)
{
	int	sum;
	int	average;
	int	position;

	(void)end;
	position = 0;
	sum = 0;
	stack_a = stack_a->next;
	while (stack_a && (position - start < stack_size))
	{
		if (position >= start)
			sum += stack_a->content;
		position++;
		stack_a = stack_a->next;
	}
	average = sum / stack_size;
	
	return (average);
}



int count_pushables(t_node *stack, int pivot, int start, int end)
{
    t_node  *tmp;
    int     elements_to_push;
	int		position;
	int		stack_size;

	stack_size = end - start;

	position = 0;
    tmp = stack->next;
	elements_to_push = 0;
	while (tmp && (position - start < stack_size))
	{
		if (position >= start)
		{
			if (tmp->content < pivot)
				elements_to_push++;	
		}
		position++;
		tmp = tmp->next;
	}
    return (elements_to_push);
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