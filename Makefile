# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 16:06:25 by hurabe            #+#    #+#              #
#    Updated: 2024/09/20 17:26:14 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	push_swap
INCLUDE					=	push_swap.h
CFLAGS					=	-Wall -Wextra -Werror
RM						=	rm -fclean
FOLDER					=	src
ITEM_FOLDER				=	src/items
LIBFT_FOLDER			=	src/libft

FUNCTIONS				=	$(FOLDER)/push_swap.c 

OBJ	= $(FUNCTION:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -I$(INCLUDE) $(OBJ) -o push_swap

.c.o:
	cc $(CFLAGS) -I$(INCLUDE) -c $< -o $@

fsanitize:
	cc $(CFLAGS) -g -fsanitize=address -I$(INCLUDE) $(FUNCTIONS) -o push_swap

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re