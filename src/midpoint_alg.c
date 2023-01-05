/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:01 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/05 13:01:16 by arurangi         ###   ########.fr       */
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


