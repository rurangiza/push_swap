/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:27 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 17:08:33 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* (swap a): Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
*/

void	sa(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	(void)stack_b;
	first = stack_a->next;
	if (first->next == NULL)
		return ;
	second = first->next;
	if (second->next != NULL)
		third = second->next;
	stack_a->next = second;
	first->next = second->next;
	second->next = first;
	second->previous = stack_a;
	first->previous = second;
	if (second->next != NULL)
		third->previous = first;
	write(1, "sa\n", 3);
}

/* (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
*/
void	sb(t_node *stack_b, t_node *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	(void)stack_a;
	first = stack_b->next;
	if (first->next == NULL)
		return ;
	second = first->next;
	if (second->next == NULL)
		return ;
	third = second->next;
	stack_b->next = second;
	first->next = second->next;
	second->next = first;
	second->previous = stack_b;
	first->previous = second;
	third->previous = first;
	write(1, "sb\n", 3);
}

static void	_sa(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	(void)stack_b;
	first = stack_a->next;
	if (first->next == NULL)
		return ;
	second = first->next;
	if (second->next != NULL)
		third = second->next;
	stack_a->next = second;
	first->next = second->next;
	second->next = first;
	second->previous = stack_a;
	first->previous = second;
	if (second->next != NULL)
		third->previous = first;
}

static void	_sb(t_node *stack_b, t_node *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	(void)stack_a;
	first = stack_b->next;
	if (first->next == NULL)
		return ;
	second = first->next;
	if (second->next == NULL)
		return ;
	third = second->next;
	stack_b->next = second;
	first->next = second->next;
	second->next = first;
	second->previous = stack_b;
	first->previous = second;
	third->previous = first;
}

/* sa and sb at the same time. */
void	ss(t_node *stack_a, t_node *stack_b)
{
	_sa(stack_a, stack_b);
	_sb(stack_b, stack_a);
	write(1, "ss\n", 3);
}
