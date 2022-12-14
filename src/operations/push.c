/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:42 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 17:07:34 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* (push a): Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
*/
void	pb(t_node *stack_a, t_node *stack_b)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;

	first_a = stack_a->next;
	second_a = first_a->next;
	first_b = stack_b->next;
	stack_a->next = second_a;
	first_a->next = first_b;
	if (second_a != NULL)
		second_a->previous = stack_a;
	stack_b->next = first_a;
	if (first_b != NULL)
		first_b->previous = first_a;
	first_a->previous = stack_b;
	write(1, "pb\n", 3);
}

/* (push b): Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
*/
void	pa(t_node *stack_a, t_node *stack_b)
{
	t_node	*first_b;
	t_node	*second_b;
	t_node	*first_a;

	first_b = stack_b->next;
	second_b = first_b->next;
	first_a = stack_a->next;
	stack_b->next = second_b;
	if (second_b != NULL)
		second_b->previous = stack_b;
	first_b->next = first_a;
	stack_a->next = first_b;
	if (first_a != NULL)
		first_a->previous = first_b;
	first_b->previous = stack_a;
	write(1, "pa\n", 3);
}
