/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:55:15 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/21 15:23:01 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char **initialize_matrix(int arg_count, char **argv)
{
    int     arg_type;
    char    **matrix;
    int     index;
    
    index = 0;
    if (arg_count == 2)
    {
        arg_type = 0;
        matrix = ft_split(argv[1], ' ');
    }
    else
    {
        index = 1;
        arg_type = 1;
        matrix = argv + 1;
    }
    while (matrix[index])
    {
        if (valid_number(matrix, index, arg_type))
            index++;
        else
            return (NULL);
    }
    return (matrix);
}

void    initialize_linkedlist(t_node *stack_a, char **matrix)
{
    int index;

    (void)stack_a;
    index = 0;
    while (matrix[index])
    {
            success_msg(1, "pushed (%d) => stack A", ft_atoi(matrix[index]));
            push(ft_atoi(matrix[index]), stack_a);
            index++;
    }
}
