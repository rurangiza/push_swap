/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/19 11:33:51 by arurangi         ###   ########.fr       */
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
            if (!ft_isdigit(av[index]))
                return (1, "argument nº%d is not a digit", index);
            number = ft_atoi(av[index]);
            if (number < INT_MIN || number > INT_MAX)
                return (1, "number bigger/lower than INT_MAX/INT_MIN");
            if (!first_encounter(number))
                return (1, "there are duplicates of %d", number);
            add_node(number);
            index++;
        }
        // Free nodes in case of errors
    }
    return (0);
}


int count_numbers(int ac, char **av)
{
    int     counter;
    int     index;
    int     j;
    
    counter = 0;
    index = 1;
    while (index < ac)
    {
        j = 0;
        while (av[index][j])
        {
            if (!ft_isdigit(av[index][j]) && !ft_isspace(av[index][j]))
                return (-1);
            while (ft_isspace(av[index][j]))
                j++;
            
            if (ft_isdigit(av[index][j]))
            {
                add_node_to_stack(av[index][j]);
                counter++;
            }
            while (ft_isdigit(av[index][j]))
                j++;
        }
        index++;
    }
    return (counter);
}

void    add_node_to_stack(char *strnum)
{
    int i;
    int nbr;

    i = 0;
    while (ft_isdigit(strnum[i]))
        i++;
    nbr = ft_atoi();
}
