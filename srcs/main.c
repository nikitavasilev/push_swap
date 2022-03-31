/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:43 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 07:49:34 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char const *argv[])
{
	t_pos	*stack_a;
	t_pos	*stack_b;
	char	**args;

	if (argc >= 2)
	{
		args = parse(argv);
		stack_a = fill_stack(args);
		stack_b = alloc_pos();
		print_stacks(stack_a, stack_b);
		free_stacks(stack_a, stack_b);
	}
	return (0);
}
