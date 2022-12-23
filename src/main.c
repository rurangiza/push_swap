/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/23 14:48:04 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Sort data on a stack
 * with limited set of instructions
 * using the lowest number of actions
*/

#include <stdio.h>
#include "../includes/push_swap.h"
#include "../includes/unit_test.h"

int main(int arg_count, char **argv)
{
    t_node  *stack_a = NULL;
    t_node  *stack_b = NULL;
    char    **matrix;

    stack_a = malloc(sizeof(t_node));
    stack_b = malloc(sizeof(t_node));

    matrix = initialize_matrix(arg_count, argv);
    if (matrix == NULL)
        return (1);

    initialize_linkedlist(stack_a, stack_b, matrix);

    
    sort(stack_a, stack_b);

    t_node *tmp = stack_a->next;
    while (tmp)
    {
        info_msg(1, "%d / previous (%d)", tmp->content, tmp->previous->content);
        // if (tmp->previous != NULL)
        // {
        // }
        tmp = tmp->next;
    }
    // printf("\nStack A's head = %d", stack_a->next->content);

    return (0);
}
