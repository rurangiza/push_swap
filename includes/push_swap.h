/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:35 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/20 17:26:36 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/library/libft.h"
# include <stdlib.h> // malloc, free

/* TYPEDEFS AND STRUCTURES */
typedef struct s_dllist {
	int            content;
	int				index;
	struct s_dllist	*next;
	struct s_dllist	*previous;
}	t_dllist;

/* FUNCTION PROTOTYPES */
int		valid_number(char **arg_list, int index, int arg_type);
int		first_encounter(int number, char *arguments, int position, int arg_type);
char	**init_matrix(int arg_count, char **argv, int *arg_type, int *index);

void    push(int node_content, t_dllist *stack);
t_list	*dll_create_node(int content);
void	dll_add_back(t_list **lst, t_list *new);

# endif