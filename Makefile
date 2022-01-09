# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 18:57:42 by nvasilev          #+#    #+#              #
#    Updated: 2022/01/09 16:57:01 by nvasilev         ###   ########.fr        #
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
				./srcs/check_args.c

UTILS =			./utils/ft_putchar_fd.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_error.c \
				./utils/ft_isdigit.c \
				./utils/ft_atoi.c \
				./utils/ft_isspace.c \
				./utils/ft_issign.c \
				./utils/ft_split.c \
				./utils/ft_strlen.c \
				./utils/ft_strjoin.c \
				./utils/ft_strdup.c \
				./utils/atoint128.c

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
