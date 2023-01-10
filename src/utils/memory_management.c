/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:19:35 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/10 09:49:30 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	free_stacks(t_node *stack_a, t_node *stack_b, int return_value)
{
	delete_all_nodes(&stack_a);
	delete_all_nodes(&stack_b);
	return (return_value);
}
