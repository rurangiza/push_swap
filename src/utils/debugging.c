/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:42:01 by Arsene            #+#    #+#             */
/*   Updated: 2023/01/09 17:09:24 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>
#include <time.h>

void	display_hor(t_node *stack_a, t_node *stack_b)
{
	static int	opglobal = 0;
	t_node		*tmp_a;
	t_node		*tmp_b;

	opglobal++;
	tmp_b = stack_b->next;
	tmp_a = stack_a->next;
	system("clear");
	printf("\033[32mStack A: \033[0m");
	while (tmp_a)
	{
		printf("%d ", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	printf("\033[33mStack B: \033[0m");
	while (tmp_b)
	{
		printf("%d ", tmp_b->content);
		tmp_b = tmp_b->next;
	}
	printf("\n");
	printf("=> %d operations\n", opglobal);
}

int	first_encounter_gen(int number, int *list, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		if (number == list[i])
			return (0);
		i++;
	}
	return (1);
}

void	break_msg(char *message, ...)
{
	va_list	args;
	int		index;

	ft_putstr("\033[34m○\033[0m ");
	va_start(args, message);
	index = 0;
	while (message[index])
	{
		if (message[index] == '%')
		{
			if (message[index + 1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (message[index + 1] == 'd')
				ft_putnbr(va_arg(args, int));
			index++;
		}
		else
			ft_putchar(message[index]);
		index++;
	}
	write(1, "\n", 1);
	usleep(1000000);
}

int	*random_numbers(int size, int threshold)
{
	int	index;
	int	*list;
	int	sign;
	int	number;

	list = malloc(sizeof(int) * size);
	srand(time(0));
	index = 0;
	while (index < size)
	{
		sign = 1;
		if (rand() % 3 == 1)
			sign = -1;
		number = (rand() % threshold) * sign;
		while (!first_encounter_gen(number, list, index))
		{
			number = (rand() % threshold) * sign;
		}
		list[index] = number;
		index ++;
	}
	return (list);
}
