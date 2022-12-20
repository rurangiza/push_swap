/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/20 15:15:32 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Sort data on a stack
 * with limited set of instructions
 * using the lowest number of actions
*/

#include <stdio.h>
#include "../includes/push_swap.h"

int main(int arg_count, char **argv)
{
    t_list  *stack;
    int     index;
    char    **arg_list;
    int     arg_type;

    if (arg_count == 1)
        return (error_msg(1, "No numbers to sort")); // Remove error message
    
    index = 0;
    if (arg_count == 2)
    {
        arg_list = ft_split(argv, ' '); // Free later
        arg_type = 0;
    }
    else
    {
        index = 1;
        arg_list = argv;
        arg_type = 1;
    }

    while (arg_list[index])
    {
        if (valid_number(arg_list, index, arg_type))
        {
            push(ft_atoi(arg_list[index]), stack);
            index++;
        }
        else
            return (1);
    }
    
    return (0);
}



