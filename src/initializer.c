/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:55:15 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/23 14:47:39 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char **initialize_matrix(int arg_count, char **argv)
{
    char    **matrix;
    int     index;
    
    if (arg_count == 1)
    {
        error_msg(1, "No numbers to sort");
        return (NULL);
    }
    
    index = 0;
    if (arg_count == 2)
    {
        matrix = ft_split(argv[1], ' ');
    }
    else
    {
        index = 1;
        matrix = argv + 1;
    }
    while (matrix[index])
    {
        if (valid_number(matrix, index))
            index++;
        else
            return (NULL);
    }
    return (matrix);
}

void    initialize_linkedlist(t_node *stack_a, t_node *stack_b, char **matrix)
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
            //success_msg(1, "pushed (%d) => stack A", ft_atoi(matrix[index]));
            push(ft_atoi(matrix[index]), stack_a);
            index++;
    }
}
