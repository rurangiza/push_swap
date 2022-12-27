/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:32:16 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/27 13:28:49 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
3 numbers -> 6 operations
5 numbers -> 12 operations
100 numbers -> 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "../../includes/unit_test.h"

/* UTILS */
void	summury(int *unsorted, int size, int operations)
{
	printf("Sorted: ");
	for (int i = 0; i < size; i++)
		printf("%d ", unsorted[i]);
	printf(" \033[33m(%d operations)\033[0m\n", operations);
}



/* OPERATIONS */
static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* SORITNG ALGORTIHMS */
int	bubble_sort(int	*unsorted, int size)
{
	int	permutation;
	int	i;
	int	operations;
	
	operations = 0;
	permutation = 1;
	while (permutation > 0)
	{
		permutation = 0;
		i = 0;
		while (i < size - 1)
		{	
			if (unsorted[i] > unsorted[i + 1])
			{
				permutation++;
				swap(&unsorted[i], &unsorted[i + 1]);
				operations++;
			}
			i++;
		}
	}
	return (operations);
}

/*
 * Selection sort  
 *
 * sorts an array by repeatedly finding the minimum element (considering ascending order)
 * from the unsorted part and putting it at the beginning. 
 *
 * The algorithm maintains two subarrays in a given array:
 * - The subarray which already sorted. 
 * - The remaining subarray was unsorted.
*/
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

/* MAIN */
// int main(void)
// {
// 	int	size = 100;
// 	int	*unsorted = random_numbers(size, 5000);
// 	int	operations;

// 	printf("\033[31mUnsorted:\033[0m \n");
// 	for (int i = 0; i < size; i++)
// 		printf("%d ", unsorted[i]);
	
// 	operations = selection_sort(unsorted, size);
	
// 	printf("\n\n\033[32mSorted\033[0m\n");
// 	for (int i = 0; i < size; i++)
// 		printf("%d ", unsorted[i]);
// 	printf("\n\033[33m(%d operations)\033[0m\n", operations);

// 	free(unsorted);
// 	return (0);
// }

int	find_pivot(t_node *stack_a, int start, int end, int stack_size)
{
	int	closest;
	int	closest_number;
	int	target;
	int	position;

	target = calc_average(stack_a, start, end, stack_size);
	//target = calc_medthree(stack_a, start, end);
	//return (success_msg(target, "pivot = %d", target));
	
	//info_msg(0, "head: %d", stack_a->next->content);
	//info_msg(0, "target : %d", target);
	closest = INT_MAX;
	closest_number = 0;
	stack_a = stack_a->next;
	position = 0;
	while (stack_a && (position - start < stack_size))
	{
		if (position >= start)
		{
			if (ft_abs(stack_a->content - target) < ft_abs(closest - target))
			{
				closest = stack_a->content;
				closest_number = stack_a->content;
			}
		}
		position++;
		stack_a = stack_a->next;
	}
	//info_msg(0, "closest number : %d", closest_number);
	//pick_best_pivot(stack_a, target, calc_medthree(stack_a, start, end));
	
	return (closest_number);
}

//int	calc_

int	calc_medthree(t_node *stack_a, int start, int end)
{
	int	stack_size = end - start;
	int	medthree[3];
	int	mt_index = 0;
	int	index = 0;

	// medthree up three random numbers
	stack_a = stack_a->next;
	while (stack_a && (index - start < stack_size))
	{
		if (index >= start)
		{
			if (index == start || index == stack_size / 2 || index == end - 1)
			{
				medthree[mt_index] = stack_a->content;
				mt_index++;
			}
		}
		index++;
		stack_a = stack_a->next;
	}
	// Calculate average of those three
	//medthree /= 3;
	// Pick the middle of the three
	mt_index = 0;
	while (mt_index < 3)
	{
		int j = 0;
		int smaller = 0;
		int larger = 0;
		while (j < 3)
		{
			if (j != mt_index)
			{
				if (medthree[j] < medthree[mt_index])
					smaller++;
				else
					larger++;
			}
			j++;
		}
		if (smaller > 0 && larger > 0)
			return (medthree[mt_index]);
		mt_index++;
	}
	
	return (error_msg(-1, "no mid found in calc_medthree"));
}