/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:51:24 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/10 09:04:56 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_quartile(t_node *stack, int start, int end, int stack_size)
{
	int	stack_pos;
	int	*array;
	int	array_pos;
	int	quartile;

	(void)end;
	array = malloc(sizeof(int) * stack_size);
	stack_pos = 0;
	array_pos = 0;
	while (stack && (stack_pos - start < stack_size))
	{
		if (stack_pos >= start)
		{
			array[array_pos] = stack->next->content;
			array_pos++;
		}
		stack_pos++;
		stack = stack->next;
	}
	selection_sort(array, stack_size);
	quartile = array[(stack_size / 4)];
	free(array);
	return (quartile);
}

int	find_octile(t_node *stack, int start, int end, int stack_size)
{
	int	stack_pos;
	int	*array;
	int	array_pos;
	int	octile;

	(void)end;
	array = malloc(sizeof(int) * stack_size);
	stack_pos = 0;
	array_pos = 0;
	while (stack && (stack_pos - start < stack_size))
	{
		if (stack_pos >= start)
		{
			array[array_pos] = stack->next->content;
			array_pos++;
		}
		stack_pos++;
		stack = stack->next;
	}
	selection_sort(array, stack_size);
	octile = array[(stack_size / 8)];
	free(array);
	return (octile);
}

int	selection_sort(int *unsorted, int size)
{
	int	i;
	int	j;
	int	smallest_index;
	int	operations;

	operations = 0;
	i = 0;
	while (i < size)
	{
		smallest_index = i;
		j = i;
		while (j < size)
		{
			if (unsorted[j] < unsorted[smallest_index])
				smallest_index = j;
			j++;
		}
		if (i != smallest_index)
		{
			ft_swap(&unsorted[i], &unsorted[smallest_index]);
			operations++;
		}
		i++;
	}
	return (operations);
}
