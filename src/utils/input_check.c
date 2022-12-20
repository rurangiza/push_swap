/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:49:33 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/20 13:53:48 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Valid number
int valid_number(char **arg_list, int index)
{
    int     number;
    char    *strnum;
    int     i;

    i = 0;
    strnum = arg_list[index];
    while (strnum[i] != '\0')
    {
        if (!ft_isdigit(strnum[i]) && strnum[i] != '-' && strnum[i] != '+')
            return (1, "argument nº%d is not a valid digit", index);
        i++;
    }
    number = ft_atoi(strnum);
    if (number < INT_MIN || number > INT_MAX)
        return (0, "number bigger/lower than INT_MAX/INT_MIN");
    if (!first_encounter(number, arg_list, index)) // Replace with comparaison with previous numbers in the stack for quick traversal
        return (0, "there are duplicates of %d", number);
}

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

int    extract_numbers(int arg_count, char **arg_list, t_list *stack)
{
    int     index;
    char    *strnums;
    int     sign;
    int     number;

    /*  Two options:
        - progname + number => nothing to sort
        - progname + string of numbers => extract numbers
            ./push_swap "12 54 844 -62"
    */
    strnums = arg_list[1];
    index = 0;
    while (strnums[index] != '\0')
    {
        if (!ft_isdigit(strnums[index]) && !ft_isspace(strnums[index]) && !issign(strnums[index]))
            return (error_msg(0, "contains invalid characters"));
        
        number = ft_atoi(strnums + index);
        push(number, stack);
        // sign = 1;
        
        while (ft_isspace(strnums[index]))
            index++;
        while (ft_issign(strnums[index]))
            index++;
        while (ft_isdigit(strnums[index]))
            index++;
    }
}
