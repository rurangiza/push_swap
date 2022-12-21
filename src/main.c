/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/21 12:07:40 by arurangi         ###   ########.fr       */
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
    t_node  *stack_a = NULL;
    int     index;
    char    **matrix;
    int     arg_type;

    if (arg_count == 1)
        error_msg(1, "No numbers to sort");

    matrix = init_matrix(arg_count, argv, &arg_type, &index);

    stack_a = malloc(sizeof(t_node));
    stack_a->next = NULL;
    stack_a->previous = NULL;

    while (matrix[index])
    {
        if (valid_number(matrix, index, arg_type))
        {
            //push(ft_atoi(matrix[index]), stack_a);
            success_msg(1, "Added (%d)", ft_atoi(matrix[index]));
            index++;
        }
        else
            return (1);
    }
    // I have a singly-linked list starting with {stack_a}
    return (0);
}



