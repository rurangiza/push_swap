/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:49:33 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/21 15:17:14 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Valid number */
int valid_number(char **arg_list, int index, int arg_type)
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
    if (!first_encounter(number, arg_list, index, arg_type)) // Replace with comparaison with previous numbers in the stack for quick traversal
        return (error_msg(0, "there are duplicates of %d", number));
    return (1);
}



/* BEWARE!!! index will start with 1 or 0 depending on arg_list type */
int	first_encounter(int number, char **arguments, int position, int arg_type)
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
