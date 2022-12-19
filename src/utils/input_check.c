/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:49:33 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/19 13:50:14 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Add an element to the top of a stack
void    push(int node_content, t_list **stack)
{
    t_list *node;
    
    node = ft_lstnew(node_content);
    if (!node)
    {
        error_msg(0, "couldn't create new node");
        return ;
    }
    ft_lstadd_front(stack, node);
}

int	first_encounter(int number, char *arguments, int position)
{
	int index;

	index = 1;
	while (index < position)
	{
		if (ft_atoi(arguments[index]) == number)
			return (0);
		index++;
	}
	return (1);
}


int count_numbers(int ac, char **av)
{
    int     counter;
    int     index;
    int     j;
    
    counter = 0;
    index = 1;
    while (index < ac)
    {
        j = 0;
        while (av[index][j])
        {
            if (!ft_isdigit(av[index][j]) && !ft_isspace(av[index][j]))
                return (-1);
            while (ft_isspace(av[index][j]))
                j++;
            
            if (ft_isdigit(av[index][j]))
            {
                add_node_to_stack(av[index][j]);
                counter++;
            }
            while (ft_isdigit(av[index][j]))
                j++;
        }
        index++;
    }
    return (counter);
}

void    add_node_to_stack(char *strnum)
{
    int i;
    int nbr;

    i = 0;
    while (ft_isdigit(strnum[i]))
        i++;
    nbr = ft_atoi();
}
