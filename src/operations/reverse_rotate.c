/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:05:52 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/26 20:24:55 by Arsene           ###   ########.fr       */
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
	if (first == NULL || first->next == NULL)
		return ;
	old_last = get_last_node(stack_a);
	new_last = old_last->previous;
	
	old_last->next = first;
	stack_a->next = old_last;
	new_last->next = 0;

	old_last->previous = stack_a;
	first->previous = old_last;

	t_node *stack_b = NULL;
	display_hor(stack_a, stack_b);
	//write(1, "rra\n", 4);
}

/* (reverse rotate b): Shift down all elements of stack b by 1
 * The last element becomes the first one.
*/
void    rrb(t_node *stack_b, t_node *stack_a)
{
    t_node	*first;
	t_node	*old_last;
	t_node	*new_last;

	first = stack_b->next;
	if (first == NULL || first->next == NULL)
		return ;
	old_last = get_last_node(stack_b);
	new_last = old_last->previous;
	
	old_last->next = first;
	stack_b->next = old_last;
	new_last->next = 0;

	old_last->previous = stack_b;
	first->previous = old_last;

	//t_node *stack_a = NULL;
	//info_msg(0, "--> here");
	display_hor(stack_a, stack_b);
	//write(1, "rrb\n", 4);
}

/* rra and rrb at the same time */
void    rrr()
{
    
}