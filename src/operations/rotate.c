/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:55:11 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/23 11:16:53 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* (rotate a): Top number goes to bottom of stack A
 * The first element becomes the last one.
*/
void    ra(t_node *stack_a)
{
	t_node	*first;
	t_node	*second;
    t_node	*last;
	
	first = stack_a->next;
	second = first->next;
	last = get_last_node(stack_a);
	
	stack_a->next = second;
	first->next = last->next;
	last->next = first;

	first->previous = last;
	second->previous = stack_a;
}

/* (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
*/
void    rb()
{
    
}

/* ra and rb at the same time */
void    rr()
{
    
}