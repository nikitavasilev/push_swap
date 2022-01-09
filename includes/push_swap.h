/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:19:13 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/21 23:17:09 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	char	*str;
	t_list	*next;
};


int	check_args(int argc, char const *argv[]);

// UTILS
int		ft_isdigit(int c);
void	ft_error(const char *str);
int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);

#endif
