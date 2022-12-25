# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 09:27:45 by Arsene            #+#    #+#              #
#    Updated: 2022/12/25 23:08:51 by Arsene           ###   ########.fr        #
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
UNIT_TEST	=	./src/unit-testing/

# SOURCE FILES
SOURCE_FILES	=	${SRC_DIR}main.c \
					${SRC_DIR}parsing.c \
					${SRC_DIR}initializer.c \
					${SRC_DIR}sorting.c \
					${SRC_DIR}quicksort.c \
					${UTILS_DIR}linked_list.c \
					${UTILS_DIR}sorting_utils.c \
					${UTILS_DIR}quicksort_utils.c \
					${UTILS_DIR}display.c \
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