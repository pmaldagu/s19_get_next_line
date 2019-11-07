/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:25:19 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/07 16:33:18 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define FD_MAX 1024

void ft_bzero(char *stack)
{
	size_t i;

	i = 0;
	while (i < (BUFF_SIZE + 1))
	{
		stack[i] = '\0';
		i++;
	}
}

int ft_read(char **line, char *stack, int fd)
{
	char *tmp;
	static int ret;

	tmp = "";
	tmp = ft_strjoin(tmp, stack);
	//write(1, "tmp : ", 6);
	//printf("%s\n", tmp);
	ft_bzero(stack);
	while (((ret = read(fd, stack, BUFF_SIZE)) > 0) && ft_strchr(stack) == NULL)
	{	
		//write(1, "buff : ", 7);
		stack[ret] = '\0';
		//printf("%s\n", stack);
		tmp = ft_strjoin(tmp, stack);
		//ft_bzero(stack);
	}
	if (ret != 0)
		tmp = ft_strjoin(tmp, stack);
	//write(1, "buffendloop : ", 14);
	//printf("%s\n", stack);
	//write(1, "strjoin : ", 10);
	//printf("%s\n", tmp);
	*line = ft_strdup(tmp);
	//write(1, "stack : ", 8);
	stack = ft_strcpy(stack, ft_strchr(tmp));
	//printf("%s\n", stack);
	free(tmp);
	//write(1, "end------:", 10);
	if (stack == NULL)
		return (0);
	else if (*line != NULL)
		return (1);
	else 
		return (-1);
}

int get_next_line(int fd, char **line)
{
	static char stack[FD_MAX][BUFF_SIZE + 1];
	
	if (fd < 0 && BUFF_SIZE < 1)
			return (-1);
	//printf("%d\n",ft_read(line, stack[fd], fd));
	return (ft_read(line, stack[fd], fd));
}
