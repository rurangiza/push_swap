/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 14:27:46 by Arsene           ###   ########.fr       */
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

    t_node *tmp_a = stack_a->next;
    t_node *tmp_b = stack_b->next;
    printf("+----------+\n|  STACKS  |\n+----------+\n");
    while (tmp_a)
    {
        printf("%-4d", tmp_a->content);
        if (tmp_b != NULL)
        {
            printf(" %-4d", tmp_b->content);
            tmp_b = tmp_b->next;            
        }
        printf("\n");
        tmp_a = tmp_a->next;
    }
    printf("_    _\nA    B\n");

    return (0);
}
