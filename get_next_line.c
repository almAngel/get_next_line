/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:17:57 by angellop          #+#    #+#             */
/*   Updated: 2025/01/15 21:26:52 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_check_for_line_return_remainder(char *buff)
{
	char	*newline;

	newline = ft_strchr(buff, '\n');
	free(buff);
	if (newline)
		return (newline + 1);
	return (NULL);
}

char	*ft_cut_till_newline_including(char *buff)
{
	char	*nl;

	nl = ft_strchr(buff, '\n');
	if (nl)
		return (ft_substr(buff, 0, (nl - buff) + 1));
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*remainder;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0)
		return (NULL);
	line = "";
	bytes_read = 1;
	remainder = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = 0;
		remainder = ft_strjoin(remainder, buff);
		if (bytes_read == 0 && *remainder)
			return (remainder);
		if (ft_strchr(buff, '\n'))
		{
			line = ft_cut_till_newline_including(remainder);
			remainder = ft_check_for_line_return_remainder(remainder);
			return (line);
		}
	}
	free(remainder);
	remainder = NULL;
	return (NULL);
}

#include <fcntl.h>
int main(void)
{
	int fd;
	char *line;

	// // Test archivo normal
	// printf("\n=== Test archivo normal ===\n");
	// fd = open("normal.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	// close(fd);

	// // Test archivo vacío
	// printf("\n=== Test archivo vacío ===\n");
	// fd = open("empty.txt", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	//     printf("%s", line);
	// close(fd);

	// // Test archivo 1char
	// printf("\n=== Test archivo 1char ===\n");
	// fd = open("1char", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);	
	// }
	// close(fd);

	// Test archivo mutiple_nl
	printf("\n=== Test archivo mutiple_nl ===\n");
	fd = open("mutiple_nl", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);	
	}
	close(fd);

	// // Test archivo grande
	// printf("\n=== Test archivo grande ===\n");
	// fd = open("data", O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	//     printf("%s", line);
	// close(fd);

	return (0);
}