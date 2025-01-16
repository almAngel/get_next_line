/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:17:57 by angellop          #+#    #+#             */
/*   Updated: 2025/01/16 21:41:05 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_check_for_line_return_remainder(char *remaining)
{
	int		i;
	int		n;
	char	*new_save;

	i = 0;
	while (remaining[i] != '\0' && remaining[i] != '\n')
		i++;
	if (remaining[i] == '\0')
	{
		free(remaining);
		return (NULL);
	}
	new_save = ft_calloc(sizeof(char), (ft_strlen(remaining) - i + 1));
	i++;
	n = 0;
	while (remaining[i] != '\0')
		new_save[n++] = remaining[i++];
	free(remaining);
	return (new_save);
}

char	*ft_cut_till_newline_including(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	if (buff[i] == '\0')
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_safe_strjoin(char *remaining, char *buff)
{
	char	*new;

	new = ft_strjoin(remaining, buff);
	free(remaining);
	return (new);
}

char	*ft_mount_line(int fd, char *remaining)
{
	char	*buff;
	int		bytes_read;

	if (!remaining)
		remaining = ft_calloc(1, 1);
	bytes_read = 1;
	buff = ft_calloc(1, BUFFER_SIZE + 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(remaining);
			return (NULL);
		}
		buff[bytes_read] = 0;
		remaining = ft_safe_strjoin(remaining, buff);
		if (ft_strchr(remaining, '\n'))
			break ;
	}
	free(buff);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*remaining[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remaining[fd] = ft_mount_line(fd, remaining[fd]);
	if (!remaining[fd])
		return (NULL);
	line = ft_cut_till_newline_including(remaining[fd]);
	remaining[fd] = ft_check_for_line_return_remainder(remaining[fd]);
	return (line);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int fd;
// 	char *line;

// 	// // Test archivo normal
// 	// printf("\n=== Test archivo normal ===\n");
// 	// fd = open("normal.txt", O_RDONLY);
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// }
// 	// close(fd);

// 	// // Test archivo vacío
// 	// printf("\n=== Test archivo vacío ===\n");
// 	// fd = open("empty.txt", O_RDONLY);
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	//     printf("%s", line);
// 	// 	free(line);
// 	// }
// 	// close(fd);

// 	// Test archivo 1char
// 	printf("\n=== Test archivo 1char ===\n");
// 	fd = open("1char", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);

// 	// // Test archivo mutiple_nl
// 	// printf("\n=== Test archivo mutiple_nl ===\n");
// 	// fd = open("mutiple_nl", O_RDONLY);
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// }
// 	// close(fd);

// 	// // Test archivo grande
// 	// printf("\n=== Test archivo grande ===\n");
// 	// fd = open("data", O_RDONLY);
// 	// while ((line = get_next_line(fd)) != NULL)
// 	//     printf("%s", line);
// 	// close(fd);

// 	return (0);
// }