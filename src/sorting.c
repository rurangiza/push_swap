/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:45:12 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/09 15:48:27 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A sorting algorithm is set of instructions used to arrange elements
 * of an array/list in a specific order
*/

#include "../includes/push_swap.h"

void	sort_stack(t_node *stack_a, t_node *stack_b)
{
	int	stack_size;

	stack_size = get_list_size(stack_a) - 1;
	if (is_sorted(stack_a))
	{
		success_msg(1, "aleready sorted");
		return ;
	}
	if (stack_size <= 5)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}
