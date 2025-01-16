/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:17:57 by angellop          #+#    #+#             */
/*   Updated: 2025/01/16 03:34:56 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_check_for_line_return_remainder(char *buff)
{
	char *newline;
	
	if (!*buff)
	{
		free(buff);
		return (NULL);
	}
	newline = ft_strchr(buff, '\n');
	if (newline)
		return (ft_strdup(newline + 1));
	return (NULL);
}

char	*ft_cut_till_newline_including(char *buff)
{
	char *line;
	char *nl;
	int i;
	int len;

	i = 0;
	if (!*buff)
		return (NULL);
	nl = ft_strchr(buff, '\n');
	len = (nl - buff) + 1;
	line = malloc(len + 1);
	while (i < len)
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char *ft_safe_strjoin(char *remaining, char *buff)
{
	char *new;

	new = ft_strjoin(remaining, buff);
	free(remaining);
	return (new);
}

char *ft_mount_line(int fd, char *remaining)
{
	char buff[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	if (!remaining)
		remaining = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remaining);
			return (NULL);
		}
		buff[bytes_read] = 0;
		remaining = ft_safe_strjoin(remaining, buff);
		if (ft_strchr(remaining, '\n'))
			break;
	}
	return (remaining);
}

char *get_next_line(int fd)
{
	static char *remaining;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	remaining = ft_mount_line(fd, remaining);
	if (!remaining)
		return (NULL);
	line = ft_cut_till_newline_including(remaining);
	remaining = ft_check_for_line_return_remainder(remaining);

	return (line);
}

#include <fcntl.h>
int main(void)
{
	int fd;
	char *line;

	// Test archivo normal
	printf("\n=== Test archivo normal ===\n");
	fd = open("normal.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);

	// // Test archivo vacío
	// printf("\n=== Test archivo vacío ===\n");
	// fd = open("empty.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	//     printf("%s", line);
	// 	free(line);
	// }
	// close(fd);

	// Test archivo 1char
	printf("\n=== Test archivo 1char ===\n");
	fd = open("1char", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);

	// // Test archivo mutiple_nl
	// printf("\n=== Test archivo mutiple_nl ===\n");
	// fd = open("mutiple_nl", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	// close(fd);

	// // Test archivo grande
	// printf("\n=== Test archivo grande ===\n");
	// fd = open("data", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	//     printf("%s", line);
	// close(fd);

	return (0);
}