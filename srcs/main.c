/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:43 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/17 06:53:13 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	//t_pos	*stack_a;
	char	**args;
	size_t	i;

	if (argc >= 2)
	{
		args = parse(argv);
		i = 0;
		while (args[i])
		{
			printf("%s\n", args[i]);
			free(args[i]);
			i++;
		}
		free(args);
		//stack_a = fill_stack(args);
		//print_list(stack_a);
		//del_list(stack_a->head);
		//free(stack_a);
	}
	else
		ft_error("Usage: ./push_swap <integers>");
	return (0);
}
