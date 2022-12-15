# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 09:27:45 by Arsene            #+#    #+#              #
#    Updated: 2022/12/15 11:40:57 by Arsene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM
NAME	=	push_swap
LIBFT	=	./src/libft/libft.a

# DERECTORIES
LIBFT_DIR	=	./src/libft/

# SOURCE FILES
SOURCE_FILES	=	./src/push_swap.c \

# VARIABLES
COMPILER	= 	gcc
C_FLAGS		=	-Wall -Wextra -Werror
rm			=	rm -f

OBJ			=	${SOURCE_FILES:.c=.o}

# RULES
%.o: 		%.c
				@$(COMPILER) $(C_FLAGS) -c $< -o $@

$(NAME): 	$(OBJ) $(LIBFT)
				@$(COMPILER) $(OBJ) $(LIBFT_DIR)libft.a -o $(NAME)

$(LIBFT):
				@make -C $(LIBFT_DIR)

all:		$(NAME)

clean:
				@make -C $(LIBFT_DIR) fclean
				@rm -f $(OBJ) core

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re