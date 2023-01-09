/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:06:57 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 13:46:59 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    init_stack(t_node *stack_a, t_node *stack_b, char **matrix)
{
    int index;

    stack_a->next = NULL;
    stack_a->previous = NULL;
    stack_a->index = -1;

    stack_b->next = NULL;
    stack_b->previous = NULL;
    
    index = 0;
    while (matrix[index])
        add_to_stack(ft_atoi(matrix[index++]), stack_a);
}

void    add_to_stack(int node_content, t_node *stack)
{
    t_node *node;
    
    node = create_node(node_content);
    if (node == NULL)
    {
        error_msg(0, "couldn't create new node");
		delete_all_nodes(&stack);
        return ;
    }
    add_back(&stack, node);
}
