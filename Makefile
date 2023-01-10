# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 09:27:45 by Arsene            #+#    #+#              #
#    Updated: 2023/01/10 09:46:04 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM
NAME	=	push_swap
LIBFT	=	./src/library/libft.a

# DERECTORIES
LIBFT_DIR	=	./src/library/
SRC_DIR		=	./src/
UTILS_DIR	=	./src/utils/
OP_DIR		=	./src/operations/

# SOURCE FILES
SOURCE_FILES	=	${SRC_DIR}main.c \
					${SRC_DIR}parsing.c \
					${SRC_DIR}initializer.c \
					${SRC_DIR}sorting.c \
					${SRC_DIR}pivot_selection.c \
					${SRC_DIR}small_list.c \
					${SRC_DIR}big_list.c \
					${UTILS_DIR}linked_list.c \
					${UTILS_DIR}checker.c \
					${UTILS_DIR}counter.c \
					${UTILS_DIR}finder.c \
					${UTILS_DIR}debugging.c \
					${UTILS_DIR}memory_management.c \
					${OP_DIR}push.c \
					${OP_DIR}swap.c \
					${OP_DIR}rotate.c \
					${OP_DIR}reverse_rotate.c \
					

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

test:
		@gcc -Wall -Werror -Wextra practice.c -o runthis
		@./runthis