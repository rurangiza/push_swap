/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/20 15:00:26 by arurangi         ###   ########.fr       */
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
    t_list  *head = NULL;
    int     index;
    char    **arg_list;

    if (arg_count == 1)
        return (error_msg(1, "No numbers to sort")); // Remove error message
    
    index = 0;
    if (arg_count == 2)
        arg_list = ft_split(argv, ' ');
    else
    {
        index = 1;
        arg_list = argv;
    }

    while (arg_list[index])
    {
        if (valid_number(arg_list, index))
        {
            push(ft_atoi(arg_list[index]), stack);
            index++;
        }
        else
            return (1);
    }
    
    return (0);
}



