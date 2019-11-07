/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:37:32 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/07 16:35:19 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char 	*ft_strchr(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
//void	ft_bzero(void *s, size_t n);
char	*ft_line(char *s);
int		ft_read(char **line, char *stack, int fd);
int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dst, char *src);
void	ft_bzero(char *stack);

# endif
