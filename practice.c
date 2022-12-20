/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/20 14:13:52 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main(int arg_count, char )
{
	extract_number(arc_count, arg_list, tab);
}