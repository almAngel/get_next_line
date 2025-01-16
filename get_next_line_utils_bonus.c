/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:17:05 by angellop          #+#    #+#             */
/*   Updated: 2025/01/16 21:41:39 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	s1_len;
	size_t	t_len;

	i = 0;
	s1_len = ft_strlen(s1);
	t_len = s1_len + ft_strlen(s2);
	s3 = ft_calloc(1, t_len + 1);
	if (!s3)
		return (NULL);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < t_len)
	{
		s3[i] = s2[i - s1_len];
		i++;
	}
	s3[i] = 0;
	return (s3);
}

void	ft_bzero(void *buff, size_t n)
{
	char	*buff_aux;
	size_t	i;

	i = 0;
	buff_aux = (char *) buff;
	while (i < n)
		buff_aux[i++] = '\0';
}

void	*ft_calloc(unsigned long int size, unsigned long int c)
{
	char	*result;

	result = malloc(size * c);
	if (!result)
		return (NULL);
	ft_bzero(result, (size * c));
	return (result);
}
