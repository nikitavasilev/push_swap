/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:05:38 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/04 06:03:21 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include "libft.h"

static void	print_line_info(char stack, int size, int data)
{
	if (stack == 'a' || stack == 'b')
	{
		ft_putstr_fd("\nStack ", STDOUT_FILENO);
		if (stack == 'a')
			ft_putchar_fd('a', STDOUT_FILENO);
		else
			ft_putchar_fd('b', STDOUT_FILENO);
		ft_putstr_fd(" of size ", STDOUT_FILENO);
		ft_putnbr_fd(size, STDOUT_FILENO);
		ft_putstr_fd(":\n", STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd("Node no ", STDOUT_FILENO);
		ft_putnbr_fd(size, STDOUT_FILENO);
		ft_putstr_fd(": ", STDOUT_FILENO);
		ft_putnbr_fd(data, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

static void	print_list(t_pos *pos, char stack)
{
	t_list	*current;
	int		i;

	if (!pos || !pos->head)
		return ;
	current = pos->head;
	print_line_info(stack, pos->size, 0);
	i = 0;
	while (current != pos->tail)
	{
		print_line_info(' ', i++, current->data);
		current = current->next;
	}
	if (pos->tail)
		print_line_info(' ', i++, current->data);
}

void	print_stacks(t_pos *stack_a, t_pos *stack_b)
{
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
}
