/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:42:20 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/29 20:07:19 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define BUFFER_SIZE 32
# define MAX_FD 256

int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_issign(int c);
void		ft_error(const char *str);
int			ft_putchar_fd(int c, int fd);
void		ft_putstr_fd(const char *str, int fd);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			atoi_err_overflow(const char *str, int *err);
char		*strjoin_free_s1(char *s1, char const *s2);
void		ft_putnbr_fd(int n, int fd);
float		power(float x, int y);
char		*get_next_line(int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
