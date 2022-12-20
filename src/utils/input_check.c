/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:49:33 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/20 15:16:15 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Valid number */
int valid_number(char **arg_list, int index, int arg_type)
{
    int     number;
    char    *strnum;
    int     i;

    i = 0;
    strnum = arg_list[index];
    while (strnum[i] != '\0')
    {
        if (!ft_isdigit(strnum[i]) && !ft_issign(strnum[i]))
            return (1, "argument nº%d is not a valid digit", index);
        i++;
    }
    number = ft_atoi(strnum);
    if (number < INT_MIN || number > INT_MAX)
        return (0, "number bigger/lower than INT_MAX/INT_MIN");
    if (!first_encounter(number, arg_list, index, arg_type)) // Replace with comparaison with previous numbers in the stack for quick traversal
        return (0, "there are duplicates of %d", number);
    return (1);
}

/* Add an element to the top of a stack */
void    push(int node_content, t_list **stack)
{
    t_list *node;
    
    node = ft_lstnew(node_content);
    if (!node)
    {
        error_msg(0, "couldn't create new node");
        // Shoulw I free?
        return ;
    }
    ft_lstadd_front(stack, node);
}

/* BEWARE!!! index will start with 1 or 0 depending on arg_list type */
int	first_encounter(int number, char *arguments, int position, int arg_type)
{
	int index;

	index = arg_type;
	while (index < position)
	{
		if (ft_atoi(arguments[index]) == number)
			return (0);
		index++;
	}
	return (1);
}
