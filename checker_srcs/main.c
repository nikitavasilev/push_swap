/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:40:25 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/29 20:14:25 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "checker.h"
#include <stdio.h>

static void	do_operations(char *line, t_pos *stack_a, t_pos *stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_c(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_c(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_c(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa_c(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_c(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_c(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_c(stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_c(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_c(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_c(stack_a, stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_c(stack_a, stack_b);
	else
		ft_error("Error");
}

static void	read_input(t_pos *stack_a, t_pos *stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		do_operations(line, stack_a, stack_b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char const *argv[])
{
	t_pos	*stack_a;
	t_pos	*stack_b;
	char	**args;

	if (argc > 1)
	{
		args = parse(argv);
		if (!args)
			ft_error("Error");
		stack_a = fill_stack(args);
		stack_b = alloc_pos();
		if (!stack_b)
		{
			free_stacks(stack_a, stack_b);
			ft_error("Error");
		}
		read_input(stack_a, stack_b);
		if (!is_sorted(stack_a))
			ft_putstr_fd("KO\n", STDOUT_FILENO);
		else
			ft_putstr_fd("OK\n", STDOUT_FILENO);
		free_stacks(stack_a, stack_b);
	}
	return (0);
}
