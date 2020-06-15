/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:26:56 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/12 16:57:38 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_errfree(char *stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
	return (-1);
}

int		ft_buff(int fd, char **line, char *stack)
{
	char	*buff;
	char	*heap;
	int		ret;

	ret = 1;
	if (stack == NULL)
		if (!(*line = ft_calloc(1, 1)))
			return (-1);
	if (stack != NULL)
		if (!(*line = ft_strdup(stack)))
			return (-1);
	while (ret > 0)
	{
		if (ft_strchr(*line, '\n'))
			break ;
		if (!(buff = ft_calloc(1, (BUFFER_SIZE + 1))))
			return (-1);
		ret = read(fd, buff, BUFFER_SIZE);
		heap = *line;
		*line = ft_strjoin(*line, buff);
		free(heap);
		free(buff);
	}
	return (ret);
}

char	*ft_line(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if ((tmp = malloc(sizeof(char) * (i + 1))))
	{
		while (j < i)
		{
			tmp[j] = line[j];
			j++;
		}
		tmp[j] = '\0';
		free(line);
		return (tmp);
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static char	*stack[FOPEN_MAX];
	int			ret;

	if (BUFFER_SIZE < 1)
		return (-1);
	else if (fd < 0 || line == NULL || (ret = ft_buff(fd, line, stack[fd])) < 0)
		return (ft_errfree(stack[fd]));
	free(stack[fd]);
	if (!(stack[fd] = ft_strdup(ft_strchr(*line, '\n'))))
		return (-1);
	else if (!(*line = ft_line(*line)))
		return (ft_errfree(stack[fd]));
	if (stack[fd][0] == '\0' && ret == 0)
	{
		free(stack[fd]);
		stack[fd] = NULL;
		return (0);
	}
	else
		return (1);
}
