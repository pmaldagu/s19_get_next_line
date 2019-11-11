/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:37:32 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/11 16:52:24 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
int		ft_buff(int fd, char **line, char *stack);
char	*ft_strdup(char *s);
char 	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
//void	ft_bzero(void *s, size_t n);
char	*ft_line(char *line);
int		ft_read(char **line, char *stack, int fd);
int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dst, char *src);
void	ft_bzero(char *stack);
char	*ft_calloc(size_t count, size_t size);

# endif
