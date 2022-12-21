/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:36:31 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/21 17:05:19 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* UTILS */
void	summury(int *unsorted, int size, int operations)
{
	printf("Sorted: ");
	for (int i = 0; i < size; i++)
		printf("%d ", unsorted[i]);
	printf(" \033[33m(%d operations)\033[0m\n", operations);
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
	summury(unsorted, size, operations);
}

/*
3 numbers -> 6 operations
5 numbers -> 12 operations
100 numbers -> 
*/

/* MAIN */
int main(void)
{
	//int	unsorted_10[] = {20, 98, 1, 14, 2, 38, 7, 5, 3, 10};
	int	unsorted_3[] = {2, 3, 1}; // 2 3 1 -> 2 1 3 -> 1 2 3
	
	bubble_sort(unsorted_3, 3);
	
	return (0);
}

/*

ra : rotate a


*/