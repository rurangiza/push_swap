/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:51:24 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/28 14:18:53 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_median(t_node *stack_a, int start, int end, int stack_size)
{
	int	stack_pos;
	int	*array;
	int	array_pos;
	int	median;

	(void)end;
	array = malloc(sizeof(int) * stack_size);
	// Store in array
	stack_pos = 0;
	array_pos = 0;
	while (stack_a && (stack_pos - start < stack_size))
	{
		if (stack_pos >= start)
		{
			array[array_pos] = stack_a->next->content;
			array_pos++;
		}
		stack_pos++;
		stack_a = stack_a->next;
	}
	// Sort array
	selection_sort(array, stack_size);
	// Find median
	median = array[(stack_size / 2)];
	
	free(array);
	return (median);

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
			swap(&unsorted[i], &unsorted[smallest_index]);
			operations++;
		}
		i++;
	}
	return (operations);
}

int	insertion_sort(int *unsorted, int size)
{
	int	i;
	int	j;
	int	operations;
	int	key;

	operations = 0;
	i = 1;
	while (i < size)
	{
		j = i - 1;
		key = unsorted[i];
		while (j >= 0 && unsorted[j] > key)
		{
			unsorted[j + 1] = unsorted[j];
			j--;
		}
		operations++;
		unsorted[j + 1] = key;
		i++;
	}

	return (operations);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}