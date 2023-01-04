/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:24:25 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/04 16:40:32 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
