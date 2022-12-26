/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:55:11 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/26 22:04:08 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* (rotate a): Top number goes to bottom of stack A
 * The first element becomes the last one.
*/
void    ra(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
    t_node	*last;
	
	(void)stack_b;
	first = stack_a->next;
	if (first == NULL || first->next == NULL)
		return ;
	second = first->next;
	last = get_last_node(stack_a);
	
	stack_a->next = second;
	first->next = last->next;
	last->next = first;

	first->previous = last;
	second->previous = stack_a;

	display_hor(stack_a, stack_b);
	//write(1, "ra\n", 3);
}

/* (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
*/
void    rb(t_node *stack_b, t_node *stack_a)
{
    t_node	*first;
	t_node	*second;
    t_node	*last;
	first = stack_b->next;
	
	(void)stack_a;
	if (first == NULL || first->next == NULL)
		return ;
	
	second = first->next;
	last = get_last_node(stack_b);
	
	stack_b->next = second;
	first->next = last->next;
	last->next = first;

	first->previous = last;
	second->previous = stack_b;

	display_hor(stack_a, stack_b);
	//write(1, "rb\n", 3);
}

/* ra and rb at the same time */
void    rr()
{
    
}