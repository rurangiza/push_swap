/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:49:34 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/19 11:55:47 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int			data;
	struct node	*link;
};

int main(void)
{
	struct node *head = NULL;

	head = malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;
	return (0);
}