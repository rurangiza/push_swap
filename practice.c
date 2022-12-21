/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:36:31 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/21 20:42:02 by Arsene           ###   ########.fr       */
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

/* UTILS */
void	summury(int *unsorted, int size, int operations)
{
	printf("Sorted: ");
	for (int i = 0; i < size; i++)
		printf("%d ", unsorted[i]);
	printf(" \033[33m(%d operations)\033[0m\n", operations);
}

int	first_encounter(int number, int *list, int position)
{
	int i;
	
	i = 0;
	while (i < position)
	{
		if (number == list[i])
			return (0);
		i++;
	}
	return (1);
}

int	*random_numbers(int size, int threshold)
{
	int	index;
	int	*list;
	int	sign;
	int	number;

	list = malloc(sizeof(int) * size);
	srand(time(0));
	index = 0;	
	while (index < size)
	{
		sign = 1;
		if (rand() % 3 == 1)
			sign = -1;
		number = (rand() % threshold) * sign;
		while (!first_encounter(number, list, index))
		{
			number = (rand() % threshold) * sign;
		}
		list[index] = number;
		index ++;
	}
	return (list);
}

/* OPERATIONS */
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* SORITNG ALGORTIHMS */
void	bubble_sort(int	*unsorted, int size)
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
	// Print results
	printf("\n=> %d operations\n", operations);
	//summury(unsorted, size, operations);
}

/* MAIN */
int main(void)
{
	int	size = 50;
	int	*unsorted = random_numbers(size, 100);

	printf("\033[31mBefore:\033[0m ");
	for (int i = 0; i < size; i++)
		printf("%d ", unsorted[i]);
	write(1, "\n", 1);
	
	bubble_sort(unsorted, size);
	
	printf("\n\033[32mAfter:\033[0m ");
	for (int i = 0; i < size; i++)
		printf("%d ", unsorted[i]);
	write(1, "\n", 1);

	free(unsorted);
	return (0);
}
