/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:17:05 by angellop          #+#    #+#             */
/*   Updated: 2025/01/15 22:37:17 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	c %= 256;
	if (c == '\0')
		return ((char *) &s[s_len]);
	while (s[i] && s[i] != c)
		i++;
	if (i == s_len)
		return (0);
	return ((char *) &s[i]);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s_cpy;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	s_cpy = malloc(len + 1);
	if (!s_cpy)
	{
		free(s_cpy);
		s_cpy = NULL;
		return (NULL);
	}
	while (s[i])
	{
		s_cpy[i] = s[i];
		i++;
	}
	s_cpy[i] = 0;
	return (s_cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	s1_len;
	size_t	t_len;

	i = 0;
	s1_len = ft_strlen(s1);
	t_len = s1_len + ft_strlen(s2);
	s3 = malloc(t_len + 1);
	if (!s3)
		return (NULL);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	free(s1);
	while (i < t_len)
	{
		s3[i] = s2[i - s1_len];
		i++;
	}
	s3[i] = 0;
	return (s3);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*response;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	response = malloc(len + 1);
	if (!response)
		return (NULL);
	i = 0;
	while (i < len)
	{
		response[i] = s[start + i];
		i++;
	}
	response[i] = 0;
	return (response);
}
