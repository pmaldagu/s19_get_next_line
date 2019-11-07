/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:05:34 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/07 16:21:15 by pmaldagu         ###   ########.fr       */
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

	i = 0;
	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if ((rest = malloc(sizeof(char) * len + 1)) != NULL)
	{
		while (i < len)
		{
			rest[i] = s[i];
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
	while (s[i] != '\0')
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
	if (s2 == NULL)
		return (ft_strdup(""));
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

char	*ft_strcpy(char *dst, char *src)
{
		int i;

		i = 0;
		if (!dst || !src)
			return (NULL);
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		while (dst[i] != '\0')
		{
			dst[i] = '\0';
			i++;
		}
		dst[i] = '\0';
		return (dst);
}
