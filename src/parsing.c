/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:55:15 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/09 17:53:44 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**parse_input(int arg_count, char **argv)
{
	char	**matrix;
	int		index;

	index = 0;
	if (arg_count == 2)
	{
		matrix = ft_split(argv[1], ' ');
		if (matrix == NULL)
			return (NULL);
	}
	else
		matrix = argv + 1;
	while (matrix[index])
	{
		if (is_valid_number(matrix, index))
			index++;
		else
			return (NULL);
	}
	return (matrix);
}

int	is_valid_number(char **arg_list, int index)
{
	int		number;
	char	*strnum;
	int		sign_counter;
	int		digit_counter;

	sign_counter = 0;
	digit_counter = 0;
	strnum = arg_list[index];
	if (num_checker(strnum, &sign_counter, &digit_counter, index) == 0)
		return (0);
	if (sign_counter > 1)
		return (0);
	number = ft_atoi(strnum);
	if (number < INT_MIN || number > INT_MAX)
		return (rmessage());
	if (!first_encounter_arg(number, arg_list, index))
		return (rmessage());
	return (1);
}

int	num_checker(char *strnum, int *sign_counter, int *digit_counter, int index)
{
	int	i;

	i = 0;
	(void)index;
	while (strnum[i] != '\0')
	{
		if (ft_strlen(strnum) == 1 && (!ft_isdigit(strnum[i])))
			return (rmessage());
		if (!ft_isdigit(strnum[i]) && !ft_issign(strnum[i]))
			return (rmessage());
		if (ft_issign(strnum[i]))
			(*sign_counter)++;
		if (ft_isdigit(strnum[i]))
			(*digit_counter)++;
		if (ft_issign(strnum[i]) && (*digit_counter) > 1)
			return (rmessage());
		i++;
	}
	return (1);
}

int	first_encounter_arg(int number, char **arguments, int position)
{
	int	index;

	index = 0;
	while (index < position)
	{
		if (ft_atoi(arguments[index]) == number)
			return (0);
		index++;
	}
	return (1);
}
