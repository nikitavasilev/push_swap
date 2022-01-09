/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:40:40 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/09 16:57:48 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static char	*parse_integers(int argc, char const *argv[])
{
	int		i;
	char	*tmp;

	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(tmp, argv[i]);
		if (!tmp)
			return (NULL);
		i++;
	}
	return (tmp);
}

int	check_args(int argc, char const *argv[])
{
	int		i;
	char	*args;
	size_t	j;
	t_list	*list;

	list = NULL;
	(void)list;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]))
				if (!ft_issign(argv[i][j]))
					if (!ft_isdigit(argv[i][j]))
						ft_error("Error");
			j++;
		}
		i++;
	}
	args = parse_integers(argc, argv);
	printf("%s\n", args);
	return (1);
}
