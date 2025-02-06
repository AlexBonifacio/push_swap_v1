# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 11:09:10 by abonifac          #+#    #+#              #
#    Updated: 2025/02/06 16:35:36 by abonifac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap
SRCS = main.c ft_print_list.c ft_appnode.c ft_lstclear.c ft_lstdelone.c swaps.c \
		push.c rotate.c r_rotate.c \
		push_swap_utils.c ft_bubblesort.c small_sort.c check_params.c \
		
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: libft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

libft:
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: %.c push_swap.h Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft