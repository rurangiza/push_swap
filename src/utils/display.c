/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:42:01 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/05 20:09:43 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>
#include <time.h>



void    display_hor(t_node *stack_a, t_node *stack_b)
{
    static int opGlobal = 0;
    
    opGlobal++;
    t_node *tmp_a = stack_a->next;
    t_node *tmp_b = stack_b->next;
    system("clear");
	// Print stack A
    printf("\033[32mStack A: \033[0m");
    while (tmp_a)
    {
        // if (tmp_a->previous != NULL && tmp_a->next != NULL)
        // {
        //     if (stack_a->next->content == tmp_a->content && tmp_a->content < tmp_a->next->content)
        //         printf("\033[32m%d \033[0m", tmp_a->content);
        //     else if (tmp_a->previous->content < tmp_a->content && tmp_a->next->content > tmp_a->content)
        //         printf("\033[32m%d \033[0m", tmp_a->content);
        //     else
        //         printf("\033[31m%d\033[0m ", tmp_a->content);
        // }
        printf("%d ", tmp_a->content);
        tmp_a = tmp_a->next;
    }
    printf("\n");
    // Print stack B
    printf("\033[33mStack B: \033[0m");
    while (tmp_b)
    {
        printf("%d ", tmp_b->content);
        tmp_b = tmp_b->next;
    }
    printf("\n");
	// Waot before refresh
    printf("=> %d operations\n", opGlobal);
	//usleep(2000000);
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
	usleep(1);
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