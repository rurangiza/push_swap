/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:06:57 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/26 20:19:13 by Arsene           ###   ########.fr       */
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
    stack_b->index = -1;
    
    index = 0;
    
    while (matrix[index])
    {
            push(ft_atoi(matrix[index]), stack_a);
            index++;
    }
    
//    (void)matrix;
//     int size = 14;
//     int *mat = random_numbers(size, 200);
//     for (int i = 0; i < size; i++)
//         push(mat[i], stack_a);
}

/* Add an element to the top of a stack */
void    push(int node_content, t_node *stack)
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