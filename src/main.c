/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/20 16:52:53 by arurangi         ###   ########.fr       */
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
    t_list  *stack_a = NULL;
    int     index;
    char    **matrix;
    int     arg_type;

    stack_a = malloc(sizeof(t_list));
    stack_a->next = NULL;
    stack_a->previous = NULL;

    matrix = init_matrix(arg_count, argv, &arg_type, &index);

    while (matrix[index])
    {
        if (valid_number(matrix, index, arg_type))
        {
            push(ft_atoi(matrix[index]), stack_a);
            index++;
        }
        else
            return (1);
    }
    
    // I have a singly-linked list starting with {stack_a}
    return (0);
}



