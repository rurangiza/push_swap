/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 17:16:37 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Sort data on a stack
 * with limited set of instructions
 * using the lowest number of actions
*/

#include <stdio.h>
#include "../includes/push_swap.h"
//#include "../includes/unit_test.h"

void    display_stack(t_node *stack_a, t_node *stack_b)
{
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
}

int main(int arg_count, char **argv)
{
    t_node  *stack_a = NULL;
    t_node  *stack_b = NULL;
    char    **matrix;

    stack_a = malloc(sizeof(t_node));
    stack_b = malloc(sizeof(t_node));

    matrix = parse_input(arg_count, argv);
    if (matrix == NULL)
        return (1);

    init_stack(stack_a, stack_b, matrix);
    sort_stack(stack_a, stack_b);
    display_stack(stack_a, stack_b);


    return (0);
}

