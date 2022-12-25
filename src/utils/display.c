/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:42:01 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 20:42:21 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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