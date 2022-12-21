/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/21 13:35:55 by arurangi         ###   ########.fr       */
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


    if (arg_count == 1)
        error_msg(1, "No numbers to sort");

    matrix = init_matrix(arg_count, argv);
    if (matrix == NULL)
        return (error_msg(1, "couldn't initialize the matrix"));

    stack_a = malloc(sizeof(t_node));
    stack_a->next = NULL;
    stack_a->previous = NULL;

    // Push nodes to linked-list
    index = 0;
    while (matrix[index])
    {
            success_msg(1, "Added (%d)", ft_atoi(matrix[index]));
            index++;
    }
    return (0);
}
