/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:18:04 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/01 17:21:36 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
//#define BUFF_SIZE 32

char *ft_line(char *s)
{
	char *line;
	int i;

	i = 0;
	//write(1, "ok", 2);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	printf("%d\n", i);
	if ((line = malloc (sizeof(char) * (i + 1))) != NULL)
	{
		i = 0;
		while (s[i] != '\n' && s[i] !='\0')
		{
			line[i] = s[i];
			i++;
		}
		line[i] = '\0';
		return (line);
	}
	return (NULL);
}


char *ft_read(char **line, char *s, int fd)
{
	int ret;
	char buff[BUFF_SIZE + 1];
	char *tmp;
	
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = s;
		s = ft_strjoin(s, buff);
		if (tmp != NULL)
			free(tmp);
		if (ft_strchr(s) != NULL)
			break;
	}
	//printf("%s\n", s);
	//tmp = *line;
	*line = ft_line(s);
	//if (tmp != NULL)
		//free(tmp);
	//tmp = s;
	s = ft_strdup(s);
	//free (tmp);
	return (s);
}

int get_next_line(int fd, char **line)
{
	static char *s;

	if (fd < 0)
		return (-1);
	s = ft_read(line, s, fd);
	//else if (s == NULL)
	//	return (0);
	//else
		return (1);
/*	else if (*line == '\0')
	{
		//free(*line);
		return (0);
	}
	else 
		return (-1);*/
}

/*int main ()
{
	//int fd = open("test.txt", O_RDONLY);
	//char **line = NULL;
	//static char *s;
	//char buff[32] = "first line";

	//s = ft_read(line, s ,fd);
	//free(*line);
	//printf("%zu\n", ft_strlen(s));
	//printf("%s\n", ft_strjoin(s ,buff));
	//s = ft_read(line, s, fd);
	//get_next_line(fd, line);
	//printf("%s\n", *line);
	//printf("%s\n", s);
	//printf("%s\n", ft_read(line, s ,fd));
	//free(*line);
	//printf("%s\n", ft_read(line, s ,fd));
	return 0;
}
*/
