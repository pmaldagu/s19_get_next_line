/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:05:34 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/01 13:28:00 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char 	*ft_strdup(char *s)
{
	size_t i;
	size_t len;
	char *rest;
	char *tmp;

	i = 0;
	tmp = ft_strchr(s);
	if (ft_strchr(s) != NULL)
		len = ft_strlen(ft_strchr(s));
	else 
		len = 0;
	if ((rest = malloc(sizeof(char) * len + 1)) != NULL)
	{
		while ( i < len)
		{
			rest[i] = tmp[i];
			i++;
		}
		rest[i] = '\0';
		return (rest);
	}
	return (NULL);
}


char 	*ft_strchr(const char *s)
{
	int i;

	i = 0;
	while (s[i] !='\0')
	{
		if (s[i] == '\n')
			return (&((char *)s)[i + 1]);
		i++;
	}
	return (NULL);
}

char 	*ft_strjoin(const char *s1, const char *s2)
{
	int i;
	int j;
	char *join;

	i = 0;
	j = 0;
	if ((join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		if (s1 != NULL)
		{
			while (s1[i] != '\0' && s1 != NULL)
			{
				join[i] = s1[i];
				i++;
			}
		}
		while (s2[j] != '\0')
			join[i++] = s2[j++];
		join[i] = '\0';
		return (join);
	}
	return (NULL);
}
		
void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(char *)s++ = '\0';
		i++;
	}
}
