/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:35 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/21 13:34:00 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/library/libft.h"
# include <stdlib.h> // malloc, free, NULL


/* TYPEDEFS AND STRUCTURES */

typedef struct s_node {
	int	content;
	struct s_node	*next;
	struct s_node	*previous;
	int				index;
}	t_node;

/* FUNCTION PROTOTYPES */
int		valid_number(char **arg_list, int index, int arg_type);
int		first_encounter(int number, char **arguments, int position, int arg_type);
char	**init_matrix(int arg_count, char **argv);

void    push(int node_content, t_node *stack);
t_node	*create_node(int content);
void	add_back(t_node **lst, t_node *new);
void	delete_all_nodes(t_node **lst);
void	delete_one_node(t_node *lst);
t_node	*get_last_node(t_node *lst);

# endif