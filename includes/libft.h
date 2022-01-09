/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:42:20 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/09 06:48:13 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_issign(int c);
void	ft_error(const char *str);
int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

#endif
