/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/10 09:05:12 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Sort data on a stack
 * with limited set of instructions
 * using the lowest number of actions
*/

#include "../includes/push_swap.h"

int	main(int arg_count, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**matrix;

	if (arg_count == 1)
		return (1);
	stack_a = malloc(sizeof(t_node));
	stack_b = malloc(sizeof(t_node));
	matrix = parse_input(arg_count, argv);
	if (!matrix || !matrix[0])
	{
		free_stacks(stack_a, stack_b);
		write(1, "Error\n", 6);
		return (1);
	}
	init_stack(stack_a, stack_b, matrix);
	sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
