/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:28:33 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 16:52:37 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	calc_average(t_node *stack_a)
{
	int	stack_size;
	int	sum;
	int	average;

	stack_size = get_list_size(stack_a);
	sum = 0;
	while (stack_a)
	{
		sum += stack_a->content;
		stack_a = stack_a->next;
	}
	average = sum / stack_size;
	return (average);
}

int	ft_abs(int x)
{
	if (x < 0)
		return -x;
	else
		return (x);
}

int count_pushables(t_node *stack_a, int pivot)
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