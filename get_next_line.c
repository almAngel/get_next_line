/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:17:57 by angellop          #+#    #+#             */
/*   Updated: 2025/01/10 16:49:27 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	storage[BUFFER_SIZE];
	char		*response;
	ssize_t		bytes_read;

	if (fd <= 0)
		return (NULL);
	while(bytes_read > 0)
	{
		bytes_read = read(fd, storage, BUFFER_SIZE);
		if (ft_strchr(storage, '\n'))
	}
	return ("");
}

char	*ft_read_until(char *left, char *right)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = right - left;
	res = ft_calloc(len, 1);
	while (i++ < len - 1)
		res[i] = left[i];
	return (res);
}

int main(void)
{
	#include "fcntl.h"
	int fd = open("data", O_RDONLY);

	get_next_line(fd);
}