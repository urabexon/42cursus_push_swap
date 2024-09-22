# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 16:06:25 by hurabe            #+#    #+#              #
#    Updated: 2024/09/22 18:49:27 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	push_swap
INCLUDE					=	push_swap.h
CFLAGS					=	-Wall -Wextra -Werror
RM						=	rm -f
FOLDER					=	src
ITEM_FOLDER				=	src/items
LIBFT_FOLDER			=	src/libft

FUNCTIONS				=	$(FOLDER)/push_swap.c $(FOLDER)/init_dst.c $(FOLDER)/error.c $(FOLDER)/ps_isfunction.c $(FOLDER)/radix_sort.c\
							$(FOLDER)/sep_pivot.c $(FOLDER)/coordinate_press.c $(ITEM_FOLDER)/push.c $(ITEM_FOLDER)/reverse_rotate.c $(ITEM_FOLDER)/rotate.c\
							$(ITEM_FOLDER)/swap.c $(LIBFT_FOLDER)/ft_atoi.c $(LIBFT_FOLDER)/ft_atol.c $(LIBFT_FOLDER)/ft_isdigit.c $(LIBFT_FOLDER)/ft_lstadd_back.c\
							$(LIBFT_FOLDER)/ft_lstclear.c $(LIBFT_FOLDER)/ft_lstlast.c $(LIBFT_FOLDER)/ft_lstnew.c $(LIBFT_FOLDER)/ft_lstsize.c $(LIBFT_FOLDER)/ft_split.c\
							$(LIBFT_FOLDER)/ft_strcmp.c $(LIBFT_FOLDER)/ft_strlen.c

OBJ	= $(FUNCTIONS:.c=.o)

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
	$(RM) $(NAME) $(OBJ)

re: clean all

.PHONY: all clean fclean re