/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:36:47 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/18 15:45:38 by pmaldagu         ###   ########.fr       */
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

int ft_linesize(char file)
{
	int i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
	}
	return (i)
}

char *ft_linemal(char file)
{
	int i;
	char *mal;

	i = 0;
	if ((mal = malloc(sizeof(char) * (ft_linesize(file) + 1))) != NULL)
	{
		while (abuf[i] != '\n' && abuf != '\0')
		{
			mal[i] = abuf[i];
			i++;
		}
		mal[i] = '\0';
		return (mal);
	}
	return (NULL);
}

char *
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

