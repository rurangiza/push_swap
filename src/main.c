/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/19 13:49:55 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Sort data on a stack
 * with limited set of instructions
 * using the lowest number of actions
*/

#include <stdio.h>
#include "../includes/push_swap.h"

// Use the linked list when the size of the stack is not known in advance

int main(int ac, char **av)
{
    t_list  *stack;
    int     stack_size;
    int     index;  
    int     number;
    t_list  *head = NULL;
    
    head = malloc(sizeof(t_list));

    if (ac == 1)
        return (error_msg(1, "Usage: ./push_swap 1 2 3 or ./push_swap \"1 2 3\"")); // Remove error message
    else if (ac == 2)
    {
        // Break down all numbers of second argument
        save_nodes();
    }
    else
    {
        index = 1;
        while (index < ac)
        {
            if (valid_number(av[index]))
            {
                push(number, stack);
                index++;
            }
            else

            if (!ft_isdigit(av[index]))
                return (1, "argument nº%d is not a digit", index);
            number = ft_atoi(av[index]);
            if (number < INT_MIN || number > INT_MAX)
                return (1, "number bigger/lower than INT_MAX/INT_MIN");
            if (!first_encounter(number, av, index))
                return (1, "there are duplicates of %d", number);
            push(number, stack);
            index++;
        }
        // Free nodes in case of errors
    }
    matrix_to_list();
    return (0);
}



