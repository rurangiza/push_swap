/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:19:35 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/09 12:31:35 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stacks(t_node *stack_a, t_node *stack_b)
{
	delete_all_nodes(&stack_a);
	delete_all_nodes(&stack_b);
	//write(1, "Error\n", 6);
	// free(stack_a);
	// free(stack_b);
}