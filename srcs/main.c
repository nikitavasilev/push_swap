/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:43 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/22 11:12:01 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_pos	*stack_a;
	char	**args;

	if (argc >= 2)
	{
		args = parse(argv);
		stack_a = fill_stack(args);
		print_list(stack_a);
		del_list(stack_a->head);
		free(stack_a);
	}
	else
		ft_error("Usage: ./push_swap <integers>");
	return (0);
}
