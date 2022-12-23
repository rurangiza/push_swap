/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:05:52 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/23 11:33:20 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* (reverse rotate a): Bottom number goes to top of stack A
 * The last element becomes the first one.
*/
void    rra(t_node *stack_a)
{
	t_node	*first;
	t_node	*old_last;
	t_node	*new_last;

	first = stack_a->next;
	old_last = get_last_node(stack_a);
	new_last = old_last->previous;
	
	old_last->next = first;
	stack_a->next = old_last;
	new_last->next = NULL;
	
	old_last->previous = stack_a;
	first->previous = old_last;

}

/* (reverse rotate b): Shift down all elements of stack b by 1
 * The last element becomes the first one.
*/
void    rrb()
{
    
}

/* rra and rrb at the same time */
void    rrr()
{
    
}