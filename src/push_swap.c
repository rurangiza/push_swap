/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/16 14:40:39 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Sort data on a stack
 * with limited set of instructions
 * using the lowest number of actions
*/

#include <stdio.h>
#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    int stack_size;

    if (ac == 1)
        return (1);

    stack_size = count_numbers(ac, av);
    if (stack_size == -1)
        return (error_msg(1, "invalid input"));
    success_msg(1, "Stack size = %d", stack_size);

    return (0);
}

// Some arguments aren't integers
// Some arguments are bigger than MAX_INT
// Duplicates
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
                counter++;
            while (ft_isdigit(av[index][j]))
                j++;
        }
        index++;
    }
    return (counter);
}
