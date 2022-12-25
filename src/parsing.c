/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:55:15 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/25 17:03:14 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char **parse_input(int arg_count, char **argv)
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

int valid_number(char **arg_list, int index)
{
    int     number;
    char    *strnum;
    int     sign_counter;
    int     digit_counter;
    int     i;

    sign_counter = 0;
    digit_counter = 0;
    i = 0;
    strnum = arg_list[index];
    while (strnum[i] != '\0')
    {
        if (ft_strlen(strnum) == 1 && (!ft_isdigit(strnum[i])))
            return (error_msg(0, "sign only"));
        if (!ft_isdigit(strnum[i]) && !ft_issign(strnum[i]))
            return (error_msg(0, "argument nº%d is not a valid digit", index));
        if (ft_issign(strnum[i]))
            sign_counter++;
        if (ft_isdigit(strnum[i]))
            digit_counter++;
        if (ft_issign(strnum[i]) && digit_counter > 1)
            return (error_msg(0, "sign after digit"));
        i++;
    }
    if (sign_counter > 1)
        return (0);
    number = ft_atoi(strnum);
    if (number < INT_MIN || number > INT_MAX)
        return (error_msg(0, "number bigger/lower than INT_MAX/INT_MIN"));
    if (!first_encounter_arg(number, arg_list, index)) // Replace with comparaison with previous numbers in the stack for quick traversal
        return (error_msg(0, "there are duplicates of %d", number));
    return (1);
}



/* BEWARE!!! index will start with 1 or 0 depending on arg_list type */
int	first_encounter_arg(int number, char **arguments, int position)
{
	int index;

	index = 0;
	while (index < position)
	{
		if (ft_atoi(arguments[index]) == number)
			return (0);
		index++;
	}
	return (1);
}
