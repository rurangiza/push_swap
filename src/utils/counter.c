/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:28:33 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 16:53:27 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_pushables(t_node *stack, int pivot, int start, int end)
{
	t_node	*tmp;
	int		elements_to_push;
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
