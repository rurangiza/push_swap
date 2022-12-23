/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:35 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/23 14:44:17 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/library/libft.h"
# include <stdlib.h> // malloc, free, NULL
# include <stdio.h>


/* TYPEDEFS AND STRUCTURES */

typedef struct s_node {
	int	content;
	struct s_node	*next;
	struct s_node	*previous;
	int				index;
	int				order;
}	t_node;

/* FUNCTION PROTOTYPES */
int		valid_number(char **arg_list, int index);
int		first_encounter_arg(int number, char **arguments, int position);
char	**initialize_matrix(int arg_count, char **argv);

void    push(int node_content, t_node *stack);

t_node	*create_node(int content);
void	add_back(t_node **lst, t_node *new);
void	delete_all_nodes(t_node **lst);
void	delete_one_node(t_node *lst);
t_node	*get_last_node(t_node *lst);
int		get_list_size(t_node *lst);

void	initialize_linkedlist(t_node *stack_a, t_node *stack_b, char **matrix);

void	sort(t_node *stack_a, t_node *stack_b);

void    sa(t_node *stack_a);
void    ra(t_node *stack_a);
void    rra(t_node *stack_a);

# endif