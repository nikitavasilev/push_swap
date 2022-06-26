# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 18:57:42 by nvasilev          #+#    #+#              #
#    Updated: 2022/06/26 22:49:02 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = 			push_swap
CHECKER = 		checker

CC = 			cc
CFLAGS =		-Wall -Wextra -Werror -g3
RM =			rm -f

INCLUDES =		-I ./includes/

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

PUSH_SWAP_SRCS =	./push_swap_srcs/main.c \
					./push_swap_srcs/create_node.c \
					./push_swap_srcs/del_list.c \
					./push_swap_srcs/alloc_struct.c \
					./push_swap_srcs/swap.c \
					./push_swap_srcs/rotate.c \
					./push_swap_srcs/rrotate.c \
					./push_swap_srcs/print_list.c \
					./push_swap_srcs/parser.c \
					./push_swap_srcs/fill_stack.c \
					./push_swap_srcs/check_dups.c \
					./push_swap_srcs/push.c \
					./push_swap_srcs/sort.c \
					./push_swap_srcs/bubble_sort.c \
					./push_swap_srcs/selection_sort_big.c \
					./push_swap_srcs/selection_sort_stop.c \
					./push_swap_srcs/selection_sort_invert.c \
					./push_swap_srcs/insertion_sort.c \
					./push_swap_srcs/find_median.c \
					./push_swap_srcs/sorted.c \
					./push_swap_srcs/smart_swap.c \
					./push_swap_srcs/find_min.c \
					./push_swap_srcs/find_shortest_path.c \
					./push_swap_srcs/chunks.c \
					./push_swap_srcs/find_max.c \
					./push_swap_srcs/selection_sort_small.c \
					./push_swap_srcs/get_chunks.c

CHECKER_SRCS =		./checker_srcs/main.c

UTILS =				./utils/ft_putchar_fd.c \
					./utils/ft_putstr_fd.c \
					./utils/ft_error.c \
					./utils/ft_isdigit.c \
					./utils/ft_isspace.c \
					./utils/ft_issign.c \
					./utils/ft_split.c \
					./utils/ft_strlen.c \
					./utils/ft_strdup.c \
					./utils/atoi_err_overflow.c \
					./utils/strjoin_free_s1.c \
					./utils/ft_putnbr_fd.c \
					./utils/power.c

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS_PUSH_SWAP =	$(PUSH_SWAP_SRCS:%.c=%.o)
OBJS_CHECKER =		$(CHECKER_SRCS:%.c=%.o)
OBJS_UTILS =		$(UTILS:%.c=%.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_UTILS) $(OBJS_PUSH_SWAP)
	$(CC) $(OBJS_UTILS) $(OBJS_PUSH_SWAP) $(INCLUDES) -o $@

clean:
	$(RM) $(OBJS_UTILS) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean:	clean
	$(RM) $(NAME) $(CHECKER)

re:	fclean all

bonus:	$(CHECKER)

$(CHECKER): $(OBJS_UTILS) $(OBJS_CHECKER)
	$(CC) $(OBJS_UTILS) $(OBJS_CHECKER) $(INCLUDES) -o $@

.PHONY: all clean fclean re
