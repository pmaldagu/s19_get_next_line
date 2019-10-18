/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:36:47 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/18 18:09:38 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_firstcall(int fd)
{
	int i;
	int ret;
	char *tmp[BUFF_SIZE + 1];

	ret = read(fd, tmp, BUFF_SIZE);
	return (tmp);
}	

int ft_linesize(static char *file)
{
	int i;

	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
	{
		i++;
	}
	return (i)
}

char *ft_linemal(static char *file)
{
	int i;
	char *mal;

	i = 0;
	if ((mal = malloc(sizeof(char) * (ft_linesize(file) + 1))) != NULL)
	{
		while (file[i] != '\n' && file[i] != '\0')
		{
			mal[i] = file[i];
			i++;
		}
		mal[i] = '\0';
		return (mal);
	}
	return (NULL);
}

char *ft_newstc(static char *file)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	while (file[i] != '\0')
		i++;
	while (file[j] != '\n')
		j++;
	if ((tmp = malloc(sizeof(char) * (i + j))) != NULL)
	{
		j = j + 2;
		i = 0;
		while (file[j] != '\0')
		{
			tmp[i] = file[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL)
}

int	get_next_line(int fd, char **line)
{
	int i;
	int ret;
	static char *file;

	i = 0;
	ret = read(fd, ret, BUFF_SIZE + 1);
	if (file == NULL)
		file = ft_firstcall(fd);
	else
	{
		*line = ft_linemal(file);
		file = ft_newstc(file);
	}
	return (1);
}


