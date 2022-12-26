/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:42:01 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/26 20:28:11 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>
#include <time.h>

void    display_hor(t_node *stack_a, t_node *stack_b)
{
    stack_a = stack_a->next;
    stack_b = stack_b->next;
    system("clear");
	// Print stack A
    printf("\033[32mStack A: \033[0m");
    while (stack_a)
    {
        printf("%d ", stack_a->content);
        stack_a = stack_a->next;
    }
    printf("\n");
    // Print stack B
    printf("\033[33mStack B: \033[0m");
    while (stack_b)
    {
        printf("%d ", stack_b->content);
        stack_b = stack_b->next;
    }
    printf("\n");
	// Waot before refresh
	usleep(100000);
}

void    display_stack(t_node *stack_a, t_node *stack_b)
{
    // t_node *tmp_a;
    // t_node *tmp_b;
    int iterations;
    int size_a = get_list_size(stack_a);
    int size_b = get_list_size(stack_b);
    if (size_a > size_b)
        iterations = size_a;
    else
        iterations = size_b;
    
    if (stack_a != NULL)
        stack_a = stack_a->next;
    
    if (stack_b != NULL)
        stack_b = stack_b->next;

	// Clear terminal content
	system("clear");
	// Print stack content
    printf("+----------+\n|  STACKS  |\n+----------+\n");
    while (iterations != 0)
    {
        printf("%-4d", stack_a->content);
        info_msg(0, "---> here");
        usleep(1000000);
        if (stack_b != NULL)
        {
            printf(" %-4d", stack_b->content);
            stack_b = stack_b->next;            
        }
        printf("\n");
        if (stack_a != NULL)
            stack_a = stack_a->next;
        iterations--;
    }
    printf("_    _\nA    B\n");
	// Waot before refresh
	usleep(1000000);
}

int	first_encounter_gen(int number, int *list, int position)
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
		while (!first_encounter_gen(number, list, index))
		{
			number = (rand() % threshold) * sign;
		}
		list[index] = number;
		index ++;
	}
	return (list);
}