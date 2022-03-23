/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:43 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/23 21:16:19 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

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
		printf("Stack a:\n");
		print_list(stack_a);
		stack_b = alloc_pos();
		push(stack_a, stack_b);
		printf("Stack b:\n");
		print_list(stack_b);
		printf("Stack a:\n");
		print_list(stack_a);
		del_list(stack_a->head);
		del_list(stack_b->head);
		free(stack_a);
		free(stack_b);
	}
	return (0);
}
