/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:26:56 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/11 18:51:53 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_buff(int fd, char **line, char *stack)
{
	char *buff;
	char *heap;
	int ret;
	
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
			break;
		if (!(buff = ft_calloc(1, (BUFFER_SIZE + 1))))
			return (-1);
		ret = read(fd, buff, BUFFER_SIZE);
		heap = *line;
		*line = ft_strjoin(*line, buff);
		free(heap);
		free(buff);
	}
	return (ret < 0 ? (-1) : ret);
}

char *ft_line(char *line)
{
	char *tmp;
	int i;
	int j;

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

int get_next_line(int fd, char **line)
{
	static char	*stack = NULL;
	int ret;

	if (fd < 0 || line == NULL || (ret = ft_buff(fd, line, stack)) < 0)
		return (-1);
	else if (!(stack = ft_strdup(ft_strchr(*line, '\n'))))
		return (-1);
	 if (!(*line = ft_line(*line)))
		return (-1);
	if (stack[0] == '\0' && ret == 0)
	{
		free(stack);
		return (0);
	}
	else
		return (1);
}
