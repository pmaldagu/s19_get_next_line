/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:27:16 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/12 13:53:40 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&((char *)s)[i + 1]);
		i++;
	}
	return (NULL);
}

char	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*calloc;

	i = 0;
	if ((calloc = malloc(size * count)))
	{
		while (i < count * size)
		{
			calloc[i] = '\0';
			i++;
		}
		return (calloc);
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if ((join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		while (s1[i] != '\0')
		{
			join[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			join[i++] = s2[j++];
		join[i] = '\0';
		return (join);
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (ft_calloc(1, 1));
	if ((str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
