/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:35 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 18:26:39 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/library/libft.h"
# include <stdlib.h> // malloc, free, NULL
# include <stdio.h>

/* TYPEDEFS AND STRUCTURES */

typedef struct s_node {
	int				content;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

enum e_state {
	_top = 1,
	_bottom = 2,
};

/* PARSING */
char	**parse_input(int arg_count, char **argv);

int		is_valid_number(char **arg_list, int index);
int		first_encounter_arg(long number, char **arguments, int position);

/* INITIALIZER */
void	init_stack(t_node *stack_a, t_node *stack_b, char **matrix);

void	load_in_stack(int node_content, t_node *stack);
t_node	*create_node(int content);
void	add_back(t_node **lst, t_node *new);
void	delete_all_nodes(t_node **lst);
void	delete_one_node(t_node *lst);
t_node	*get_last_node(t_node *lst);
int		get_list_size(t_node *lst);

/* OPERATIONS */
void	sa(t_node *stack_a, t_node *stack_b);
void	sb(t_node *stack_b, t_node *stack_a);
void	ra(t_node *stack_a, t_node *stack_b);
void	rra(t_node *stack_a, t_node *stack_b);
void	rb(t_node *stack_b, t_node *stack_a);
void	rrb(t_node *stack_b, t_node *stack_a);
void	pb(t_node *stack_a, t_node *stack_b);
void	pa(t_node *stack_a, t_node *stack_b);
void	rr(t_node *stack_a, t_node *stack_b);
void	rrr(t_node *stack_a, t_node *stack_b);
void	ss(t_node *stack_a, t_node *stack_b);

/* SORTING */
void	sort_stack(t_node *stack_a, t_node *stack_b);

void	small_sort(t_node *stack_a, t_node *stack_b);
void	big_sort(t_node *stack_a, t_node *stack_b);

void	sort_trio(t_node *stack_a, t_node *stack_b);

void	set_two_aside(t_node *stack_a, t_node *stack_b);
void	bring_two_back(t_node *stack_a, t_node *stack_b);

void	empty_main_stack(t_node *stack_a, t_node *stack_b, int cutoff);
void	empty_temporary_stack(t_node *stack_a, t_node *stack_b);
void	handle_pushables(t_node *stack_a, t_node *stack_b,
			int pivot, int *pushables);
void	keep_largest_ontop(t_node *stack_a, t_node *stack_b);

/* CHECKERS */
int		is_sorted(t_node *stack_a);
int		is_sorted_asc(t_node *stack_a, int start, int end);
int		is_sorted_desc(t_node *stack, int start, int end);

/* FINDERS */
int		find_smallest_nbr(t_node *stack_a);
int		find_largest_nbr(t_node *stack_a);
int		find_node_position(t_node *list, int content);
int		find_quartile(t_node *stack, int start, int end, int stack_size);
int		find_octile(t_node *stack, int start, int end, int stack_size);
int		find_sextuplet(t_node *stack, int start, int end, int stack_size);
/* COUNTERS */
int		count_pushables(t_node *stack_a, int pivot, int start, int end);

void	bring_closest_pushable_ontop(t_node *stack_a, t_node *stack_b,
			int pivot);

int		selection_sort(int *unsorted, int size);
int		insertion_sort(int *unsorted, int size);

/* DISPLAY */
void	break_msg(char *message, ...);
void	display_hor(t_node *stack_a, t_node *stack_b);
int		first_encounter_gen(int number, int *list, int position);
int		*random_numbers(int size, int threshold);

/* MEMORY */
void	free_stacks(t_node *stack_a, t_node *stack_b);

int		num_checker(char *strnum, int *sign_counter,
			int *digit_counter, int index);

/* ERROR HANDLING */
int		rmessage(void);

#endif