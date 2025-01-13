/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:17:57 by angellop          #+#    #+#             */
/*   Updated: 2025/01/13 21:26:32 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*ft_check_for_line_return_remainder(char *buff)
{
	char	*newline;

	newline = ft_strchr(buff, '\n');
	if (newline)
		return (newline + 1);
	return (buff);
}

char *ft_cut_till_newline_including(char *buff)
{
	char *response;
	int i;

	i = 0;
	response = ft_strdup(buff);
	if (ft_strchr(response, '\n'))
	{
		while (response[i] != '\n')
			i++;
		response[i + 1] = 0;
		return (response);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	char buff[BUFFER_SIZE + 1];
	static char *remainder;
	char *line;
	ssize_t bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd <= 0)
		return (NULL);
	else
	{
		if (!remainder)
			remainder = ft_strdup("");
		while (bytes_read > 0)
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			buff[bytes_read] = 0;
			remainder = ft_strjoin(remainder, buff);
			line = ft_strchr(remainder, '\n');
			if (line)
			{
				line = ft_cut_till_newline_including(remainder);
				remainder = ft_check_for_line_return_remainder(remainder);
				return (line);
			}
		}
	}
	return (line);
}

int main(void)
{
	#include "fcntl.h"
	int fd = open("data", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}