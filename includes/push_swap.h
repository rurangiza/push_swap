/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:35 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 20:13:49 by Arsene           ###   ########.fr       */
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

/* PARSING */
char	**parse_input(int arg_count, char **argv);

int		valid_number(char **arg_list, int index);
int		first_encounter_arg(int number, char **arguments, int position);

/* INITIALIZER */
void	init_stack(t_node *stack_a, t_node *stack_b, char **matrix);

void    push(int node_content, t_node *stack);
t_node	*create_node(int content);
void	add_back(t_node **lst, t_node *new);
void	delete_all_nodes(t_node **lst);
void	delete_one_node(t_node *lst);
t_node	*get_last_node(t_node *lst);
int		get_list_size(t_node *lst);


/* OPERATIONS */
void    sa(t_node *stack_a);
void    ra(t_node *stack_a);
void    rra(t_node *stack_a);
void    pb(t_node *stack_a, t_node *stack_b);
void    pa(t_node *stack_a, t_node *stack_b);

/* SORTING */
void	sort_stack(t_node *stack_a, t_node *stack_b);

void	handle_3(t_node *stack_a);
void	handle_5(t_node *stack_a, t_node *stack_b);
void	handle_100(t_node *stack_a, t_node *stack_b);

int		is_sorted(t_node *stack_a);
int		find_smallest_nbr(t_node *stack_a);

/* PARTITION */
void	quicksort(t_node *stack_a, t_node *stack_b, int start, int end);

int		find_node_position(t_node *list, int content);
void	move_pivot_ontop(t_node *stack_a, int pivot);
int		count_pushables(t_node *stack_a, int pivot);
int		find_pivot(t_node *stack_a, int start, int end, int stack_size);
int		ft_abs(int x);
int		calc_average(t_node *stack_a, int start, int end, int stack_size);
int		push_to_b(t_node *stack_a, t_node *stack_b, int elements_to_push, int pivot);

# endif