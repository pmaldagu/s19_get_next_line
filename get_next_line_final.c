/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:25:19 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/04 17:57:54 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int ft_read(char **line, char *stack, int fd)
{
	char *tmp;
	char buff[BUFFER_SIZE + 1]

	tmp = NULL;
	while (ret = read(fd, buff, BUFFER_SIZE) > 0 && ft_strchr(stack) == NULL)
	{
		buff[ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, buff);
		if (tmp != NULL)
			free(tmp);
	}
	if (*line == NULL)
		*line = ft_strjoin(tmp, stack);
	stack = ft_memmove(buff, ft_strchr(buff));
	if (*line != NULL)
		return (1);
	else if (stack[0] == '\0')
	{
		free(*line);
		stack = NULL;
		return (0);
	}
	else 
		return (-1);
}

int get_next_line(int fd, char **line)
{
	static char *stack[FD_MAX];
	
	if (fd < 0)
			return (-1);
	return (ft_read(line, stack[fd], fd));
}
