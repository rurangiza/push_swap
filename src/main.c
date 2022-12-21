/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/21 15:29:01 by arurangi         ###   ########.fr       */
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
    t_node  *stack_b = NULL;
    char    **matrix;


    if (arg_count == 1)
        error_msg(1, "No numbers to sort");

    matrix = initialize_matrix(arg_count, argv);
    if (matrix == NULL)
        return (1);

    stack_a = malloc(sizeof(t_node));
    stack_a->next = NULL;
    stack_a->previous = NULL;

    initialize_linkedlist(stack_a, matrix);

    sort(stack_a, stack_b);
    
    printf("\nStack A's head = %d", stack_a->next->content);

    return (0);
}
