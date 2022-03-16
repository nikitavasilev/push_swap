# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 18:57:42 by nvasilev          #+#    #+#              #
#    Updated: 2022/03/16 20:00:00 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = 			push_swap

CC = 			gcc
CFLAGS =		-Wall -Wextra -Werror
RM =			rm -f

INCLUDES = -I ./includes/

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS =			./srcs/main.c \
				./srcs/check_args.c \
				./srcs/create_node.c \
				./srcs/del_list.c \
				./srcs/alloc_struct.c \
				./srcs/swap.c \
				./srcs/rotate.c \
				./srcs/rrotate.c

UTILS =			./utils/ft_putchar_fd.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_error.c \
				./utils/ft_isdigit.c \
				./utils/ft_isspace.c \
				./utils/ft_issign.c \
				./utils/ft_split.c \
				./utils/ft_strlen.c \
				./utils/ft_strjoin.c \
				./utils/ft_strdup.c \
				./utils/atoi_err_overflow.c

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS_SRCS =		$(SRCS:%.c=%.o)
OBJS =			$(UTILS:%.c=%.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_SRCS)
	$(CC) $(OBJS) $(OBJS_SRCS) $(INCLUDES) -o $@

clean:
	$(RM) $(OBJS) $(OBJS_SRCS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
