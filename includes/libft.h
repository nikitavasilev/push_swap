/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:42:20 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/17 06:23:09 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_issign(int c);
void		ft_error(const char *str);
int			ft_putchar_fd(int c, int fd);
void		ft_putstr_fd(const char *str, int fd);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
int			atoi_err_overflow(const char *str, int *err);
char		*strjoin_free_s1(char *s1, char const *s2);

#endif
